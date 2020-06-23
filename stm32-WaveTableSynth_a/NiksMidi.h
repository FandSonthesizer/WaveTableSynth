#include "stm32-WaveTableSynth_a.h"
#include "Graphic.h" 

// Some midi buffer vars:
uint8_t mBuffer[3];
uint8_t mIdx = 0;
uint8_t cmdLen =1;
uint8_t command = 0;


void doRead(void);


/**
 * Midi command received, execute it!
 * handleNoteOn(ch, note , vel);
 */
void executeMidi() {
    // received 3 bytes
    if (command >= 0x90 && command <= 0x9f) {
      handleNoteOn(command & 0x0f, mBuffer[0], mBuffer[1]);
    }
    else if (command >= 0x80 && command <= 0x8f) {
      handleNoteOff(command & 0x0f, mBuffer[0], 0);
    }
    else if (command >= 0xb0 && command <= 0xbf) {
      // control change
      if ( mBuffer[0] == 123 &&  mBuffer[1] == 0) {
        // all notes off!
        handleAllNoteOff();
      }
    }
}


/**
   * Here it is, my very basic Midi in method...
   */
  void readMIDI(){
    bool a = false;
    #if defined USE_BOOTLOADER 
      a = Serial1.available();
    #elif !defined USE_BOOTLOADER 
      a = Serial.available();
    #endif  
   if (a)
      doRead();
  }

/**
 * Check if this byte is a command byte
 * @param the byte we just read
 * @return the length of the expected command, if it is a command byte ! Else return 0
 */
int isCommand(uint8_t b ) {
  int l = 0;
  if (b >= 0x80 && b <= 0x8f) { // Note off
    l = 2; 
    command = b;
  }
  else if (b >= 0x90 && b <= 0x9f) { // Note on
    l = 2;
    command = b;
  }
  else if (b >= 0xa0 && b <= 0xaf) {
     // aftertouch, poly
    l = 2;
    command = b;
  }
  else if (b >= 0xb0 && b <= 0xbf) {
     // control change
    l = 2;
    command = b;
  }
  else if (b >= 0xc0 && b <= 0xcf) {
     // program change
    l = 1;
    command = b;
  }
  else if (b >= 0xd0 && b <= 0xdf) {
     // aftertouch, channel
    l = 1;
    command = b;
  }
  else if (b >= 0xe0 && b <= 0xef) {
     // Pitch wheel
    l = 2;
    command = b;
  }
  else if (b >= 0xf0 && b <= 0xff) {
     // System exclusive
    l = 1; // this may be wrong, change per manufacturer
    command = b;
  }
  return l;
}


/**
 * Read one byte from the serial stream
 */
  void doRead() {
    uint8_t b = 0;
    #if defined USE_BOOTLOADER  
      b = Serial1.read();
    #elif !defined USE_BOOTLOADER 
      b = Serial.read();
    #endif
    // display the byte on the display
    //printHex(b);

    int len = isCommand(b );
    if (len > 0){
      cmdLen = len;
      mIdx = 0; // reset buffer index
    }
    else {
      // is a data-byte 
      mBuffer[mIdx++] = b;
      cmdLen--;
      if (cmdLen == 0) {
        // all data byte are read, now execute the command
         executeMidi();
      }
    }

      /*
      // first initialize the command buffer
      if (cmd >= 0x90 && cmd <= 0x9f) {
        // note on command 
        mIdx = 2;
        mBuffer[mIdx--] = cmd;
      }
      else if (cmd >= 0x80 && cmd <= 0x8f) {
        // note on command
        mIdx = 2;
        //cmdLen = 3;
        mBuffer[mIdx--] = cmd;
      }
      else if (cmd >= 0xd0 && cmd < 0xdf) {
        // aftertouch
        mIdx = 1;
      }
      else
         mBuffer[mIdx--] = cmd;
         
      if (mIdx == 0) {
        // Execute command, data complete
      
        executeMidi();
      }
    }
    */
  }

