/**
 * Father & Sonthesizer (c) 2019
 * Wavetable Synthesizer V1.1
 * 
 * ToDO: keytracking, Effects
 * 
 *
 */
#include "NiksMidi.h"
#include "Voice.h" 
#include "Controls.h"
#include "Reverb.h" 
#include "Tune.h"
#include "EEPROM.h"

//--- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ---------------
// #define USE_BOOTLOADER   // uncomment this, when using the stm32 bootloader, or else no Midi is possible

// #define USE_ATAN_MIX   //  Audio mixer methods, use just one!
#define USE_CLIP_MIX   //    

# if defined USE_ATAN_MIX   
  #include "Atan.h"  
#endif   
//----------- Pins ---------------
#define PWM_OUT       PA8    // PA8 PWM output pin, Audio out
#define PWM_OUT2      PA11    // PWM output pin, ADSR out
#define ONBOARDLED    PC13   //  
#define scalePin      PA2 //PA2    // freq tuning

int ypos = 18;
int zero = 0;

//---------Some debug values ----------------------
const bool doMidi = true;           // if true, the synth listens to midi in
const bool debug = false;           // If true, play a small melody as a test
const bool trigger = true;           // If true, use the encoder push button to trigger one midi note

const bool doReverbF = false;      // if true, actually use the build in reverb filter 
const bool doFilterADSR = true;    // if true, also generate the filter ad signal for external analog filter
const bool doADSR = true;          // if true, apply an ADSR to each midi note
const bool doScope = true;         // if true, show the actual playing waveform on the display 
//
const bool debugVoice = false;      // if true, the loop will calculate the voice engine. (Used for debugging)
const bool testRev = false;        // If true, just do a test of the reverb filter. (Used onyl for debugging)
const bool Align = false;          // if true  run max-output on pwm1 and pwm 2. use to align trimmer pots for output volume
//---
const uint16_t isr_cnt =  40;     // interrupt rate 25us = 40000
const uint16_t pwm_cnt =  20;     // pwm frew @ 50kHz , 10us=max ampl. 720 20us=max ampl. 1440

//MIDI_CREATE_DEFAULT_INSTANCE();
//using namespace midi;
//MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI); 

const boolean LISTENTOALLCHANNELS = false;

//------------ Vars --------------
uint32_t mil = 0;               // millisec. tic, this replace the call: millis()
uint32_t globalTic = 0;           
//uint32_t potDebounce = 0;
int waveFormD[128];

bool start = true;                  // true, while we are in  start-mode
uint16_t testrun = 0;
bool testRuns = false;
bool play = debug;

String tmp = "";
uint32_t avgsumv = 0;     // experimantal lp filter on synth out, not used!
uint16_t mcountv = 0;
int16_t AVERAGEV = 64;

const int EEP_CHANNEL = 0;
const int WAVE_CHANNEL = 1;
const int DATTACK_CHANNEL = 2;
const int DDECAY_CHANNEL = 3;
const int PWM_CHANNEL = 4;
const int VSTART = 5;
const int VEND = 6;
const int FM_DECAY = 7;

int midiChannel = EEPROM.read(EEP_CHANNEL);        // Midi channel

// Tune, used to play a little tune, mostly needed for debugging
uint32_t tuneStart = 0;
int tuneIndex;
bool tunePlaying = false;
bool startTune = debug;
int tcnt;

/**
 * Debug voice
 */
bool startDebugVoice = debugVoice;
bool voiceDebugging = false;

// Vars for oszilloscope display:
int16_t vres = 0;
uint16_t dispIdx = 0, refreh = 0, anz = 0;
uint16_t tbase = 1; //
uint16_t tbaseidx = 0;
uint16_t DisplayScale = 4000;

//Analog input
uint16_t aChannel = 0;
uint16_t aDelayIDX = 0;
const uint16_t ADELAY = 50;

bool tstate = false;


byte sNo = 1;
//byte channel = EEPROM.read(WAVE_CHANNEL);        // Midi channel


/**
 * Setup routine, this is the first to be called on startup of the stm32
 */
