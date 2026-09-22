#include <avr/io.h>
#include "usart.h"

void initUSART(void){
  // Baud to 9600
	UBRR0 = 103;
  // Enable transmit and receive
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
  // Set character size to 8 bits
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void serialPrint(const char message[]){
    for (int i = 0; message[i] != '\0'; i++){
    while (!(UCSR0A & (1 << UDRE0))){
          // Wait
    }
    UDR0 = message[i];
  }
}

void serialRead(char message[], int size){
  int i = 0;

  while(i < size - 1){
    while (!(UCSR0A & (1 << RXC0))){
          // Wait for a bit to be received
    }

    char serialCharacter = UDR0;
    if (serialCharacter == '\r' || serialCharacter == '\n') {
      break;
    }

    message[i] = serialCharacter;
    i++;
  }
  message[i] = '\0';
}