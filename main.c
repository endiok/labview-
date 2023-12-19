#include <at89c51RC2.h>
#include "Delay.h"
#include "UART.h"
#include <INTRINS.h>
#include "Timer0.h"
#include "Nixie.h"
sbit led0=P2^0;
sbit led1=P2^1;
sbit led2=P2^2;
sbit led3=P2^3;
sbit led4=P2^4;
sbit led5=P2^5;
sbit led6=P2^6;
sbit led7=P2^7;
sbit Buzzer=P2^5;
sbit Motor=P1^0;

unsigned char Counter,Compare;
unsigned char Speed;
void main()
{
	UART_Init();
	Timer0_Init();
	while(1)
	{
		
	}
}
void Buzzer_Delay500us()
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}
void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		switch(SBUF)
		{
			case '0':led0=0;break;
			case '1':led0=1;break;
			case '2':led1=0;break;
			case '3':led1=1;break;
			case '4':led2=0;break;
			case '5':led2=1;break;
			case '6':led3=0;break;
			case '7':led3=1;break;
			
			case 'h':led4=0;break;
			case 'i':led4=1;break;
			case 'j':led5=0;break;
			case 'k':led5=1;break;
			case 'l':led6=0;break;
			case 'm':led6=1;break;
			case 'n':led7=0;break;
			case 'o':led7=1;break;
			
			case '8':Buzzer_Time(100);break;
			case 'a':Buzzer_Time(100);P2=0x00;break;
			case 'b':P2=0xFF;Compare=0;Nixie(1,0);break;
			case 'c':Nixie(1,0);Compare=0;break;
			case 'd':Nixie(1,1);Compare=25;break;
			case 'e':Nixie(1,2);Compare=50;break;
			case 'f':Nixie(1,3);Compare=75;break;
			case 'g':Nixie(1,4);Compare=100;break;
			default:break;
		}
		UART_SendByte(SBUF);
		RI=0;	
	}

}


void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;
	TH0 = 0xFF;
	Counter++;
	Counter%=100;
	if(Counter<Compare)
	{
		Motor=1;
	}
	else
	{
		Motor=0;
	}
}