void setup() {
  // 1st Initialize the programm
  sNo =  EEPROM.read(WAVE_CHANNEL); // 0=saw, 1=sin,2=tri, 3=sqr, 4=FM
  //sNo = 4; // saw debug
  if (sNo < 0 || sNo > 4) {
    sNo = 1;
     EEPROM.write(WAVE_CHANNEL, sNo);
  }
  fat =  EEPROM.read(DATTACK_CHANNEL); 
  fde =  EEPROM.read(DDECAY_CHANNEL);

  pwm_value = EEPROM.read(PWM_CHANNEL);
  if (pwm_value < 10 || pwm_value > 1020) {
    pwm_value = 512;
    EEPROM.write(PWM_CHANNEL, pwm_value);
  }
  pw = pwm_value;

  v_start =  EEPROM.read(VSTART);   
  if (v_start < 0 || v_start > 4096) {
       v_start = 256;
       EEPROM.write(VSTART, v_start);
  }
  v_end =  EEPROM.read(VEND);   
  if (v_end < 0 || v_end > 4096) {
       v_end = 64;
       EEPROM.write(VEND, v_end);
  }
  fm_decay =  EEPROM.read(FM_DECAY);   
  if (fm_decay < 0 || fm_decay > 4096) {
       fm_decay = 1023;
       EEPROM.write(FM_DECAY, fm_decay);
  }
  
  initControls();
  initVoices(doMidi);
  initGraphic();
  setAdsrVals(); // some values to beginn with. Maybe read from EEprom ?
  initRev(); // inít reverb filter
  requestToUpdate = true; // inital draw of the display
  if (midiChannel > 15) {
    midiChannel = 1;
    EEPROM.write(EEP_CHANNEL, midiChannel);
  }
  
  pinMode(ONBOARDLED, OUTPUT); // on - board led etc
  pinMode(scalePin, INPUT_ANALOG);
  /* Initialization of midi input and serial for debug*/
 /* if (doMidi) {
    MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function
    MIDI.setHandleNoteOff(handleNoteOff);  // Put only the name of the function
  }
  */
  if (doMidi){
    
    # if defined USE_BOOTLOADER   
      Serial1.begin(31250);//31250
    #elif !defined USE_BOOTLOADER
      //HardwareSerial Serial2(PA3, PA2);   // or HardWareSerial Serial2 (PA3, PA2);
      Serial.begin(31250);   //31250 
    #endif   
    
  }
 else 
    Serial.begin(115200);
    // init oled display 
    display.begin(SSD1306_SWITCHCAPVCC);
    display.display();
    // Clear the buffer.
    display.clearDisplay();
  
    # if !defined USE_BOOTLOADER  
      while (!Serial) { // this does not seem to work on my blue-pill, Serial is always true...
        delay(10);      // and with the boot-loader the pill stm never leaves this loop!
     }
    #endif
  
  /**
  * Pwm Set for analog out: 50kHz, 0-1420
 */
  HardwareTimer timer1 = HardwareTimer(1);  // using timer 1, can be 2,3,4...
  timer1.setPrescaleFactor(1);              // Pre-scale factor 1-65536
  timer1.setPeriod(pwm_cnt); //0-1420 @ 50kHz    // microseconds uSec 
  pinMode(PWM_OUT, PWM);      // synthesizer analog output

/**
  * Pwm Set for analog out: 50kHz, 0-1420
 */
  HardwareTimer timer3 = HardwareTimer(3);  // using timer 1, can be 2,3,4...
  timer3.setPrescaleFactor(1);              // Pre-scale factor 1-65536
  timer3.setPeriod(pwm_cnt); //0-1420 @ 50kHz    // microseconds uSec 
  pinMode(PWM_OUT2, PWM);   // Filter AD output

  /** 
   *  Setup Timer 2 to 25u (40000 per second)
   */
  Timer2.setMode(TIMER_CH1, TIMER_OUTPUTCOMPARE);
  Timer2.setPeriod(isr_cnt);                          // in microseconds (25u)
  Timer2.setCompare(TIMER_CH1, 1);                   
  if (!testRev && !debugVoice) 
    Timer2.attachInterrupt(TIMER_CH1, handler_Synth);   // in this routine the synth moves through the wave-table

  /**
   * Really only used when I developed this effect...
   */
  if (testRev) {
      // init the reverb-filter
      Serial.println("Start Rev test");
      setDelayTime(100); // [0-4096] = 0-120ms
      // Fill buffer with a small ramp
      for (int n = 0; n < 50; n++)
        writeHead(n);
      //delay(1000);
  }
  
  //---
  selectWave(sNo); // 1 = sin
  //displayPage0(midiChannel, sNo); // start screen
  
 // dispChannel(midiChannel, 0);
 // sei(); //Enable interrupt
 
  digitalWrite(ONBOARDLED, 1); // turn LED off
  delay(200);
}



