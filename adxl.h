
#ifndef ADXL_H
#define	ADXL_H

#include <xc.h> // include processor files - each processor file is guarded.  

// ADLX Registers
#define ADXL_RESET 0x1f
#define ADXL_INTMAP2 0x2b
#define ADXL_POWER_CTL 0x2d
#define ADXL_WR_SPI 0x0A
#define ADXL_RD_SPI 0x0B
#define DOWN 0
#define UP 1
#define ADXL_CS PORTAbits.RA2
//#define ADXL_INT2 PORTCbits.RC0   rev001
#define ADXL_INT2 PORTCbits.RC1    //rev002

void ADXL_Init(void);

//Write SPI bus
void ADXL_WriteReg( char reg, char cmd );

//Read SPI bus
char ADXL_ReadReg( char reg );

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

