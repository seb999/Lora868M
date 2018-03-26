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
void EUART_GPS(void)
{
 
    //__delay_ms(250);
    bool state = (unsigned char)GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    //   RB5_SetDigitalOutput();
     
    RXPPSbits.RXPPS = 0x0C;   //RB4->EUSART:RX;
    RB5PPSbits.RB5PPS = 0x14;   //RB5->EUSART:TX;
    RC2PPSbits.RC2PPS = 0x13; 

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
    GIE = state;
    // Baud Rate = 9600; SP1BRGL 64; 
    SP1BRGL = 0x40;
    SP1BRGH = 0x03; 
    __delay_ms(250);
}

void EUART_LORA(void)
{
    
    //__delay_ms(250);
    bool state = (unsigned char)GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    //RC2_SetDigitalOutput();
    RXPPSbits.RXPPS = 0x0C;   //RB4->EUSART:RX;
    RC2PPSbits.RC2PPS = 0x14;   //RC2->EUSART:TX();
    RB5PPSbits.RB5PPS = 0x13;

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
    GIE = state;
     // Baud Rate = 9600; SP1BRGL 64; 
    SP1BRGL = 0x40;
    SP1BRGH = 0x03;
     // Baud Rate = 57600; SP1BRGL 138; 
//    SP1BRGL = 0x8A;
//    SP1BRGH = 0x00;
    __delay_ms(250);
}

//----------EUART EXTENTION METHODS----------
void ReadUartCmd(char *output)
{
    *output = "";
    int i = 0;
    char token;
    token = EUSART_Read();
    while(token!='\n'){
        output[i] = token;
        token = EUSART_Read();
        i++;
    }
}

void SendUartCmd(char *cmd)
{
  for(int i=0;cmd[i] !=  '\0' ;i++)
    EUSART_Write(cmd[i]);
}

//---------GPS COMMANDS---------
void InitGPS(){
    SendUartCmd("$PUBX,40,GSA,0,0,0,0\r\n");
    SendUartCmd("$PUBX,40,GSV,0,0,0,0\r\n");
    SendUartCmd("$PUBX,40,RMC,0,0,0,0\r\n");
    SendUartCmd("$PUBX,40,VTG,0,0,0,0\r\n");
    SendUartCmd("$PUBX,40,GGA,0,0,0,0\r\n");
    SendUartCmd("$PUBX,40,GLL,1,0,0,0,0\r\n");
}