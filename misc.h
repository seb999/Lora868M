#ifndef MISC_H
#define	MISC_H

void ReadUartCmd(char *Output);
void SendUartCmd(char *cmd);
void ReadUartCmdModified(char *Output);
void EUART_LORA(void);
void InitGPS(void);

void __delay_sec(int);


#endif	/* MISC_H */

