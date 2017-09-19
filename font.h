#ifndef FONT_H
#define	FONT_H

const unsigned char Icon16x16[] = {
0x8F, 0xF1, 0xC1, 0x83, 0xFD, 0xBF, 0xFD, 0xBF, 0x3C, 0x3C, 0x1C, 0x38, 0x8E, 0x71, 0xCF, 0xF3, 0xCF, 0xF3, 0x8E, 0x71, 0x1C, 0x38, 0x3C, 0x3C, 0xFD, 0xBF, 0xFD, 0xBF, 0xC1, 0x83, 0x8F, 0xF1,  // Code for char 0
0x80, 0x01, 0xC0, 0x03, 0xFC, 0x3F, 0xFC, 0x3F, 0x3C, 0x3C, 0x1C, 0x38, 0x0E, 0x70, 0x0F, 0xF0, 0x0F, 0xF0, 0x0E, 0x70, 0x1C, 0x38, 0x3C, 0x3C, 0xFC, 0x3F, 0xFC, 0x3F, 0xC0, 0x03, 0x80, 0x01,   // Code for char 1
0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0xC0, 0x01, 0x80, 0x03, 0x00, 0x07, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x03, 0xC0, 0x01, 0xE0, 0x00, 0x70, 0x00, 0x38, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char 2
0x1F, 0xF8, 0x01, 0x80, 0xE1, 0x80, 0xC1, 0x81, 0x81, 0x83, 0x00, 0x07, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x03, 0xC0, 0x01, 0xE0, 0x00, 0x71, 0x80, 0x39, 0x80, 0x1D, 0x80, 0x01, 0x80, 0x1F, 0xF8,  // Code for char 3
0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x1C, 0x38, 0x38, 0x1C, 0x70, 0x0E, 0xE0, 0x07, 0xC0, 0x03, 0xC0, 0x03, 0xE0, 0x07, 0x70, 0x0E, 0x38, 0x1C, 0x1C, 0x38, 0x0C, 0x30, 0x00, 0x00, 0x00, 0x00,  // Code for char 4
0x1F, 0xF8, 0x01, 0x80, 0x0D, 0xB0, 0x1D, 0xB8, 0x39, 0x9C, 0x70, 0x0E, 0xE0, 0x07, 0xC0, 0x03, 0xC0, 0x03, 0xE0, 0x07, 0x70, 0x0E, 0x39, 0x9C, 0x1D, 0xB8, 0x0D, 0xB0, 0x01, 0x80, 0x1F, 0xF8,   // Code for char 5
0x00, 0x00, 0xFF, 0x07, 0x07, 0x05, 0x8D, 0x04, 0x59, 0x04, 0x31, 0x04, 0x61, 0x04, 0xC1, 0x04, 0x61, 0x04, 0x31, 0x04, 0x59, 0x04, 0x8D, 0x04, 0x07, 0x05, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00   // Code for char 6
 };

const unsigned char Battery8x21[] = {
0x7C, 0x7C, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,  // Code for char num #0
0x7C, 0x7C, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0xFF,  // Code for char num #1
0x7C, 0x7C, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0xFF,  // Code for char num #2
0x7C, 0x7C, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0xFF,  // Code for char num #3
0x7C, 0x7C, 0xFF, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0x7D, 0x7D, 0x7D, 0x01, 0xFF,  // Code for char num #4
0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01   // Code for char num #5
};

const unsigned char FlightMode8x12[] = {
0xFC, 0x00, 0x78, 0x00, 0x30, 0x00, 0x30, 0x00, 0xFF, 0x03, 0xFE, 0x01, 0xFC, 0x00, 0x78, 0x00, 0x78, 0x00, 0x78, 0x00, 0x78, 0x00, 0x78, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   // Code for char 0
};

const unsigned char Reception8x8[] = {
0x00, 0x3C, 0x7E, 0x7E, 0x7E, 0x7E, 0x3C, 0x00,  // Code for char num #0
0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00  // Code for char num #1
};

const unsigned char Battery6x8[] = {
0x23, 0x13, 0x08, 0x64, 0x62, 0x00, // % accessible with / char
0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00, // 0
0x00, 0x42, 0x7F, 0x40, 0x00, 0x00, // 1
0x42, 0x61, 0x51, 0x49, 0x46, 0x00, // 2
0x21, 0x41, 0x45, 0x4B, 0x31, 0x00, // 3
0x18, 0x14, 0x12, 0x7F, 0x10, 0x00, // 4
0x27, 0x45, 0x45, 0x45, 0x39, 0x00, // 5
0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00, // 6
0x01, 0x71, 0x09, 0x05, 0x03, 0x00, // 7
0x36, 0x49, 0x49, 0x49, 0x36, 0x00, // 8
0x06, 0x49, 0x49, 0x29, 0x1E, 0x00 // 9
};

