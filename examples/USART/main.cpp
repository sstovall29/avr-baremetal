// Basic Serial string echo at 9600 baud
#include <avr/io.h>
#include "usart/usart.h"

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
