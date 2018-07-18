/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16F1709
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"


void (*IOCCF1_InterruptHandler)(void);
void (*IOCCF7_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */   
    LATA = 0x00;    
    LATB = 0x80;    
    LATC = 0x00;    

    /**
    TRISx registers
    */    
    TRISA = 0x20;
    TRISB = 0x10;
    TRISC = 0xEB;

    /**
    ANSELx registers
    */   
    ANSELC = 0x08;
    ANSELB = 0x00;
    ANSELA = 0x00;

    /**
    WPUx registers
    */ 
    WPUB = 0x00;
    WPUA = 0x08;
    WPUC = 0x88;
    OPTION_REGbits.nWPUEN = 0;

    /**
    ODx registers
    */   
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    

    /**
    IOCx registers
    */
    // interrupt on change for group IOCCF - flag
    IOCCFbits.IOCCF1 = 0;
    IOCCFbits.IOCCF7 = 0;
    // interrupt on change for group IOCCN - negative
    IOCCNbits.IOCCN1 = 0;
    IOCCNbits.IOCCN7 = 1;
    // interrupt on change for group IOCCP - positive
    IOCCPbits.IOCCP1 = 1;
    IOCCPbits.IOCCP7 = 0;

    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);
    IOCCF7_SetInterruptHandler(IOCCF7_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    INTCONbits.IOCIE = 1; 
    
    
    bool state = (unsigned char)GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS
    
    SSPDATPPSbits.SSPDATPPS = 0x0C;   //RB4->MSSP:SDI;
    RB6PPSbits.RB6PPS = 0x10;   //RB6->MSSP:SCK;
    SSPCLKPPSbits.SSPCLKPPS = 0x0E;   //RB6->MSSP:SCK;
    RB5PPSbits.RB5PPS = 0x12;   //RB5->MSSP:SDO;

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS

    GIE = state;
}       

void PIN_MANAGER_IOC(void)
{   
    // interrupt on change for pin IOCCF1
    if(IOCCFbits.IOCCF1 == 1)
    {
        IOCCF1_ISR();  
    }                          

    // interrupt on change for pin IOCCF7
    if(IOCCFbits.IOCCF7 == 1)
    {
        IOCCF7_ISR();  
    }                          


}

/**
   IOCCF1 Interrupt Service Routine
*/
void IOCCF1_ISR(void) {

    // Add custom IOCCF1 code
    inter_adxl(); //define this method in main

    // Call the interrupt handler for the callback registered at runtime
    if(IOCCF1_InterruptHandler)
    {
        IOCCF1_InterruptHandler();
    }
    IOCCFbits.IOCCF1 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF1 at application runtime
*/
void IOCCF1_SetInterruptHandler(void* InterruptHandler){
    IOCCF1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF1
*/
void IOCCF1_DefaultInterruptHandler(void){
    // add your IOCCF1 interrupt custom code
    // or set custom function using IOCCF1_SetInterruptHandler()
}

/**
   IOCCF7 Interrupt Service Routine
*/
void IOCCF7_ISR(void) {

    // Add custom IOCCF7 code
    inter_sw1();

    // Call the interrupt handler for the callback registered at runtime
    if(IOCCF7_InterruptHandler)
    {
        IOCCF7_InterruptHandler();
    }
    IOCCFbits.IOCCF7 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF7 at application runtime
*/
void IOCCF7_SetInterruptHandler(void* InterruptHandler){
    IOCCF7_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF7
*/
void IOCCF7_DefaultInterruptHandler(void){
    // add your IOCCF7 interrupt custom code
    // or set custom function using IOCCF7_SetInterruptHandler()
}

/**
 End of File
*/