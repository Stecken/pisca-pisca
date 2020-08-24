/*
 * GccTeste.c
 *
 * Created: 23/08/2020 15:02:48
 * Author : Stecken
 */ 
#define F_CPU 1600000UL
#include <util/delay.h>



int main(void){
	short int valorDd = 0b11111100;
	short int valorDb = 0b00000000;
	short int valorPb = 0b00000001;
	short int *ddrd = 0x2A;
	short int *ddrb = 0x24;
	short int *portb = 0x25;
	*ddrd = valorDd;
	*ddrb = valorDb;
	*portb = valorPb;
	short int pin = 0b10101000;
    while(1){
		tester(&pin);
    }
}

void tester(short int *pin){
	short int *pinb = 0x23;
	short int *portd = 0x2B;
	while(*pinb == 0b00000000){
		*pin ^= 0b11111100;
		*portd= *pin;
		_delay_ms(1000);
	}
}