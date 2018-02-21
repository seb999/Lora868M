#ifndef MISC_H
#define	MISC_H

void ReadUartCmd(char *Output, unsigned int length);
void SendUartCmd(char *cmd);

void __delay_sec(int);


#endif	/* MISC_H */

