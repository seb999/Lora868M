/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16F1709
        Version           :  1.01
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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()    do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()   do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()   do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()         PORTAbits.RA0
#define RA0_SetDigitalInput()   do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()  do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()     do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()   do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode() do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()    do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()   do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()   do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()         PORTAbits.RA4
#define RA4_SetDigitalInput()   do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()  do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()     do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()   do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode() do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()    do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()   do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()   do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()         PORTAbits.RA5
#define RA5_SetDigitalInput()   do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()  do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()     do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()   do { WPUAbits.WPUA5 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()    do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()   do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()   do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()         PORTBbits.RB4
#define RB4_SetDigitalInput()   do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()  do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()     do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()   do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode() do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()    do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()   do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()   do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()         PORTBbits.RB5
#define RB5_SetDigitalInput()   do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()  do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()     do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()   do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode() do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS               TRISBbits.TRISB6
#define SW1_LAT                LATBbits.LATB6
#define SW1_PORT               PORTBbits.RB6
#define SW1_WPU                WPUBbits.WPUB6
#define SW1_OD                ODCONBbits.ODB6
#define SW1_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SW1_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SW1_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SW1_GetValue()           PORTBbits.RB6
#define SW1_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SW1_SetPullup()      do { WPUBbits.WPUB6 = 1; } while(0)
#define SW1_ResetPullup()    do { WPUBbits.WPUB6 = 0; } while(0)
#define SW1_SetPushPull()    do { ODCONBbits.ODB6 = 1; } while(0)
#define SW1_SetOpenDrain()   do { ODCONBbits.ODB6 = 0; } while(0)

// get/set LED_RED aliases
#define LED_RED_TRIS               TRISBbits.TRISB7
#define LED_RED_LAT                LATBbits.LATB7
#define LED_RED_PORT               PORTBbits.RB7
#define LED_RED_WPU                WPUBbits.WPUB7
#define LED_RED_OD                ODCONBbits.ODB7
#define LED_RED_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define LED_RED_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define LED_RED_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define LED_RED_GetValue()           PORTBbits.RB7
#define LED_RED_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define LED_RED_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define LED_RED_SetPullup()      do { WPUBbits.WPUB7 = 1; } while(0)
#define LED_RED_ResetPullup()    do { WPUBbits.WPUB7 = 0; } while(0)
#define LED_RED_SetPushPull()    do { ODCONBbits.ODB7 = 1; } while(0)
#define LED_RED_SetOpenDrain()   do { ODCONBbits.ODB7 = 0; } while(0)

// get/set LED_GREEN aliases
#define LED_GREEN_TRIS               TRISCbits.TRISC7
#define LED_GREEN_LAT                LATCbits.LATC7
#define LED_GREEN_PORT               PORTCbits.RC7
#define LED_GREEN_WPU                WPUCbits.WPUC7
#define LED_GREEN_OD                ODCONCbits.ODC7
#define LED_GREEN_ANS                ANSELCbits.ANSC7
#define LED_GREEN_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED_GREEN_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED_GREEN_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED_GREEN_GetValue()           PORTCbits.RC7
#define LED_GREEN_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED_GREEN_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED_GREEN_SetPullup()      do { WPUCbits.WPUC7 = 1; } while(0)
#define LED_GREEN_ResetPullup()    do { WPUCbits.WPUC7 = 0; } while(0)
#define LED_GREEN_SetPushPull()    do { ODCONCbits.ODC7 = 1; } while(0)
#define LED_GREEN_SetOpenDrain()   do { ODCONCbits.ODC7 = 0; } while(0)
#define LED_GREEN_SetAnalogMode()  do { ANSELCbits.ANSC7 = 1; } while(0)
#define LED_GREEN_SetDigitalMode() do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF6 pin functionality
 * @Example
    IOCBF6_ISR();
 */
void IOCBF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF6_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_InterruptHandler);

*/
extern void (*IOCBF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_DefaultInterruptHandler);

*/
void IOCBF6_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/