void loop() {
  readMIDI();   // my own, very basic, midi in Method
  //MIDI.read();

  /**
   * Only on start-up 
   */
  if (mil > 1000 && start) {
    if (!doMidi)
      Serial.println("Wavetable Synth v1.0");
    setAdsrVals();
    /**
     * output full amplitude to align the low pass filter gain
     */
    if (Align) {
      Serial.println("Start Alignment");
      pwmWrite(PWM_OUT, 1420);
      pwmWrite(PWM_OUT2, 1420);
    }
    /*Serial.print("fat=");
    Serial.print(fat);
    Serial.print(" fde=");
    Serial.println(fde);
    */
    start = false;
    testrun = 0;
  }

/**
 * Start method, Just for debugging a voice
 */
  if (startDebugVoice) {
      startDebugVoice = false;
      Serial.println("Start debug Voice");
      setAdsrVals();
      tuneStart = 0; // time-stamp
      dispIdx = 0;
      handleNoteOn(1, 65, 127); // just start one note, not using the interrupt routine. (Just for debugging)
      display.clearDisplay();
      voiceDebugging = true;
  }
   
   updateDisplay();
   
//----
/**
 * True, if a voice is being debugged
 */
  if (voiceDebugging) { // to debug the synth voice engine, no interrupt used
    doVoice();
    tuneStart++;
    if (vAdsr[0].ADSR_mode == STOPPING) {
      voiceDebugging = false; // stop
    }
    else if (tuneStart > 40000) {
      handleNoteOff(1, 38, 0); 
    }
  }
  else if (testRev) {
    doReverb();   // test the reverb filter, no interrupt used. (so we can print debug info)
  }
  else if (startTune) { // if request to play
    startTune = false;
    startPlayTune(); // reset Index and start first note
  }
  
  if(tunePlaying) {
    playTune();
  }
  
  // -------- release notes in end of release state for re-use ------
  /**
   * If a voice is in finished release state mode (STOPPING), just clean it up here.
   * If we would do this in the interrupt routine, unexpected things might happen! :-)
   */
  for (int n=0; n < MAXVOICE; n++) {
   if (vAdsr[n].ADSR_mode == STOPPING) {
    int nt = voice[n].note;
    voice[n].note = 0;
    vAdsr[n].ADSR_mode = STOP;
   /* Serial.print(n);
    Serial.print(" CTRL Loop Free Note");      
    Serial.print(nt);
    Serial.print(" @");      
    Serial.print(n);
    */
   }
  }
  
  /**
   * Here now we read the periphal adjustment components, 
   *  like potentiometers etc.
   */
   //int Nscale = adc_read(ADC2, PA0);       // ADC2 read noisy voltage value from pot.
   /*Serial.print("Attack=");
   Serial.println(Nscale);
   */
   aDelayIDX++;
   if (aDelayIDX > ADELAY) {
     aDelayIDX = 0;
     readAnalogChannel(aChannel);
     aChannel++;
     if (aChannel >= MAXPOT)
       aChannel = 0;
   }
   actOnEncoder(mil);

  if (trigger) {
    if (readInputPin(mil, ENCODERBT)) {
      // button state has changed
      if (buttons[ENCODERBT].lastButtonState == 0) {
        // pressed
        //Serial.println("Button Pressed");
        if (page == DATTACK || page == DDECAY) {
          if (page == DATTACK )
            page = DDECAY;
          else
            page = DATTACK;  
          requestToUpdate = true;
        }
        else 
          handleNoteOn(1, 62, 127); 
      }
      else {
        //Serial.println("Button Released");
        if (page != DATTACK && page != DDECAY) {
          handleNoteOff(1, 62, 0);
        }
      } 
    }
  }
}

void readAnalogChannel(int n) {
  if (start)
    return; // not in start mode...
  
   bool change = updateAnalogChannel(n);
   if (change) { 
      if (n == P_ATTACK){
        setAttackScale(Avalue[n], VOICES);
        setAtValue(Avalue[n]); // for the graphic 
       // Serial.print("Attack=");
       // Serial.println(Avalue[n]);
      }
      else if (n == P_DECAY){
        setDecayScale(Avalue[n], VOICES);
        setDeValue(Avalue[n]);
      }
      else if (n == P_SUSTAIN){
        setSustainValue(Avalue[n], VOICES);
        setSusValue(Avalue[n]);
      }
      else if (n == P_RELEASE){
        //Serial.print("Release=");
       // Serial.println(Avalue[n]);
        setReleaseScale(Avalue[n], VOICES);
        setReValue(Avalue[n]);
      }
      else if (n == P_REVDELAY){
        setDelayTime(Avalue[n]); // 0-250ms
      }
      /*else if (n == P_PWM){
        pwm_CValue = Avalue[n] >> 2;  // : 4, analog = 0-4095 to 0-1023 PWM Value
        //setReleaseScale(Avalue[n], VOICES);
      }
      */
       else if (n == P_MODUL){
        setFMModulator(Avalue[n]); // 0-2048
      }
      
     // page = 1; // if button is pressed?
     // drawADSR();
    }
}


