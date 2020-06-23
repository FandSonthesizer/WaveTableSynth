// Ky-040 encoder
const int ky_clk  = PB14;   // Connected to CLK on KY-040
const int ky_dt   = PA12;   // Connected to DT on KY-040
//const int ky_sw   = PA15;   // Der Switch wird mit Pin D2 Verbunden. 



const uint16_t MAXPOT  = 7;
const uint16_t P_ATTACK  = 0;
const uint16_t P_DECAY  = 1;
const uint16_t P_SUSTAIN  = 2;
const uint16_t P_RELEASE  = 3;
const uint16_t P_REVDELAY  = 4;
const uint16_t P_REVAMOUNT  = 5;
//const uint16_t P_PWM  = 6;
const uint16_t P_MODUL  = 6;

const int AVERAGE =       16;     // For the gliding average method (LP filter for noisy analog values)

uint16_t pin[MAXPOT];             // Analog input pins
uint16_t mcount[MAXPOT]; // 
uint32_t avgsum[MAXPOT]; 
uint16_t Avalue[MAXPOT];  // 0-4096, analog in

// Encoder vars:
uint32_t TimeOfLastDebounce = 0;
uint16_t DelayofDebounce = 10;
int16_t encoderPosCount = 0; 
uint16_t dtVal_Old = 1;
boolean bCW;

//Switches & buttons
const int noOfButtons = 4;
const uint16_t ENCODERBT  = 0;
const uint16_t SHIFT  = 1;
const uint16_t SW1  = 2;
const uint16_t SW2  = 3;

typedef struct {
  int portPin;                 // Pin Nunber to read;
  uint16_t debounceDelay;      // debounceDelay = 50;    // the debounce time; increase if the output flickers
  uint16_t lastDebounceTime;   // lastDebounceTime = 0;  // the last time the output pin was toggled
  uint16_t lastButtonState;    // actual state
 } Button_type;
Button_type buttons[noOfButtons];

void initControls() {
  // define and init input pins:
  buttons[ENCODERBT].portPin  = PA15;
  buttons[SHIFT].portPin      = PB5;
  buttons[SW1].portPin        = PB6;
  buttons[SW2].portPin        = PB7;
  
  for(int n = 0; n < noOfButtons; n++) {
    buttons[n].debounceDelay = 100;
    buttons[n].lastDebounceTime = 0;
    buttons[n].lastButtonState = 1;             // not pressed
    pinMode(buttons[n].portPin, INPUT_PULLUP);
  }
  // Define the analog input pins: 
  pin[P_ATTACK] = PA0;
  pin[P_DECAY] = PA1;
  pin[P_SUSTAIN] = PA2;
  pin[P_RELEASE] = PA3; //pa3
  
  pin[P_REVDELAY] = PA6;
  pin[P_REVAMOUNT] = PA7; // mix

  pin[P_MODUL] = PA4; // generic 1 fm modulator

  for (int n = 0; n < MAXPOT; n++) {
     mcount[n] = 0;
     avgsum[n] = 0;
     Avalue[n] = 0;
     pinMode(pin[n], INPUT_ANALOG);
  }
}

/**
 * Gliding Average value.
 * This method simulates a capacitor to even out the noisyness of the stm32's adc.
 * @param newval the ne value, read from adc
 * @param potCh which channel to read
 */
uint32 glidingAverage(uint16 newval, uint16 potCh) {
   uint32 average = 0; 
   if (mcount[potCh] < AVERAGE) { // initial loading of the capacitor
      avgsum[potCh] += newval;
      average = avgsum[potCh] / mcount[potCh];
      mcount[potCh]++;
   }
   else {
    // now hold and change the charge
      avgsum[potCh] -= avgsum[potCh] / AVERAGE;
      avgsum[potCh] += newval;
      average = avgsum[potCh] / AVERAGE;
   }
   return average;
}

/**
 * read an analog channel. Store value in Avalue[potCh]
 * @param potCh the analoge channel to read
 * @return true if the value was changed
 */
bool updateAnalogChannel(uint16 potCh) {
   // Read the Potentiometer value 
   bool c = false;
   /*Serial.print("Channel=");
   Serial.print(potCh);
   */
   int Nscale = adc_read(ADC2, pin[potCh]);       // ADC2 read noisy voltage value from pot.
   //Serial.print(" Nscale=");
  // Serial.print(Nscale);
   uint32 m = glidingAverage(  Nscale, potCh );   // Add the new adc value into a gliding average value
   //Serial.print(" GAverage=");
  // Serial.print(m);
   uint32 d = abs(m - Avalue[potCh]);
   //Serial.print(" diff=");
   //Serial.println(d);
   if (d > 5) {
      Avalue[potCh] = m;
      c = true;
   }
   return c;
}
// ----------- switches amd buttons: -------------------------
/**
 * @param btn number of the button/switch
 * @return true if changed
 */
boolean readInputPin(uint32_t mil, int btn) {
  // Reset Button:
    bool res = false;
    uint16_t bt = digitalRead(buttons[btn].portPin); // 0=clear, 1 = neutral
   // Serial.println(bt);
    uint32_t diff = mil - buttons[btn].lastDebounceTime;
    //  Serial.println(diff);
    if (buttons[btn].lastButtonState != bt && diff > buttons[btn].debounceDelay ) {
      if (bt == LOW) {
        // pressed
          buttons[btn].lastDebounceTime = mil;
        }
    }
    res = buttons[btn].lastButtonState != bt;
    buttons[btn].lastButtonState = bt; // here we save the actual button state
   /*if (bt == 0)
      Serial.println("Shift pressed");
      */
    return res;
}

bool readEncoder(uint32_t mil) {
  int inc = 1;
  int dtVal = digitalRead(ky_dt);
  bool change = false;
  unsigned long diff = mil - TimeOfLastDebounce;
  if (dtVal != dtVal_Old && diff > 10 && dtVal == 0) {
    // falling flank on dt !
    bCW = digitalRead(ky_clk) == 1;
    (bCW)?encoderPosCount +=inc: encoderPosCount -=inc;
      TimeOfLastDebounce = mil; 
      change = true;
  }
  dtVal_Old = dtVal;
  return change;
}





