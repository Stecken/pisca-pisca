/*
 * pisca.c
 *
 * Created: 23/08/2020 19:42:18
 *  Author: T-Gamer
 */ 

#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void){
	DDRD = 0b11111100;
	DDRB = 0b00000000;
	PORTB = 0b00000001;
	short int pin = 0b10101000;
	while(1){
		tester(&pin);
	}
}

void tester(short int *pin){
	while(PINB == 0b00000000){
		*pin ^= 0b11111100;
		PORTD = *pin;
		_delay_ms(1000);
	}
}

