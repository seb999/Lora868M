#include "mcc_generated_files/mcc.h"
#include "misc.h"
#include "adxl.h"
#include <stdbool.h>
#include <__null.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

bool ReadGPS();
bool LoraSendData();
bool LoraCheckNetwork();
bool LoraDebug();

bool isGpsAccess = false;
bool isLoraAccess = false;
bool isMotionStopped = false;
        
char lora[40]="";
char gps[40]="";
char hex[10]="";
char gpsHex[30]="";

char * token;
char * latitude;
char * latitudeDec;
char * longitude;
char * longitudeDec;

int counter = 0;
int counterMotion = 0;
int debugger = 0;
    
void main(void)
{
    SYSTEM_Initialize();
    GIE = 0;
    
    SWDTEN = 1;
    CLRWDT();  
    
    ADXL_Init();
    EUART_GPS();
    InitGPS();
    
    EUART_LORA(); //remove this one after debug
     __delay_ms(100);  
    //Change PIC Baud Rate to 57600;
    SP1BRGL = 0x8A;
    SP1BRGH = 0x00;
    __delay_ms(100);  
    
    GIE = 1;
    IOCIE = 1;

    //TImer0 interruption Off
    //INTCONbits.TMR0IE = 0;
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
    
    //Look for LORA NETWORK
    EUART_LORA();
    LoraSendData();
}

inter_adxl()
{
    blinkRed(1);
    
    //Routine 1
//    EUART_GPS();
//    if(!ReadGPS()) return;
//    
//    //Look for LORA NETWORK
//    EUART_LORA();
//    LoraSendData();
    
    //Routine 2
//    if(!isMotionStopped){
//        EUART_LORA();
//        if(!LoraCheckNetwork()) return;
//
//        EUART_GPS();
//        if(!ReadGPS()) return;
//
//        EUART_LORA();
//        LoraSendData();
//    }
}

inter_timer()
{
    counter++;
    if(counter==400){
        blinkRed(1);
        counter = 0;
        debugger++;
        
        if(debugger == 3){
            debugger=0;
            
            EUART_GPS();
            if(!ReadGPS()) return;
            
            EUART_LORA();
            for(int i=0;i<=5;i++)
            {
                //LoraDebug();
                if(LoraSendData()) break;
            }
            
            //LoraDebug();
            
        }
        
        //Future
//        if(counterMotion == 20){
//            isMotionStopped = false;
//            counterMotion = 0;
//        }
        //remove after debug used to setup the device
//        LORA_RESET_SetLow();
//        __delay_ms(200);
//        LORA_RESET_SetHigh();
//        __delay_ms(200);
//        SendUartCmd("mac set appeui 70B3D57ED0007651\r\n"); 
//        ReadUartCmd(lora);
//        SendUartCmd("mac set appkey 9FA338A47B91F3690A48DAFEC7CEF807\r\n"); 
//        ReadUartCmd(lora);
//        SendUartCmd("mac save\r\n"); 
//        ReadUartCmd(lora);
    } 
}

bool LoraCheckNetwork(){
    LORA_RESET_SetLow();
    __delay_ms(200);
    LORA_RESET_SetHigh();
     __delay_ms(200);
    SendUartCmd("sys reset\r\n"); 
    ReadUartCmd(lora);  //read serial number
    
    SendUartCmd("mac join otaa\r\n");
    ReadUartCmd(lora);  //read ok
    ReadUartCmd(lora);  //read denied/accepted
   
    token = strtok(lora," \r\n");
    if(strcmp(token,"accepted") != 0){
        blinkOrange(1);
        isLoraAccess = false;
        return false;
    }
    return true;
}

bool ReadGPS()
{  
    CLRWDT();
    //LED_ORANGE_SetHigh();
    SendUartCmd("$PUBX,40,GLL,1,1,0,0,0\r\n"); //GPS ON
    ReadUartCmd(gps);
    ReadUartCmd(gps);//we read twice if empty string
    SendUartCmd("$PUBX,40,GLL,1,0,0,0,0\r\n");// GPS OFF
    //LED_ORANGE_SetLow();
    
    token = strtok (gps," ,");//READ root code
    if(strcmp(token,"$GPGLL") != 0){ 
        isGpsAccess = false;
        return false;
    }
   
    latitude = strtok (NULL,"."); //Latitude
    latitudeDec = strtok (NULL,","); //Latitude decimal .
    
    token = strtok (NULL,","); //READ 'N' or exit
    if(strcmp(token,"N") != 0){
        isGpsAccess = false;
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
    SendUartCmd(gpsHex);
    //blinkGreen(2);
    isGpsAccess = true;
    return true;
}

bool LoraSendData(){
    LORA_RESET_SetLow();
    __delay_ms(200);
    LORA_RESET_SetHigh();
     __delay_ms(200);
    SendUartCmd("sys reset\r\n"); 
    ReadUartCmd(lora);  //read serial number
    
    CLRWDT();//watch dog can reset before end of routine
    SendUartCmd("mac set pwridx 1\r\n"); //Set power
    ReadUartCmd(lora);  //read ok
    
    SendUartCmd("mac join otaa\r\n");
    ReadUartCmd(lora);  //read ok
    ReadUartCmd(lora);  //read denied or accepted
   
    token = strtok(lora," \r\n");
    if(strcmp(token,"accepted") != 0){
        blinkRed(2);
        isLoraAccess = false;
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
        blinkRed(2);
        isLoraAccess = false;
        return false;
    }
    blinkGreen(3);
    isLoraAccess = true;
    isMotionStopped = true;
    counterMotion = 0;
    return true;
}

//to be deleted, used for debugging
bool LoraDebug(){
    LORA_RESET_SetLow();
    __delay_ms(200);
    LORA_RESET_SetHigh();
     __delay_ms(200);
    SendUartCmd("sys reset\r\n"); 
    ReadUartCmd(lora);  //read serial number
    
    CLRWDT();//watch dog can reset before end of routine
    SendUartCmd("mac join otaa\r\n");
    ReadUartCmd(lora);  //read ok
    ReadUartCmd(lora);  //read denied or accepted
   
    token = strtok(lora," \r\n");
    if(strcmp(token,"accepted") != 0){
        blinkRed(2);
        return false;
    }
    CLRWDT();   
    
    SendUartCmd("mac tx uncnf 9 17206EB1070C01E9\r\n");
    ReadUartCmd(lora);  //read ok 
    ReadUartCmd(lora);   //read mac_tx_ok or not
    
    token = strtok(lora," \r\n");
    if(strcmp(token,"mac_tx_ok") != 0){
        SendUartCmd("send data failed");
        blinkRed(2);
        return false;
    }
    blinkGreen(3);
    SendUartCmd("GPS data sent\n"); 
    return true;
}