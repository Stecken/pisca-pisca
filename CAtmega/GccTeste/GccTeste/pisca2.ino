
void setup(){
  	DDRD = 0b11111100;
  	DDRB = 0b00000000;
  	PORTB = 0b00000001;
}

void loop(){	
  int pin = 0b10101000; 
  int *local = &pin;
  tester(*local);
}

void tester(int pin){
  PORTD = 0b00000000;
  while(PINB == 0b00000000){
  	pin ^= 0b11111100;
    PORTD = pin;
    delay(1000); 
   }
}