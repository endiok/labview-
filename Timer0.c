#include <at89c51RC2.h>

void Timer0_Init(void)
{
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0x9C;
	TH0 = 0xFF;
	TF0 = 0;
	TR0 = 1;
	ET0=1;
	EA=1;
}