void actOnEncoder(uint32_t mil) {
  
  if(readEncoder(mil)) {
    // encoder pos was changed
    /*Serial.print("Encoder=");
    Serial.print(encoderPosCount);
    Serial.print(" direction=");
    Serial.println(bCW);
    */
    readInputPin(mil, SHIFT);
    if (buttons[SHIFT].lastButtonState == 0) { 
      // shift is pressed, we are in page select mode
      // change menu tab
      if (bCW) {
        page++;
        if (page > PAGEMAX)
          page = PAGEMAX;
      }
      else {
        page--;
        if (page < 0)
          page = 0;
      }
      if (page == SCOPE)
        display.clearDisplay();
      requestToUpdate = true;
    }
    else {
      // we are in value-select mode
      if (page == WAVESEL) {
        // select a new waveform!
        if (bCW) {
          sNo++;
          if (sNo > WMAX)
            sNo = WMAX -1;
        }
        else {
          sNo--;
          if (sNo < 0)
            sNo = 0;
        }
        Serial.print("Waveform=");
        Serial.println(sNo);
        EEPROM.write(WAVE_CHANNEL, sNo);
        selectWave(sNo);
      }
      else if (page == BASE) {
        if (bCW) {
          midiChannel ++;
          if (midiChannel > 15)
            midiChannel = 15;
        }
        else {
          midiChannel--;
          if (midiChannel < 1)
            midiChannel =1;
        }
         EEPROM.write(EEP_CHANNEL, midiChannel);
      }
      else if (page == DATTACK) {
        if (bCW) {
          fat += 200;
          if (fat > 4095)
            fat = 4095;
        }
        else {
          fat -= 200;
          if (fat < 10)
            fat =10;
        }
        setAttackScale(fat, FILTER);
        EEPROM.write(DATTACK_CHANNEL, fat);
      }
      else if (page == DDECAY) {
        if (bCW) {
          fde += 200;
          if (fde > 4095)
            fde = 4095;
        }
        else {
          fde -= 200;
          if (fde < 10)
            fde = 10;
        }
        setDecayScale(fde, FILTER);
        EEPROM.write(DDECAY_CHANNEL, fde);
      }
      else if (page == DPWM) {
        if (bCW) {
          pwm_value += 50;
          if (pwm_value > 1020)
            pwm_value = 1020;
        }
        else {
          pwm_value -= 50;
          if (pwm_value < 10)
            pwm_value = 10;
        }
        pw = pwm_value;
        EEPROM.write(PWM_CHANNEL, pwm_value);
      }
      else if (page == FMSTART) {
        if (bCW) {
          v_start += 10;
          if (v_start > 2048)
            v_start = 2048;
        }
        else {
          v_start -= 10;
          if (v_start < 10)
            v_start = 10;
        }
        //pw = pwm_value;
        EEPROM.write(VSTART, v_start);
      }
      else if (page == FMEND) {
        if (bCW) {
          v_end += 10;
          if (v_end > 2048)
            v_end = 2048;
        }
        else {
          v_end -= 10;
          if (v_end < 10)
            v_end = 10;
        }
        //pw = pwm_value;
        EEPROM.write(VEND, v_end);
      }
      else if (page == FMDECAY) {
        if (bCW) {
          fm_decay += 20;
          if (fm_decay > 2048)
            fm_decay = 2048;
        }
        else {
          fm_decay -= 20;
          if (fm_decay < 10)
            fm_decay = 10;
        }
        //pw = pwm_value;
        EEPROM.write(FM_DECAY, fm_decay);
      }
      requestToUpdate = true;
    }
  }
}
/**
 * Init ADSR default values to default values, maybe from eeprom?
 */
void setAdsrVals() {
  //Serial.println("Set ADSR values");
    setDelayTime(4000); // 
    Avalue[P_REVAMOUNT] = 4000;
    setAttackScale(20, VOICES);
    setAtValue(20);
    setDecayScale(600, VOICES);
    setDeValue(600);
    setSustainValue(2048, VOICES);
    setSusValue(2048);
    setReleaseScale(200, VOICES);
    setReValue(200);

    // AD Filter setting
    setAttackScale(fat, FILTER);
    setFAtValue(fat);
    setDecayScale(fde, FILTER);
    setFDeValue(fde);
    /*setAttackScale(400, FILTER);
    setFAtValue(400);
    setDecayScale(600, FILTER);
    setFDeValue(600);
    */
    setSustainValue(0, FILTER); // not used
    setReleaseScale(100, FILTER);// not used
}

/**
 * Set reverb amount mix value
 * @param a value of the mix pot [0-4095]
 */
void setRevAmount(uint16_t a) {
  // To be done
}

//------------------------------------------------------------------------------------------

