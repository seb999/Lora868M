#include "misc.h"
#include <stdint.h>
#include <xc.h>
#include <stdbool.h>
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/mcc.h"


//----------OTHERS----------
void __delay_sec(int n){
    while(n--) __delay_ms(1000); 
}

//----------EUART PIN MANAGER----------
void PIN_MANAGER_GPS(void)
{
    bool state = (unsigned char)GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    RXPPSbits.RXPPS = 0x0C;   //RB4->EUSART:RX;
    RB5PPSbits.RB5PPS = 0x14;   //RB5->EUSART:TX;

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS

    GIE = state;
}

//----------EUART EXTENTION METHODS----------
void ReadUartCmd(char *Output, unsigned int length)
{
    Output[0] = EUSART_Read();
    for(int i=1;i<length;i++)
    {
        Output[i] = EUSART_Read();
//        if(Output[i-1]=='O' && Output[i]=='K')
//            break;
    }
}

void ReadUartCmdModified(char *Output)
{
    while(eusartRxCount != 0){
        *Output = EUSART_Read();
        Output++;
    }
}

void SendUartCmd(char *cmd)
{
  for(int i=0;cmd[i] !=  '\0' ;i++)
    EUSART_Write(cmd[i]);
}