#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI  PC14 // D1
#define OLED_CLK   PB10 // D0
#define OLED_DC    PB1 // DC
#define OLED_CS    PB0 // CS
#define OLED_RESET PB11 // RES

const int width =  SSD1306_LCDWIDTH; // pixel-width of display
const int height = SSD1306_LCDHEIGHT; // pixel height of display
const int LF = 8;     // line feed size

const int BASE = 0;
const int WAVESEL = 1;
const int DATTACK = 2;
const int DDECAY = 3;
const int SCOPE = 4;
const int DPWM = 5;
const int FMSTART = 6;
const int FMEND = 7;
const int FMDECAY = 8;
const int ADSRP = 9;
//const int MIDISNIF = 7; // not used
const int PAGEMAX = 9;

const int chDispY = LF;
const int noOnY = LF*2;   // note on-off y pos
const int chDispX = 0;   // midi Channel
const int ntOnX = 42;   // note on x pos
const int ntOffX = 85;   // note off x pos
const int curveOffX = 42;
const int ntW = 42; // width of fields

const int ARROW_WIDTH = 8;
const int DGAP = 3;
int WAVEDISP_WIDTH = width - 2*ARROW_WIDTH - 2 * DGAP;
int xstart = ARROW_WIDTH + DGAP;

uint16_t  page = BASE;    // this is the ui-page we actually display
uint16_t  opx = 0;
uint16_t  opy = 0;
uint16_t at, de, sus, rel; // adsr values
int16_t fat, fde, pw; // filter ad values

bool requestToUpdate = true; // if true, execute the  display.display() function
int cx = 0, cy = 0;

 Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
 