/**
 * Interrupt routine, triggered every 25us (40Khz)
 * In this routine, we travel along the wavetable and output the amplitude values we find.
 */
 void handler_Synth(void) {
  globalTic++;            // count up all the time at 40khz
  if (globalTic > 39) {
    globalTic = 0;        // 40 tics at 40 khz is one millisec.
    mil++;                // increase millisecond tic, used for button debounce etc.
  }
  doVoice();              // the actual sound generation
 }




/**
 * Just for debugging, not used in synth!
 */
 void doReverb() {
  // Reverb: ---------- make echo switchable? Or just set 0
    if (delayTime > 0 && diff == 0) {
      uint16_t rv = readRev(); // echo value
      Serial.print("readPointer=");
      Serial.print(readPointer);
      Serial.print(" v=");
      Serial.print(rv);
      Serial.print(" writePointer=");
      Serial.println(writePointer);
    }
    else if (diff > 0) {
      Serial.print("Buffering diff=");
      Serial.print(diff);
      Serial.print(" writePointer=");
      Serial.println(writePointer);
    }
      
    writeHead(1); // write empty 
 }

//-------------------------------

 void handleAllNoteOff() {
   for (int n=0; n < MAXVOICE; n++) {
     if(voice[n].note > 0){
         setGateOff(n); // change adsr state
     }
   }
 }
  
/**
 * Command received from Midi, stop a voice
 * velocity ignored for the moment...
 */
 void handleNoteOff(byte inChannel, byte inNote, byte inVelocity) {
  //dispNoteOff(inNote, 0);
  if (midiChannel == inChannel || LISTENTOALLCHANNELS) { // all notes
     // Midi Off
       int slot = findOldestMidiNote(inNote);
       if (slot < 0) {
       // Serial.print("Error for note ");
       // Serial.println(inNote);
        return;
       }
       if (!doMidi) { 
        Serial.print(slot);
        Serial.print(" -Off ");
        Serial.print(inNote);
        Serial.print(" @");
        Serial.print(voice[slot].activationTime);
        Serial.print(" Now:");
        Serial.println(mil);
       }
       setGateOff(slot); // change adsr state
       /*if (!doScope) {
          dispNoteOff(inNote, slot);
       }
       */
    }
    
 }

/**
 * A note on signal was read either from MIDI or from the tune-player
 */
void handleNoteOn(byte inChannel, byte inNote, byte inVelocity) {
    //dispNoteOn(inNote, 0);
    //Serial.print("handleNoteOn nt=");
    //Serial.println(inNote);

    /**
     * Repect the Midi channel ?
     */
    
    if (midiChannel == inChannel || LISTENTOALLCHANNELS) {
      int slot = -1;
      for (int n=0; n < MAXVOICE; n++) {
         if(voice[n].note == 0){
             slot = n;
             break;
         }
      }
      if (slot < 0) {
         // no voice found to use!
         //Serial.println("On: No empty slot found!");
         int oldestSlot = -1;
         // find the oldest note
         uint32_t maxT = 0xffffffff;
         uint32_t maxRT = 0xffffffff;
         for (int n=0; n < MAXVOICE; n++) {
           if (voice[n].activationTime < maxRT &&  vAdsr[slot].ADSR_mode == RELEASE) {
             maxRT =  voice[n].activationTime;
             slot = n; // oldest slot already in Release state
           }
           else if (voice[n].activationTime < maxT) {
             maxT = voice[n].activationTime;
             oldestSlot = n; // oldest note
            // Serial.print("On: actual oldest ");
             //Serial.println(slot);
           }
         }
         // now use the oldest release slot or the oldest slot
         if (slot < 0)
            slot = oldestSlot;
      } 
      vAdsr[slot].ADSR_mode = STOP;
      voice[slot].activationTime = mil;
      
      if (!doMidi) {
          Serial.print(slot);
          Serial.print(" +On ");
          Serial.print(inNote);
          Serial.print(" @");
          Serial.println(voice[slot].activationTime);
      }
      // now trigger the new voice
    
      uint16_t f = getFreq(inNote); // determine freq. from midi note
      if (waveForm != FM)
          setVoiceFreqency(f, slot, mil); // set the step value for the isr
      else
          setFMFrequencys(f, slot, mil);
      voice[slot].note = inNote;
      setGateOn(slot); // start adsr, gate on setGateOn(channel); // start adsr, gate on
      /*if (!doScope) {
        dispNoteOn(inNote, slot);
      }
      */
   }
}

void  print(String s, int val) {
  Serial.print(s);
  Serial.println(val);
}
// -------------------

/**
 * Find an active playing midi note in the voices array
 * @param note the note to look for
 * @return the voice-index or -1 if not found
 */
