// Basic Serial echo at 9600 baud
#include <avr/io.h>

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

	while(1){
    // Echo
	  // If a bit is received
    if (UCSR0A & (1 << RXC0)){
      serialCharacter = UDR0;

      // Wait for the transmit buffer to be ready
      while (!(UCSR0A & (1 << UDRE0))){
          // Wait
      }
    
      // Echo the character
      UDR0 = serialCharacter;
      
    }
	
	}
}
