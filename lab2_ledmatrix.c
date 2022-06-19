/*
 * GccApplication6.c
 *
 * Created: 6/19/2022 2:29:28 PM
 * Author : Sameen
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

void translate_rows_down(char pattern[]) {
	int r = 7;
	char last_row_bits = pattern[r];
	for (r = 7; r > 0; r--) {
		pattern[r] = pattern[r-1];
	}
	pattern[0] = last_row_bits;
}


int main(void)
{
	DDRA = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x00;
	
	char row_bit = 0b00000001;
	char row_bit_pos = 0;
    /* Replace with your application code */
	char pattern[] = {0xff,0x80,0x80,0xfc,0x80,0x80,0x80,0xff};
	
	int iteration = 0;
	int translate_interval = 100;
	
	int is_translate = 0;
    while (1) 
    {
		if (iteration % translate_interval == 0 && is_translate != 0) {
			translate_rows_down(pattern);
		}
		
		_delay_ms(2);
		if (PIND){
			if(is_translate == 0)
				is_translate = 1;
			else
				is_translate = 0;
				
		}
		
		
		
		PORTA = row_bit;
		PORTC = ~pattern[row_bit_pos];
		
	
		row_bit <<= 1;
		row_bit_pos++;
		
		if (row_bit == 0) {
			row_bit = 0b00000001;
			row_bit_pos = 0;
		}
		
		iteration++;
		
    }
}