int16_t findOldestMidiNote(uint16_t note) { 
 // Serial.print("Find oldest Note to turn off n=");
 // Serial.print(note);
  
  int16_t slot = -1;
  uint32_t oldestTime = 0xffffffff; // highest 32 bit number
  for (int16_t n = 0; n < MAXVOICE; n++) {
      if (voice[n].note == note) {
        if (vAdsr[n].ADSR_mode > STOP &&  vAdsr[n].ADSR_mode < RELEASE ) {
          if (voice[n].activationTime < oldestTime) {
            slot = n;
            oldestTime = voice[n].activationTime;
          }
        }
      }
   }
  // Serial.print(" Resulting slot=");
  // Serial.println(slot);
  return slot; 
}
//----------------------------------------


  //--------------
 

/**
 * Gliding Average value.
 * This method simulates a capacitor to even out the noisyness of the stm32's adc.
 * @param newval the new value, read from adc
 * @return the actual average value
 */
uint16 glidingAverageVoice(uint16 newval) {
   uint16 average = 0; 
   if (mcountv < AVERAGEV) { // initial loading of the capacitor
      avgsumv += newval;
      average = avgsumv / mcountv;
      mcountv++;
   }
   else {
    // now hold and change the charge
      avgsumv -= avgsumv / AVERAGEV;
      avgsumv += newval;
      average = avgsumv / AVERAGEV;
   }
   return average;
}



//------------------- methods of the tune-player -------
// very important: the tune-entrys need to be ordered by increasing time-stamps
// ( No time travel please, the doctor is just not in right now :-) )
/**
  * Start to play a tune
  */
 void startPlayTune() {
  tuneStart = mil;       // when this tune starts to play
  tuneIndex = 0;
  tunePlaying = true;
  Serial.println("Start to play a tune.");
  //Serial.print("Serial 1=");
  //Serial.println(USE_SERIAL_1);
  tcnt = 0;
 }
 
/**
 * Time based, start or stop (multiple) notes
 */
 void playTune() {
    long millis = mil - tuneStart;
    
    if (millis >= tune[tuneIndex].startTime) {
      // time trigger
      if (tune[tuneIndex].on) {
       /* Serial.print("Tune on ");
        Serial.println(mil);
        */
        handleNoteOn(midiChannel, tune[tuneIndex].note, tune[tuneIndex].velocity);
        tcnt++;
      }
      else {
        // note off trigger
       /* Serial.print("Tune off ");
        Serial.println(mil);
        */
        handleNoteOff(midiChannel, tune[tuneIndex].note, tune[tuneIndex].velocity);
        tcnt--;
      }
      tuneIndex++;
    }
    if (tuneIndex >= tmax) {// 32 tmax
      Serial.print("Active left="); // used to check if any voice are 'hanging'
      Serial.println(tcnt);
      tunePlaying = false;
    }
 }

 /**
 * Here we create the actual sound
 * This method is called 40.000 time per second in the interrupt routine!
 */
