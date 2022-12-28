#include<avr/io.h>
#include<stdbool.h>
#include<util/delay.h>
int main(void)
{
	int X,Y,Z;
	bool F;

	DDRB	|=0b11111111;
	PORTD=0xFC;;
	DDRB=0b00100000;
	
	while(1)
	{
		X=(PIND &(1<<PIND2))==(1<< PIND2);
		Y=(PIND &(1<<PIND3))==(1<< PIND3);
		Z=(PIND &(1<<PIND4))==(1<< PIND4);

		F=Y||(X&&!Z);

		PORTB=(F<<5);

	}
	return 0;
}
