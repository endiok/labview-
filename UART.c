#include <at89c51RC2.h>

void UART_Init()
{
	PCON |= 0x80;
	SCON = 0x50;
	AUXR &= 0xBF;
	AUXR &= 0xFE;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TL1 = 0xFA;	
	TH1 = 0xFA;	
	ET1 = 0;
	TR1 = 1;
	EA=1;
	ES=1;
	
}

void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}