const unsigned char Numeric12x16[] = { //Oled_SetFont(Terminal12x16, 12, 16, 47, 57);
0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0xF0, 0x0F, 0xF0, 0x0F, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, // + (/)    
0x00, 0x00, 0xF0, 0x0F, 0xFC, 0x3F, 0x0C, 0x3C, 0x06, 0x66, 0x06, 0x63, 0x86, 0x61, 0xC6, 0x60, 0x66, 0x60, 0x3C, 0x30, 0xFC, 0x3F, 0xF0, 0x0F, // 0
0x00, 0x00, 0x00, 0x00, 0x18, 0x60, 0x18, 0x60, 0x1C, 0x60, 0xFE, 0x7F, 0xFE, 0x7F, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, // 1
0x00, 0x00, 0x38, 0x60, 0x3C, 0x70, 0x0E, 0x78, 0x06, 0x7C, 0x06, 0x6E, 0x06, 0x67, 0x86, 0x63, 0xC6, 0x61, 0xEE, 0x60, 0x7C, 0x60, 0x38, 0x60, // 2
0x00, 0x00, 0x18, 0x18, 0x1C, 0x38, 0x0E, 0x70, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0xCE, 0x73, 0xFC, 0x3E, 0x78, 0x1C, // 3
0x00, 0x00, 0x80, 0x07, 0xC0, 0x07, 0xE0, 0x06, 0x70, 0x06, 0x38, 0x06, 0x1C, 0x06, 0x0E, 0x06, 0xFE, 0x7F, 0xFE, 0x7F, 0x00, 0x06, 0x00, 0x06, // 4
0x00, 0x00, 0x7E, 0x18, 0xFE, 0x38, 0xC6, 0x70, 0xC6, 0x60, 0xC6, 0x60, 0xC6, 0x60, 0xC6, 0x60, 0xC6, 0x60, 0xC6, 0x71, 0x86, 0x3F, 0x06, 0x1F, // 5
0x00, 0x00, 0x80, 0x1F, 0xE0, 0x3F, 0xF0, 0x73, 0xB8, 0x61, 0x9C, 0x61, 0x8E, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x73, 0x00, 0x3F, 0x00, 0x1E, // 6
0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x60, 0x06, 0x78, 0x06, 0x1E, 0x86, 0x07, 0xE6, 0x01, 0x7E, 0x00, 0x1E, 0x00, 0x06, 0x00, // 7
0x00, 0x00, 0x00, 0x1E, 0x78, 0x3F, 0xFC, 0x73, 0xCE, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0xCE, 0x61, 0xFC, 0x73, 0x78, 0x3F, 0x00, 0x1E, // 8
0x00, 0x00, 0x78, 0x00, 0xFC, 0x00, 0xCE, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x71, 0x86, 0x39, 0x86, 0x1D, 0xCE, 0x0F, 0xFC, 0x07, 0xF8, 0x01 // 9
};

