/*
 * GccApplication3.c
 *
 * Created: 6/12/2022 12:38:03 PM
 * Author : Sameen
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>


int main(void)
{
	unsigned char c=0x0F, in =0;
	
	DDRA = 0x00;
	DDRB = 0XFF;
	

    while (1) 
    {	
		
		in = PINA;	
		PORTB = c<<4;
		if (in & (1<<PINA2)) {
			c--;	
			_delay_ms(1000);
		}

    }
}

