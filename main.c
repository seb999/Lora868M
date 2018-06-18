#include "mcc_generated_files/mcc.h"
#include "misc.h"
#include <stdbool.h>
#include <__null.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool ReadGPS();
bool ConnectLora();
        
char lora[40]="";
char gps[40]="";
char hex[4]="";
char gpsHex[16]="";
char * token;
char * latitude;
char * latitudeDec;
char * longitude;
char * longitudeDec;
    
void main(void)
{
    SWDTEN = 1;
    SYSTEM_Initialize();
   
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
    
    //wait that user release button
    while(SW1_PORT == 0);
    
    //Read GPS position or exit method
    EUART_GPS();
    if(!ReadGPS()) return;
    
    CLRWDT();
     
    //Look for LORA NETWORK
    EUART_LORA();
    ConnectLora();
    
    IOCBFbits.IOCBF6 = 0;
}

bool ReadGPS(){  
    SendUartCmd("$PUBX,40,GLL,1,1,0,0,0\r\n"); //GPS ON
    ReadUartCmd(gps);
    SendUartCmd("$PUBX,40,GLL,1,0,0,0,0\r\n");// GPS OFF
    token = strtok (gps," ,");//READ root code
    if(strcmp(token,"$GNGLL") != 0){ 
        blinkRed();
        IOCBFbits.IOCBF6 = 0;
        return false;
    }
   
    latitude = strtok (NULL,"."); //Latitude
    latitudeDec = strtok (NULL,","); //Latitude decimal .
    
    token = strtok (NULL,","); //READ 'N' or exit
    if(strcmp(token,"N") != 0){
        blinkRed();
        IOCBFbits.IOCBF6 = 0;
        return false;
    }
    
    longitude = strtok (NULL,"."); //Longitude 
    longitudeDec = strtok (NULL,","); //Longitude decimal
    
    //Convert to hex and concatenate
    strcpy(gpsHex,"");
    sprintf(hex, "%X", atoi(latitude));
    strcat(gpsHex,NormalizeHex(hex)); 
    sprintf(hex, "%X", atoi(latitudeDec));
    strcat(gpsHex,NormalizeHex(hex)); 
    sprintf(hex, "%X", atoi(longitude));
    strcat(gpsHex,NormalizeHex(hex)); 
    sprintf(hex, "%X", atoi(longitudeDec));
    strcat(gpsHex,NormalizeHex(hex)); 
    return true;
}

bool ConnectLora(){
    LORA_RESET_SetLow();
    __delay_ms(200);
    LORA_RESET_SetHigh();
     __delay_ms(200);
    SendUartCmd("sys reset\r\n"); 
    ReadUartCmd(lora);  //read serial number
    
    SendUartCmd("mac join otaa\r\n");
    ReadUartCmd(lora);  //read ok
    ReadUartCmd(lora);  //read denied or accepted
   
    token = strtok(lora," \r\n");
    if(strcmp(token,"accepted") != 0){
        blinkRed();
        IOCBFbits.IOCBF6 = 0;
        return false;
    }
    CLRWDT();   
    //send GPS position
    char str[50];
    strcpy(str,"mac tx uncnf 9 ");
    strcat(str, gpsHex);
    strcat(str, "\r\n");
    SendUartCmd(str);
    ReadUartCmd(lora);  //read ok 
    ReadUartCmd(lora);   //read mac_tx_ok or not
    
    token = strtok(lora," \r\n");
    if(strcmp(token,"mac_tx_ok") != 0){
    SendUartCmd("send data failed");
        blinkRed();
        IOCBFbits.IOCBF6 = 0;
        return false;
    }
    blinkGreen();
    SendUartCmd("GPS data sent\n"); 
    return true;
}