const unsigned char Terminal12x16[] = {//Oled_SetFont(Terminal12x16, 12, 16, 64, 90);
0x00, 0x00, 0x38, 0x00, 0x3C, 0x00, 0x0E, 0x00, 0x06, 0x00, 0x06, 0x6F, 0x86, 0x6F, 0xC6, 0x01, 0xEE, 0x00, 0x7C, 0x00, 0x38, 0x00, 0x00, 0x00, // Code for char ?    
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // (space) // @
0x00, 0x00, 0x00, 0x70, 0x00, 0x7E, 0xC0, 0x0F, 0xF8, 0x0D, 0x3E, 0x0C, 0x3E, 0x0C, 0xF8, 0x0D, 0xC0, 0x0F, 0x00, 0x7E, 0x00, 0x70, 0x00, 0x00, // A
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0xCE, 0x61, 0xFC, 0x73, 0x78, 0x3F, 0x00, 0x1E, 0x00, 0x00, // B
0x00, 0x00, 0xE0, 0x07, 0xF8, 0x1F, 0x1C, 0x38, 0x0E, 0x70, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x0E, 0x70, 0x1C, 0x38, 0x18, 0x18, 0x00, 0x00, // C
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x06, 0x60, 0x0E, 0x70, 0x1C, 0x38, 0xF8, 0x1F, 0xE0, 0x07, 0x00, 0x00, // D
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x06, 0x60, 0x06, 0x60, 0x00, 0x00, // E
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x86, 0x01, 0x86, 0x01, 0x86, 0x01, 0x86, 0x01, 0x86, 0x01, 0x86, 0x01, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, // F
0x00, 0x00, 0xE0, 0x07, 0xF8, 0x1F, 0x1C, 0x38, 0x0E, 0x70, 0x06, 0x60, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x8E, 0x7F, 0x8C, 0x7F, 0x00, 0x00, // G
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0xFE, 0x7F, 0xFE, 0x7F, 0x00, 0x00, // H
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x60, 0x06, 0x60, 0xFE, 0x7F, 0xFE, 0x7F, 0x06, 0x60, 0x06, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // I
0x00, 0x00, 0x00, 0x1C, 0x00, 0x3C, 0x00, 0x70, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x70, 0xFE, 0x3F, 0xFE, 0x0F, 0x00, 0x00, // J
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x80, 0x01, 0xC0, 0x03, 0xE0, 0x07, 0x70, 0x0E, 0x38, 0x1C, 0x1C, 0x38, 0x0E, 0x70, 0x06, 0x60, 0x00, 0x00, // K
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x00, // L
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x3C, 0x00, 0xF0, 0x00, 0xC0, 0x03, 0xC0, 0x03, 0xF0, 0x00, 0x3C, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x00, 0x00, // M
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x1C, 0x00, 0x70, 0x00, 0xE0, 0x01, 0x80, 0x07, 0x00, 0x0E, 0x00, 0x38, 0xFE, 0x7F, 0xFE, 0x7F, 0x00, 0x00, // N
0x00, 0x00, 0xE0, 0x07, 0xF8, 0x1F, 0x1C, 0x38, 0x0E, 0x70, 0x06, 0x60, 0x06, 0x60, 0x0E, 0x70, 0x1C, 0x38, 0xF8, 0x1F, 0xE0, 0x07, 0x00, 0x00, // O
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x06, 0x03, 0x06, 0x03, 0x06, 0x03, 0x06, 0x03, 0x06, 0x03, 0x8E, 0x03, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00, // P
0x00, 0x00, 0xE0, 0x07, 0xF8, 0x1F, 0x1C, 0x38, 0x0E, 0x70, 0x06, 0x60, 0x06, 0x6C, 0x0E, 0x7C, 0x1C, 0x38, 0xF8, 0x7F, 0xE0, 0x67, 0x00, 0x00, // Q
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x06, 0x03, 0x06, 0x03, 0x06, 0x07, 0x06, 0x0F, 0x06, 0x1F, 0x8E, 0x3B, 0xFC, 0x71, 0xF8, 0x60, 0x00, 0x00, // R
0x00, 0x00, 0x78, 0x18, 0xFC, 0x38, 0xCE, 0x71, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x86, 0x61, 0x8E, 0x73, 0x1C, 0x3F, 0x18, 0x1E, 0x00, 0x00, // S
0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, // T
0x00, 0x00, 0xFE, 0x0F, 0xFE, 0x3F, 0x00, 0x70, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x00, 0x70, 0xFE, 0x3F, 0xFE, 0x0F, 0x00, 0x00, // U
0x00, 0x00, 0x0E, 0x00, 0x7E, 0x00, 0xF0, 0x03, 0x80, 0x1F, 0x00, 0x7C, 0x00, 0x7C, 0x80, 0x1F, 0xF0, 0x03, 0x7E, 0x00, 0x0E, 0x00, 0x00, 0x00, // V
0x00, 0x00, 0xFE, 0x7F, 0xFE, 0x7F, 0x00, 0x38, 0x00, 0x0C, 0x00, 0x07, 0x00, 0x07, 0x00, 0x0C, 0x00, 0x38, 0xFE, 0x7F, 0xFE, 0x7F, 0x00, 0x00, // W
0x00, 0x00, 0x06, 0x60, 0x1E, 0x78, 0x38, 0x1C, 0x60, 0x06, 0xC0, 0x03, 0xC0, 0x03, 0x60, 0x06, 0x38, 0x1C, 0x1E, 0x78, 0x06, 0x60, 0x00, 0x00, // X
0x00, 0x00, 0x06, 0x00, 0x1E, 0x00, 0x78, 0x00, 0xE0, 0x01, 0x80, 0x7F, 0x80, 0x7F, 0xE0, 0x01, 0x78, 0x00, 0x1E, 0x00, 0x06, 0x00, 0x00, 0x00, // Y
0x00, 0x00, 0x06, 0x60, 0x06, 0x78, 0x06, 0x7C, 0x06, 0x66, 0x86, 0x63, 0xC6, 0x61, 0x66, 0x60, 0x3E, 0x60, 0x1E, 0x60, 0x06, 0x60, 0x00, 0x00, // Z
};

#endif	/* FONT_H */
