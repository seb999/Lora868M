#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();
    GIE = 1;

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();
    IOCIE = 1;

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        SWDTEN = 1;
        CLRWDT(); 
        
        if(IOCBF7){ 
            LED_GREEN_PORT  = 1;
            __delay_ms(500);
            LED_GREEN_PORT  = 0;
            IOCBF7=0; 
        }
    }
}
/**
 End of File
*/