/**
 * 
 */
uint16_t ATanLength = 1420;
// saw, 1024 byte
const uint8_t PROGMEM atanS[] = {
0x0,0x0,0x0,0x3,0x0,0x6,0x0,0x9,0x0,0xd,0x0,0x10,0x0,0x13,0x0,0x16,
0x0,0x19,0x0,0x1c,0x0,0x1f,0x0,0x22,0x0,0x26,0x0,0x29,0x0,0x2c,0x0,0x2f,
0x0,0x32,0x0,0x35,0x0,0x38,0x0,0x3b,0x0,0x3f,0x0,0x42,0x0,0x45,0x0,0x48,
0x0,0x4b,0x0,0x4e,0x0,0x51,0x0,0x54,0x0,0x57,0x0,0x5b,0x0,0x5e,0x0,0x61,
0x0,0x64,0x0,0x67,0x0,0x6a,0x0,0x6d,0x0,0x70,0x0,0x73,0x0,0x77,0x0,0x7a,
0x0,0x7d,0x0,0x80,0x0,0x83,0x0,0x86,0x0,0x89,0x0,0x8c,0x0,0x8f,0x0,0x93,
0x0,0x96,0x0,0x99,0x0,0x9c,0x0,0x9f,0x0,0xa2,0x0,0xa5,0x0,0xa8,0x0,0xab,
0x0,0xae,0x0,0xb1,0x0,0xb4,0x0,0xb8,0x0,0xbb,0x0,0xbe,0x0,0xc1,0x0,0xc4,
0x0,0xc7,0x0,0xca,0x0,0xcd,0x0,0xd0,0x0,0xd3,0x0,0xd6,0x0,0xd9,0x0,0xdc,
0x0,0xdf,0x0,0xe2,0x0,0xe5,0x0,0xe9,0x0,0xec,0x0,0xef,0x0,0xf2,0x0,0xf5,
0x0,0xf8,0x0,0xfb,0x0,0xfe,0x1,0x1,0x1,0x4,0x1,0x7,0x1,0xa,0x1,0xd,
0x1,0x10,0x1,0x13,0x1,0x16,0x1,0x19,0x1,0x1c,0x1,0x1f,0x1,0x22,0x1,0x25,
0x1,0x28,0x1,0x2b,0x1,0x2e,0x1,0x31,0x1,0x34,0x1,0x37,0x1,0x3a,0x1,0x3d,
0x1,0x40,0x1,0x43,0x1,0x46,0x1,0x49,0x1,0x4c,0x1,0x4f,0x1,0x52,0x1,0x55,
0x1,0x57,0x1,0x5a,0x1,0x5d,0x1,0x60,0x1,0x63,0x1,0x66,0x1,0x69,0x1,0x6c,
0x1,0x6f,0x1,0x72,0x1,0x75,0x1,0x78,0x1,0x7b,0x1,0x7e,0x1,0x80,0x1,0x83,
0x1,0x86,0x1,0x89,0x1,0x8c,0x1,0x8f,0x1,0x92,0x1,0x95,0x1,0x98,0x1,0x9a,
0x1,0x9d,0x1,0xa0,0x1,0xa3,0x1,0xa6,0x1,0xa9,0x1,0xac,0x1,0xae,0x1,0xb1,
0x1,0xb4,0x1,0xb7,0x1,0xba,0x1,0xbd,0x1,0xbf,0x1,0xc2,0x1,0xc5,0x1,0xc8,
0x1,0xcb,0x1,0xce,0x1,0xd0,0x1,0xd3,0x1,0xd6,0x1,0xd9,0x1,0xdc,0x1,0xde,
0x1,0xe1,0x1,0xe4,0x1,0xe7,0x1,0xe9,0x1,0xec,0x1,0xef,0x1,0xf2,0x1,0xf4,
0x1,0xf7,0x1,0xfa,0x1,0xfd,0x1,0xff,0x2,0x2,0x2,0x5,0x2,0x8,0x2,0xa,
0x2,0xd,0x2,0x10,0x2,0x12,0x2,0x15,0x2,0x18,0x2,0x1b,0x2,0x1d,0x2,0x20,
0x2,0x23,0x2,0x25,0x2,0x28,0x2,0x2b,0x2,0x2d,0x2,0x30,0x2,0x33,0x2,0x35,
0x2,0x38,0x2,0x3b,0x2,0x3d,0x2,0x40,0x2,0x43,0x2,0x45,0x2,0x48,0x2,0x4a,
0x2,0x4d,0x2,0x50,0x2,0x52,0x2,0x55,0x2,0x57,0x2,0x5a,0x2,0x5d,0x2,0x5f,
0x2,0x62,0x2,0x64,0x2,0x67,0x2,0x6a,0x2,0x6c,0x2,0x6f,0x2,0x71,0x2,0x74,
0x2,0x76,0x2,0x79,0x2,0x7b,0x2,0x7e,0x2,0x81,0x2,0x83,0x2,0x86,0x2,0x88,
0x2,0x8b,0x2,0x8d,0x2,0x90,0x2,0x92,0x2,0x95,0x2,0x97,0x2,0x9a,0x2,0x9c,
0x2,0x9f,0x2,0xa1,0x2,0xa3,0x2,0xa6,0x2,0xa8,0x2,0xab,0x2,0xad,0x2,0xb0,
0x2,0xb2,0x2,0xb5,0x2,0xb7,0x2,0xb9,0x2,0xbc,0x2,0xbe,0x2,0xc1,0x2,0xc3,
0x2,0xc6,0x2,0xc8,0x2,0xca,0x2,0xcd,0x2,0xcf,0x2,0xd2,0x2,0xd4,0x2,0xd6,
0x2,0xd9,0x2,0xdb,0x2,0xdd,0x2,0xe0,0x2,0xe2,0x2,0xe4,0x2,0xe7,0x2,0xe9,
0x2,0xeb,0x2,0xee,0x2,0xf0,0x2,0xf2,0x2,0xf5,0x2,0xf7,0x2,0xf9,0x2,0xfc,
0x2,0xfe,0x3,0x0,0x3,0x3,0x3,0x5,0x3,0x7,0x3,0x9,0x3,0xc,0x3,0xe,
0x3,0x10,0x3,0x12,0x3,0x15,0x3,0x17,0x3,0x19,0x3,0x1b,0x3,0x1e,0x3,0x20,
0x3,0x22,0x3,0x24,0x3,0x27,0x3,0x29,0x3,0x2b,0x3,0x2d,0x3,0x2f,0x3,0x32,
0x3,0x34,0x3,0x36,0x3,0x38,0x3,0x3a,0x3,0x3d,0x3,0x3f,0x3,0x41,0x3,0x43,
0x3,0x45,0x3,0x47,0x3,0x49,0x3,0x4c,0x3,0x4e,0x3,0x50,0x3,0x52,0x3,0x54,
0x3,0x56,0x3,0x58,0x3,0x5b,0x3,0x5d,0x3,0x5f,0x3,0x61,0x3,0x63,0x3,0x65,
0x3,0x67,0x3,0x69,0x3,0x6b,0x3,0x6d,0x3,0x6f,0x3,0x71,0x3,0x74,0x3,0x76,
0x3,0x78,0x3,0x7a,0x3,0x7c,0x3,0x7e,0x3,0x80,0x3,0x82,0x3,0x84,0x3,0x86,
0x3,0x88,0x3,0x8a,0x3,0x8c,0x3,0x8e,0x3,0x90,0x3,0x92,0x3,0x94,0x3,0x96,
0x3,0x98,0x3,0x9a,0x3,0x9c,0x3,0x9e,0x3,0xa0,0x3,0xa2,0x3,0xa4,0x3,0xa6,
0x3,0xa8,0x3,0xaa,0x3,0xab,0x3,0xad,0x3,0xaf,0x3,0xb1,0x3,0xb3,0x3,0xb5,
0x3,0xb7,0x3,0xb9,0x3,0xbb,0x3,0xbd,0x3,0xbf,0x3,0xc1,0x3,0xc2,0x3,0xc4,
0x3,0xc6,0x3,0xc8,0x3,0xca,0x3,0xcc,0x3,0xce,0x3,0xd0,0x3,0xd1,0x3,0xd3,
0x3,0xd5,0x3,0xd7,0x3,0xd9,0x3,0xdb,0x3,0xdc,0x3,0xde,0x3,0xe0,0x3,0xe2,
0x3,0xe4,0x3,0xe6,0x3,0xe7,0x3,0xe9,0x3,0xeb,0x3,0xed,0x3,0xef,0x3,0xf0,
0x3,0xf2,0x3,0xf4,0x3,0xf6,0x3,0xf8,0x3,0xf9,0x3,0xfb,0x3,0xfd,0x3,0xff,
0x4,0x0,0x4,0x2,0x4,0x4,0x4,0x6,0x4,0x7,0x4,0x9,0x4,0xb,0x4,0xd,
0x4,0xe,0x4,0x10,0x4,0x12,0x4,0x13,0x4,0x15,0x4,0x17,0x4,0x19,0x4,0x1a,
0x4,0x1c,0x4,0x1e,0x4,0x1f,0x4,0x21,0x4,0x23,0x4,0x24,0x4,0x26,0x4,0x28,
0x4,0x29,0x4,0x2b,0x4,0x2d,0x4,0x2e,0x4,0x30,0x4,0x32,0x4,0x33,0x4,0x35,
0x4,0x37,0x4,0x38,0x4,0x3a,0x4,0x3b,0x4,0x3d,0x4,0x3f,0x4,0x40,0x4,0x42,
0x4,0x44,0x4,0x45,0x4,0x47,0x4,0x48,0x4,0x4a,0x4,0x4c,0x4,0x4d,0x4,0x4f,
0x4,0x50,0x4,0x52,0x4,0x53,0x4,0x55,0x4,0x57,0x4,0x58,0x4,0x5a,0x4,0x5b,
0x4,0x5d,0x4,0x5e,0x4,0x60,0x4,0x61,0x4,0x63,0x4,0x64,0x4,0x66,0x4,0x68,
0x4,0x69,0x4,0x6b,0x4,0x6c,0x4,0x6e,0x4,0x6f,0x4,0x71,0x4,0x72,0x4,0x74,
0x4,0x75,0x4,0x77,0x4,0x78,0x4,0x7a,0x4,0x7b,0x4,0x7d,0x4,0x7e,0x4,0x80,
0x4,0x81,0x4,0x82,0x4,0x84,0x4,0x85,0x4,0x87,0x4,0x88,0x4,0x8a,0x4,0x8b,
0x4,0x8d,0x4,0x8e,0x4,0x90,0x4,0x91,0x4,0x92,0x4,0x94,0x4,0x95,0x4,0x97,
0x4,0x98,0x4,0x9a,0x4,0x9b,0x4,0x9c,0x4,0x9e,0x4,0x9f,0x4,0xa1,0x4,0xa2,
0x4,0xa3,0x4,0xa5,0x4,0xa6,0x4,0xa8,0x4,0xa9,0x4,0xaa,0x4,0xac,0x4,0xad,
0x4,0xae,0x4,0xb0,0x4,0xb1,0x4,0xb3,0x4,0xb4,0x4,0xb5,0x4,0xb7,0x4,0xb8,
0x4,0xb9,0x4,0xbb,0x4,0xbc,0x4,0xbd,0x4,0xbf,0x4,0xc0,0x4,0xc1,0x4,0xc3,
0x4,0xc4,0x4,0xc5,0x4,0xc7,0x4,0xc8,0x4,0xc9,0x4,0xcb,0x4,0xcc,0x4,0xcd,
0x4,0xce,0x4,0xd0,0x4,0xd1,0x4,0xd2,0x4,0xd4,0x4,0xd5,0x4,0xd6,0x4,0xd8,
0x4,0xd9,0x4,0xda,0x4,0xdb,0x4,0xdd,0x4,0xde,0x4,0xdf,0x4,0xe0,0x4,0xe2,
0x4,0xe3,0x4,0xe4,0x4,0xe5,0x4,0xe7,0x4,0xe8,0x4,0xe9,0x4,0xea,0x4,0xec,
0x4,0xed,0x4,0xee,0x4,0xef,0x4,0xf1,0x4,0xf2,0x4,0xf3,0x4,0xf4,0x4,0xf5,
0x4,0xf7,0x4,0xf8,0x4,0xf9,0x4,0xfa,0x4,0xfc,0x4,0xfd,0x4,0xfe,0x4,0xff,
0x5,0x0,0x5,0x1,0x5,0x3,0x5,0x4,0x5,0x5,0x5,0x6,0x5,0x7,0x5,0x9,
0x5,0xa,0x5,0xb,0x5,0xc,0x5,0xd,0x5,0xe,0x5,0x10,0x5,0x11,0x5,0x12,
0x5,0x13,0x5,0x14,0x5,0x15,0x5,0x16,0x5,0x18,0x5,0x19,0x5,0x1a,0x5,0x1b,
0x5,0x1c,0x5,0x1d,0x5,0x1e,0x5,0x20,0x5,0x21,0x5,0x22,0x5,0x23,0x5,0x24,
0x5,0x25,0x5,0x26,0x5,0x27,0x5,0x28,0x5,0x2a,0x5,0x2b,0x5,0x2c,0x5,0x2d,
0x5,0x2e,0x5,0x2f,0x5,0x30,0x5,0x31,0x5,0x32,0x5,0x33,0x5,0x35,0x5,0x36,
0x5,0x37,0x5,0x38,0x5,0x39,0x5,0x3a,0x5,0x3b,0x5,0x3c,0x5,0x3d,0x5,0x3e,
0x5,0x3f,0x5,0x40,0x5,0x41,0x5,0x42,0x5,0x43,0x5,0x44,0x5,0x46,0x5,0x47,
0x5,0x48,0x5,0x49,0x5,0x4a,0x5,0x4b,0x5,0x4c,0x5,0x4d,0x5,0x4e,0x5,0x4f,
0x5,0x50,0x5,0x51,0x5,0x52,0x5,0x53,0x5,0x54,0x5,0x55,0x5,0x56,0x5,0x57,
0x5,0x58,0x5,0x59,0x5,0x5a,0x5,0x5b,0x5,0x5c,0x5,0x5d,0x5,0x5e,0x5,0x5f,
0x5,0x60,0x5,0x61,0x5,0x62,0x5,0x63,0x5,0x64,0x5,0x65,0x5,0x66,0x5,0x67,
0x5,0x68,0x5,0x69,0x5,0x6a,0x5,0x6b,0x5,0x6c,0x5,0x6d,0x5,0x6e,0x5,0x6f,
0x5,0x70,0x5,0x71,0x5,0x72,0x5,0x72,0x5,0x73,0x5,0x74,0x5,0x75,0x5,0x76,
0x5,0x77,0x5,0x78,0x5,0x79,0x5,0x7a,0x5,0x7b,0x5,0x7c,0x5,0x7d,0x5,0x7e,
0x5,0x7f,0x5,0x80,0x5,0x81,0x5,0x81,0x5,0x82,0x5,0x83,0x5,0x84,0x5,0x85,
0x5,0x86,0x5,0x87,0x5,0x88,0x5,0x89,0x5,0x8a,0x5,0x8b
};

/**
 * @param index from 0-table length (1420)
 */
uint16_t getATan(uint16_t index) {
  uint16_t idx = index / 2;
  idx *= 2;
  uint16 r = pgm_read_byte( &atanS[idx] );
  r = (r << 8) +  pgm_read_byte( &atanS[idx+1] ); // msb + lsb
  return r;
}