void doVoice() {
    // Increment envelopes and oszillators
    for (uint16_t n = 0; n < MAXVOICE; n++) {
        if ( vAdsr[n].ADSR_mode != STOP && vAdsr[n].ADSR_mode != STOPPING) {
        
          if (waveForm == FM ) {
           // addFMStep(n);
            int16_t e3 = 0;
            voice[n].tableIndexEnv3 += voice[n].envStep3;
            if (voice[n].tableIndexEnv3 < VirtualTableIndexMax) { 
               int16_t t_idx = (uint16_t) ( voice[n].tableIndexEnv3 >> precisionShift); 
               e3 = getDecay(t_idx); //envelope 1 (0-4095)
               uint16_t envE3 = (e3 * voice[n].volDiff) >> 12;
               voice[n].fmVol = v_end + envE3;
            }
          //--------------------------------------------------
            voice[n].tableIndex += voice[n].step;
            voice[n].tableIndex =  voice[n].tableIndex &  0x7fffff;
            voice[n].modTableIndex += voice[n].modulatorStep;
            voice[n].modTableIndex =  voice[n].modTableIndex &  0x7fffff;
            uint16_t fmidx = voice[n].modTableIndex >> precisionShift; 
            int16_t modSin = getSinInt(fmidx); // modulator freq +- 127
            // modulator envelope:
            int32_t envModSin = divider2 * modSin * voice[n].fmVol; // ScaleV * 
            envModSin = envModSin >> 1;
            envModSin = envModSin % 0x7fffff;
            uint64_t addedPhase = voice[n].tableIndex + envModSin;
            addedPhase = addedPhase & 0x7fffff;
            uint16_t bidx = addedPhase >> precisionShift;
            int16_t v = getSinInt(bidx); // 
            voice[n].vOutput = v;
          }
          else {
            // Classic wavetable:
           // addStep(n);                 // Audio value, all voices+
           voice[n].tableIndex += voice[n].step;     // step through the wavetable, the larger the step value, the higher the frequency
           int c = 0;
            // here access the tables, divide tableIndex by 256
           uint32_t tIdx = voice[n].tableIndex >> 8;      // remember: the tableIndex was multiplied by 256, so here we divide
           tIdx = tIdx & 0x7ff; // 2048
   
           // find out which table to use:
           if(waveForm == 0)
             c = getSawInt(tIdx);
           else if(waveForm == 1)
             c = getSinInt(tIdx);  
           else if(waveForm == 2)
             c = getTriInt(tIdx); 
           else if(waveForm == 3) {// square, use pwm value!
              int pv = pwm_CValue + pwm_value; 
              if (pv > 1020)
                pv = 1020;
              c = (tIdx < pv)?-2047:2047; 
           }
           voice[n].vOutput = c; //  +- 2047
          }
          addADSRStep(n, VOICES);     // 0-4096  all adsr ???
        }
    }
    // Analog Filter (LPF) AD:
    if (vAdsr[MAXVOICE].ADSR_mode != STOP && doFilterADSR) // disable filter adsr
      addADSRStep(MAXVOICE, FILTER);
      
    //-------------- Audio Mixer -----------------
    int32_t sum = 0;      
    anz = 0;
    for (int16_t n = 0; n < MAXVOICE; n++) {
     if (vAdsr[n].ADSR_mode != STOP) {
         // just examine active voices
         // active voice!
         int16_t v = voice[n].vOutput;   // +-2047 as amplitude
         uint16_t env = vAdsr[n].output; // envelope amplitude, 0-4095
         // --- Envelope VCA: ----
         int16_t act = env * v / LogLength;    // Loglength = 4096, act = [+-2047]
         sum = sum + (act >> 1);  // add only 50%  = +-1024
         
        //Serial.print(" added sum=");
        //Serial.print(sum);
         anz++;   
      } 
    }
    
    //----------  Reverb Filter: recover values from the rev-buffer
    if (doReverbF && delayTime > 0 && !changes && diff == 0) {
      // blow up to original volume (*2)
      int8_t reverb = readRev() << 2; // echo value [+-127], since the echo buffer is only 8bit
      // reduce rev amplitude, by using the mixer value [0-4095]
      int32_t rv = (reverb * Avalue[P_REVAMOUNT]) >> 12; // : 4096; reduce echo amplitude by mixer value 4096=2^12, 
      if (rv != 0) { // if we have a pending echo
        
        // test echo value with scope:
       //pwmWrite(PWM_OUT, pwmVolume2+rv); // test output to 2nd analog out, just the reverb signal...
        //---
        sum += rv; // add to actual value, treat like another voice that got active
        anz++ ;
      }
    }
    
    //------------Output Filter adsr @ pwm2-----------
    if (doFilterADSR) {
      if ( vAdsr[MAXVOICE].ADSR_mode != STOPPING) {
         uint16_t env = vAdsr[MAXVOICE].output; // envelope amplitude, 0-4095
         uint16_t act = env >> 2;    // Loglength = 4096, act = [0-1024]
         pwmWrite(PWM_OUT2, act & 0x3fff);     
      } 
    }
    
    //----------------- Synth Audio Mixer  --------------------
    if (anz > 0){
      sum = sum >> 1; // divide by 4
      
     # if defined USE_CLIP_MIX   
      if (sum > pwmVolume2)
        sum = pwmVolume2;
      if (sum < -pwmVolume2)
        sum = -pwmVolume2;
     #endif  
      //Serial.print(" clipped sum=");
      //Serial.print(sum);
     /* //--- 3. use Atan to do the cliping ---------
      # if defined USE_ATAN_MIX   
        uint16_t tv = 0; 
        sum >>= 1;
         if (sum > 709)
          tv = 1420;
        else 
          tv = getATan(sum);
      //uint16_t res = (tv * 1420) >> 8;
        res = tv;
      #endif
      */
      //--- feed the delay buffer ----
      if (doReverbF && !changes) {
          int8_t rv = (int8_t) ((sum * 255) / pwmVolume2);
          writeHead(rv); //scale to 8bit, since our memory buffer only has 8 bit resolution
         // pwmWrite(PWM_OUT, pwmVolume2+rv);
      }
          
      // until here, all signals are +- values, so now add half amplitude to get positive values only:
      sum = pwmVolume2 + sum;
    
      pwmWrite(PWM_OUT, sum); // res
      vres = sum; // & 0x3fff;
      digitalWrite(PC13, 0); // turn on, voice is active
    }
    else {
      // No voice active, feed the delay buffer with empty values
      if (doReverbF)
        writeHead(0);
      //
      pwmWrite(PWM_OUT, pwmVolume2); 
      vres = pwmVolume2;
      digitalWrite(PC13, 1);
    }
  }

  /**
   * Update the display
   */
  void updateDisplay() {
   switch (page) {
    case BASE: // first page, shown on start-up
      if (requestToUpdate) {
        displayPage0(midiChannel, sNo);
      }
    break;
    case ADSRP:
      if (requestToUpdate) {
        drawADSR();
      }
      break;
    case SCOPE:
        /**
         * The dispaly refresh is not done every cycle...
         */
        refreh++;  
        if (refreh > 200) { 
          refreh = 0;
          requestToUpdate = true;
        } 
        tbaseidx++;
        if (tbaseidx > tbase) {
          dispIdx++; // 
          tbaseidx = 0;
        }
        dispCurve(vres, dispIdx, DisplayScale); // DisplayScale is what we scale the 128 hor. pixels to
        /**
         * if the end of the display is reached, clear the screen and start again
        */
        if (dispIdx > DisplayScale) {
         display.clearDisplay();
         dispIdx = 0;
         opx = 0;
        }
      break;
      case WAVESEL:
        if (requestToUpdate) {
          if (sNo == SAW)
           getSawWave(); // set the waveForm array
          else if (sNo == SIN) 
           getSinWave();
          else if (sNo == TRI) 
           getTriWave();
          /*else if (sNo == SQR) 
           getSQRWave();
           */
          drawWaveForm(sNo);
          if (sNo > SAW) 
              drawLeftArrow();
          if (sNo < (WMAX-1))
              drawRightArrow();
        }
      break;
   /*   case MIDISNIF:
          refreh++;  
          if (refreh > 1000) { 
            refreh = 0;
            requestToUpdate = true;
          } 
      break;
      */
      case DATTACK:
          if (requestToUpdate)
            drawAD(0);
          break;  
      case DDECAY:
        if (requestToUpdate)
            drawAD(1);
        break;
      case DPWM :
        drawPWM();
        break;
      
      case FMSTART :
        drawFMStart(v_start);
        break;
      case FMEND :
        drawFMEnd(v_end);
        break; 
      case FMDECAY :
        drawFMDecay(fm_decay);
        break;
  }
  
  if (requestToUpdate) {
    requestToUpdate = false;
    display.display();
  }
}

