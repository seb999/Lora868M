#include "misc.h"

void __delay_sec(int n){
    while(n--) __delay_ms(1000); 
}

void Bip(int n, int t){
    for(int i=0;i<n;i++){
        for (int j=0;j<t;j++){
                //BUZZER = 1;
                __delay_us(130);
                //BUZZER = 0;
                __delay_us(130);
        }
        __delay_ms(20);
    }
   // BUZZER = 1;
}