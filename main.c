#include "mcc_generated_files/mcc.h"
#include "misc.h"
#include <stdbool.h>
#include <__null.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    SWDTEN = 1;
    // initialize the device
    SYSTEM_Initialize();

    EUART_GPS();
    InitGPS();
   // EUART_57600();
    
    GIE = 1;
    IOCIE = 1;

    //TImer0 interruption Off
    INTCONbits.TMR0IE = 0;
    while (1)
    {    
        CLRWDT();  
    }
}

char * NormalizeHex(char *hex){
    char norm[20]="";
    int i;
    for (i = 0; i < hex[i]; i++) {};
    if(i==1) strcpy(norm, "000");
    if(i==2) strcpy(norm, "00");
    if(i==3) strcpy(norm, "0");
    strcat(norm, hex);
    return norm;
}

//----INTERRUPTON METHOD-----
inter_sw1()
{        
    CLRWDT();
    char lora[20]="";
    char gps[40]="";
    char * token;
    char * latitude;
    char * latitudeDec;
    char * longitude;
    char * longitudeDec;
   
    //wait that user release button
    while(SW1_PORT == 0);
    
     //Read GPS position TESTED
    EUART_GPS();
    SendUartCmd("$PUBX,40,GLL,1,1,0,0,0\r\n"); //GPS ON
    ReadUartCmd(gps);
    SendUartCmd("$PUBX,40,GLL,1,0,0,0,0\r\n");// GPS OFF
    token = strtok (gps," ,");//READ root code
    if(strcmp(token,"$GNGLL") != 0) return;
   
    latitude = strtok (NULL,"."); //Latitude
    latitudeDec = strtok (NULL,","); //Latitude decimal .
    
    token = strtok (NULL,","); //READ 'N' or exit
    if(strcmp(token,"N") != 0){ 
        SendUartCmd("Not good");
        return;
    }
    
    longitude = strtok (NULL,"."); //Longitude 
    longitudeDec = strtok (NULL,","); //Longitude decimal
    
    SendUartCmd(latitude);
    SendUartCmd("\r\n");
    SendUartCmd(latitudeDec);
    SendUartCmd("\r\n");
    SendUartCmd(longitude);
    SendUartCmd("\r\n");
    SendUartCmd(longitudeDec);
    SendUartCmd("\r\n");
    CLRWDT();
    
    //Convert to hex
    char hex[4]="";
    char result[16]="";
    sprintf(hex, "%X", atoi(latitude));
    strcat(result,NormalizeHex(hex)); 
    sprintf(hex, "%X", atoi(latitudeDec));
    strcat(result,NormalizeHex(hex)); 
    sprintf(hex, "%X", atoi(longitude));
    strcat(result,NormalizeHex(hex)); 
    sprintf(hex, "%X", atoi(longitudeDec));
    strcat(result,NormalizeHex(hex)); 
    SendUartCmd(result);
    CLRWDT();
     
    //Look for LORA NETWORK
//      EUART_LORA();
//      SendUartCmd("sys reset\r\n"); 
//      ReadUartCmd(lora);
//      SendUartCmd(lora);
// 
//    SendUartCmd("mac join otaa\r\n");
//    ReadUartCmd(lora);  //read ok 
//    ReadUartCmd(lora);  //read denied or
//    
//    token = strtok(lora," \r\n");
//    if(strcmp(token,"accepted") != 0){
//        SendUartCmd("not good\n");
//        LED_RED_PORT = 1;
//        __delay_ms(100);
//        LED_RED_PORT = 0;
//        __delay_ms(100);
//        LED_RED_PORT = 1;
//        __delay_ms(100);
//        LED_RED_PORT = 0;
//        IOCBFbits.IOCBF6 = 0;
//        return;
//    }
//    else{
//        LED_GREEN_PORT = 1;
//        __delay_ms(100);
//        LED_GREEN_PORT = 0;
//        __delay_ms(100);
//        LED_GREEN_PORT = 1;
//        __delay_ms(100);
//        LED_GREEN_PORT = 0;
//         __delay_ms(100);
//        LED_GREEN_PORT = 1;
//        __delay_ms(100);
//        LED_GREEN_PORT = 0;
//    }
//    CLRWDT();
//   
//    //send GPS position
 //   SendUartCmd("mac tx uncnf 9 592028337\r\n"); first try 
    //SendUartCmd("mac tx uncnf 9 234808?42\r\n"); second try with hex
    
//    ReadUartCmd(lora);  //read ok 
//    ReadUartCmd(lora);   //read mac_tx_ok or not
//    token = strtok(lora," \r\n");
//    if(strcmp(token,"mac_tx_ok") != 0){
//    SendUartCmd("send data failed");
//        LED_RED_PORT = 1;
//        __delay_ms(300);
//        LED_RED_PORT = 0;
//        __delay_ms(300);
//        LED_RED_PORT = 1;
//        __delay_ms(300);
//        LED_RED_PORT = 0;
//        IOCBFbits.IOCBF6 = 0;
//        return;
//    }
//    else{
//        SendUartCmd("GPS data sent\n");
//        LED_GREEN_PORT = 1;
//        __delay_ms(700);
//        LED_GREEN_PORT = 0;
//        __delay_ms(700);
//        LED_GREEN_PORT = 1;
//        __delay_ms(700);
//        LED_GREEN_PORT = 0;
//    }

    IOCBFbits.IOCBF6 = 0;
}


