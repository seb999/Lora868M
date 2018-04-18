#include "mcc_generated_files/mcc.h"
#include "misc.h"
#include <stdbool.h>
#include <__null.h>

void main(void)
{
    SWDTEN = 1;
    // initialize the device
    SYSTEM_Initialize();
     LED_RED_PORT = 1;
    __delay_ms(250);
    LED_RED_PORT = 0;
    EUART_GPS();
    InitGPS();
    GIE = 1;
    IOCIE = 1;

    //TImer0 interruption Off
    INTCONbits.TMR0IE = 0;
    while (1)
    {    
        CLRWDT();  
    }
}

//----INTERRUPTON METHOD-----
inter_sw1()
{
    CLRWDT();
    char res[20]="";
    //res[0] = "\n";
   
    //wait that user release button
    while(SW1_PORT == 0);
    
     //Read GPS position TESTED
//    EUART_GPS();
//    SendUartCmd("$PUBX,40,GLL,1,1,0,0,0\r\n"); //GPS ON
//    ReadUartCmd(res);
//    SendUartCmd(res);
//    SendUartCmd("$PUBX,40,GLL,1,0,0,0,0\r\n");// GPS OFF
//    CLRWDT();
    
    //Look for LORA NETWORK
    EUART_LORA();
    SendUartCmd("sys reset\r\n"); 
    ReadUartCmd(res);
 
    SendUartCmd("mac join otaa\r\n");
    ReadUartCmd(res);
    SendUartCmd(res);
    
    ReadUartCmd(res);
    SendUartCmd(res);

    //char ttt2 = ReadUartCmd();
    //SendUartCmd(ttt2);
    //res[0] = '\0';
    //ReadUartCmd(res);
     //SendUartCmd(res);
//    CLRWDT();
//    if(res != "ok") return;
//    LED_GREEN_PORT = 1;
//    __delay_ms(200);
//    LED_GREEN_PORT = 0;
//    __delay_ms(200);
//    LED_GREEN_PORT = 1;
//    __delay_ms(200);
//    LED_GREEN_PORT = 0;
//    ReadUartCmd(res);
//    CLRWDT();
//    if(res != "accepted") return;
//    SendUartCmd("mac tx uncnf 9 123456789\r\n");
//    ReadUartCmd(res);
//    CLRWDT();
//    if(res != "ok") return;
//    LED_GREEN_PORT = 1;
//    __delay_ms(300);
//    LED_GREEN_PORT = 0;
//    __delay_ms(300);
//    LED_GREEN_PORT = 1;
//    __delay_ms(300);
//    LED_GREEN_PORT = 0;
//    CLRWDT();

    IOCBFbits.IOCBF6 = 0;
}