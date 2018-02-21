#include "mcc_generated_files/mcc.h"
#include "misc.h"
#include <stdbool.h>
#include <__null.h>



void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    GIE = 1;
    IOCIE = 1;

      //Initialise RN2483
    
    //TImer0 interruption Off
    INTCONbits.TMR0IE = 0;
    while (1)
    {    
        SWDTEN = 1;
        CLRWDT();  
//        char* ttt = EUSART_Read();
//        __delay_ms(100);
//        SendUartCmd(&ttt);
//        __delay_ms(250);
    }
}

char* ReadUartBuffer()
{
    int i=0;
    char *Output;
    
    //while(&Output[i] != "\n"){
    while(i != 3){
        CLRWDT(); 
        Output[i] = EUSART_Read();
         __delay_ms(100);
        i++;
    }
    SendUartCmd(Output);
    return Output;
}

//----INTERRUPTON METHOD-----
inter_sw1()
{
    int i;
    char res[1];
    
    LED_RED_PORT = 1;
    __delay_ms(250);
    LED_RED_PORT = 0;
    
    //wait that user release button
    while(SW1_PORT == 0);
    __delay_ms(250);
    
   //TEST START HERE
    
    //Test 2
    SendUartCmd("sys reset\r\n");
      __delay_ms(800);
      int i=1;
    char *Output;

//    while(i != 3){
//        CLRWDT(); 
//        Output[i] = EUSART_Read();
//         __delay_ms(100);
//        i++;
//    }
//    SendUartCmd(Output);
    while (1)
    {    
        SWDTEN = 1;
        CLRWDT(); 
         Output[0] = EUSART_Read();
        __delay_ms(100);
        Output[1] = EUSART_Read();
        SendUartCmd(Output);
        __delay_ms(250);
    }
    
    //Test 1
    
    //char *Output = ReadUartBuffer();
    //SendUartCmd(&Output);
  
    
    IOCBFbits.IOCBF6 = 0;

}

//sys reset
//mac join otaa
//(ok)
//(accepted)
//mac tx uncnf 9 123
//(ok)
//(mac_tx_ok)