/**
 * Scale the table to the oled display with 128 x 64 pixel
 */
void getSawWave() {
  for (int n=0; n < WAVEDISP_WIDTH; n++) {
    uint16_t idx = (n * SawLengthInt) / WAVEDISP_WIDTH;
    waveFormD[n] = 31+ (getSawInt(idx) >> 6); // table = 0-255; display = 0-63
  }
}

void getSinWave() {
  for (int n=0; n < WAVEDISP_WIDTH; n++) {
    uint16_t idx = (n * SinusLengthInt) / WAVEDISP_WIDTH;
    waveFormD[n] = 31+ (getSinInt(idx) >> 6); // table = 0-255; display = 0-63
  }
}
void getTriWave() {
  for (int n=0; n < WAVEDISP_WIDTH; n++) {
    uint16_t idx = (n * TriLengthInt) / WAVEDISP_WIDTH;
    waveFormD[n] = 31+ (getTriInt(idx) >> 6); // table = 0-255; display = 0-63
  }
}
/*void getSQRWave() {
  
    for (int n=0; n < WAVEDISP_WIDTH; n++) {
      uint16_t idx = (n * TriLength) / WAVEDISP_WIDTH;
      waveFormD[n] = (idx < pwm_value)?63:0; 
    }
  
}
*/
void drawWaveForm(int w) {
  display.clearDisplay();
  int h = height -1;
  if (w == SQR) {
    //Serial.print("pwm_value="); 
    //Serial.print(pwm_value);
    
    uint32_t pwmx = pwm_value * WAVEDISP_WIDTH;
    //Serial.print(" z=");
    //Serial.print(pwmx);
    pwmx = xstart + (pwmx >> 10); // : 1024 (0-1024 is the range for the pwm) 
    //Serial.print(" pwmx=");
    //Serial.println(pwmx);
    
    display.drawLine(xstart, 0, pwmx, 0, WHITE);
    display.drawLine(pwmx, 0, pwmx, h, WHITE);
    display.drawLine(pwmx, h, xstart + WAVEDISP_WIDTH, h, WHITE);
  }
  else if (w == FM) {
    dispFM();
  }
  else {
    for (int n = 0; n < WAVEDISP_WIDTH; n++)
      display.drawPixel(xstart+n, h - waveFormD[n], WHITE);
  }
}

