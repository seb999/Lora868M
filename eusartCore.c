#include "eusartCore.h"
#include "mcc_generated_files/eusart.h"

void ReadUartCmd(char *Output, unsigned int length)
{
    Output[0] = EUSART_Read();
    for(int i=1;i<length;i++)
    {
        Output[i] = EUSART_Read();
        if(Output[i-1]=='O' && Output[i]=='K')
            break;
    }
}

void SendUartCmd(char *cmd)
{
  for(int i=0;cmd[i] !=  '\0' ;i++)
    EUSART_Write(cmd[i]);
}