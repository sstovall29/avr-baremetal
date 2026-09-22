// Basic Serial string echo at 9600 baud
#include <avr/io.h>
#include "usart/usart.h"

void initUSART(void){
  // Baud to 9600
	UBRR0 = 103;
  // Enable transmit and receive
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
  // Set character size to 8 bits
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

int main(void){
	char serialCharacter;
	initUSART();

  const char message[] = "Hello World!\n";
  char message2[20];
  serialPrint(message);

	
	while(1){
    serialRead(message2, 20);
    serialPrint(message2);
	}
}