void initGraphic() {
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  //delay(2000);
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void printHex(byte b) {
  display.print("0x");
  display.print(b, HEX);
  display.print(",");
  cx++;
  if (cx > 3) {
    cx = 0;
    
    display.println("");
    cy++;
    if (cy > 7) {
      display.clearDisplay();
      cy == 0;
    }
    display.setCursor(0, cy*8);
  }
  
}

/**
 * map to 128 * 64 pixel display
 * @param y in the range of 0-1024
 * @param x in the range of 0-4000;
 * 
 */
void dispCurve(uint16_t y, uint32_t x, uint16_t max) {
  uint16_t h = height - 1;
  uint16_t xp = (uint16_t) (x & 0xffff) * width / max;
  uint16_t yp = (y * h) >> 10;
  display.drawLine(opx, h - opy, xp, h - yp, WHITE);
  opx = xp;
  opy = yp;
}

// set adsr values to display
void setAtValue(uint16_t a) {
  at = a;
}
void setDeValue(uint16_t a) {
  de = a;
}
void setSusValue(uint16_t a) {
  sus = a;
}
void setReValue(uint16_t a) {
  rel = a;
}

// set adsr values to display
void setFAtValue(uint16_t a) {
  fat = a;
}
void setFDeValue(uint16_t a) {
  fde = a;
}

void drawADSR() {
 
    display.clearDisplay();
    uint16_t y = height -1;
    uint16_t x = 0;
    uint32_t s = sus * 32 / 4096; // convert to pixel

    display.setTextSize(2);
    display.setCursor(80, 0);
    display.println("ADSR"); 
    /*Serial.print("at=");
    Serial.println(at);
    */
    // Attack
    uint32_t a = at * 32 / 4096; // after what pixel we are at 100%
   // Serial.println(a);
    display.drawLine(x, height, a, 0, WHITE);
    display.drawLine(a, 0, 32, 0, WHITE);
    // Decay & sustain
    x = 32;
    a = de * 32 / 4096; // 
    y = height - s -1;
    display.drawLine(x, 0, x+a, y, WHITE);
    display.drawLine(x+a, y, x+64, y, WHITE);
    x = 96;
    // release
    a = rel * 32 / 4096; //
    display.drawLine(x, y, x+a, height-1, WHITE);
    display.drawLine(x+a, height-1, 128, height-1, WHITE);
    
}

void drawAD(uint16_t mode) {
 
    display.clearDisplay();
    uint16_t y = height -1;
    uint16_t x = 0;
    uint32_t a = fat * 64 / 4095; // convert to pixel
    uint16_t h = 20;
    display.setTextSize(2);
    display.setCursor(40, 0);
    if (mode == 0)
      display.println("Attack"); 
    else 
      display.println("Decay"); 
    /*Serial.print("at=");
    Serial.println(at);
    */
    // Attack
   // Serial.println(a);
    display.drawLine(x, height, a, h, WHITE);
    display.drawLine(a, h, 64, h, WHITE);
    uint16_t s = 1;
    // Decay 
    x = 64;
    a = fde * 64 / 4095; // 
    y = height - s -1;
    display.drawLine(x, h, x+a, y, WHITE);
    display.drawLine(x+a, y, 128, y, WHITE);
    
}


void drawPWM() {
    display.clearDisplay();
    uint16_t y = height -1;
    uint16_t x = 0;
    uint16_t h = 20;
    display.setTextSize(2);
    display.setCursor(40, 0);
    display.println("PWM"); 
    uint16_t a = pw * 127 / 1023; // // table length
    display.drawLine(x, y, x, h, WHITE);
    display.drawLine(x, h, a, h, WHITE);
    display.drawLine(a, h, a, y, WHITE); 
    display.drawLine(a, y, 127, y, WHITE);
      
}
void dispFM() {
  display.clearDisplay();
  int y = noOnY+LF;
  display.setCursor(ntOnX,y);
  // clear old text
  display.fillRect(ntOnX, y, ntW, LF, 0);
  //display.display();
  display.print("FM");
  //display.println(nt);
  display.display();
}

void drawFMStart(int nt) {
  display.clearDisplay();
  uint16_t y = height -1;
  uint16_t x = 0;
  uint16_t h = 20;
  display.setTextSize(2);
  display.setCursor(10, 0);
  display.println("FM-Start"); 
  y = noOnY+LF;
  display.setCursor(ntOnX,y);
  // clear old text
  display.fillRect(ntOnX, y, ntW*4, LF, 0);
  display.println(nt);
  display.display();
}
void drawFMEnd(int nt) {
  display.clearDisplay();
  uint16_t y = height -1;
  uint16_t x = 0;
  uint16_t h = 20;
  display.setTextSize(2);
  display.setCursor(10, 0);
  display.println("FM-End"); 
  y = noOnY+LF;
  display.setCursor(ntOnX,y);
  // clear old text
  display.fillRect(ntOnX, y, ntW*4, LF, 0);
  display.println(nt);
  display.display();
}

void drawFMDecay(int nt) {
  display.clearDisplay();
  uint16_t y = height -1;
  uint16_t x = 0;
  uint16_t h = 20;
  display.setTextSize(2);
  display.setCursor(10, 0);
  display.println("FM-Decay"); 
  y = noOnY+LF;
  display.setCursor(ntOnX,y);
  // clear old text
  display.fillRect(ntOnX, y, ntW*4, LF, 0);
  display.println(nt);
  display.display();
}

void drawLeftArrow() {
  // Navigation arrows
  int x = 0;
  int y = height / 2;
  int h = ARROW_WIDTH;
  int w = 2*h;
  display.fillRect(x, y - h, h+2, w+2, WHITE);
  display.drawLine(x, y, x + h , y - h, BLACK);
  display.drawLine(x, y, x + h , y + h, BLACK);
}

void drawRightArrow() {
  // Navigation arrows
  int h = ARROW_WIDTH;
  int x = width - 1;
  int y = height / 2;
  int w = 2*h;
  display.fillRect(x -h -1, y -h, h+2, w+2, WHITE);
  display.drawLine(x, y, x - h , y - h, BLACK);
  display.drawLine(x, y, x - h , y + h, BLACK);
}

void displayPage0(int mCh, int sNo) {
  display.clearDisplay();
  
  int h = 22;
  int off = 15;
  // text display tests
  display.setTextSize(2);
  int y = 2;
  int x = off;
  display.setCursor(x, y);
  display.println("F&S V1.1"); 
  /*y += h;
  x = 0;
  display.setCursor(x, y);
  display.println("Synth V1.0");
  */
  y += h;
  x = off;
  display.setCursor(x, y);
  // clear old text
  //display.fillRect(x, y, width, h, 0);
  display.print("MidiCh:");
  display.println(mCh);
  // Navigation arrows
  drawLeftArrow();
  drawRightArrow();
  y += h;
  x = off;
 // Waveform:
  display.setCursor(x, y);
  display.print("Wave:");
  if (sNo == 0)
    display.println("Saw");
  else if (sNo == 1)
    display.println("Sin");
  else if (sNo == 2)
    display.println("Tri");  
  else if (sNo == 3)
    display.println("SQR"); 
  else if (sNo == 4)
    display.println("FM"); 
}




