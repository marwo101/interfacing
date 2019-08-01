/*
 * 7segment switch.c
 *
 * Created: 7/27/2019 12:25:46 PM
 * Author : marwan
 */ 

#include <avr/io.h>
#define F_CPU   16000000UL
#include <util/delay.h>

int main(void)
{unsigned char u8ct = 0 ;
unsigned char u7ct = 0 ;

	PORTC = 0 ;
	DDRC = 0;
	DDRC |= (1<< DDC4) | (1<< DDC5) | (1<< DDC6) | (1<< DDC7) | (1<< DDC2) |(1<<DDC3);
    /* Replace with your application code */
    while (1) 
    {
		if (u8ct <=9){
			PORTC = (1 << PINC2);
			PORTC |= (u8ct << 4);
			_delay_ms(500);
			u8ct++;
			PORTC = (1<< PINC2) | (1<<PINC3);
			

		}
		else if(u7ct <=9){
			PORTC |= (u7ct << 4);
			_delay_ms(5000);
			u7ct++;
			PORTC = (1<< PINC2) |(1<<PINC3);
		}
		else 
		{
			PORTC |=0; 
			u8ct = 0;
		}
    }
}

