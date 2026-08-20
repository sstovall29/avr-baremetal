// Turn on an LED
#include <avr/io.h>
#include "gpio/gpio.h"


// For the AVR each GPIO port has 3 registers that define its pins, we will use pointers to them to allow our functions to set values
// For this example we will define an ledPin that will be wired to an LED
Pin ledPin = {
  &DDRB,
  &PORTB,
  &PINB,
  PB0
};

int main(void){

  // This is the custom GPIO Mode function used to define the direction register of the pin
  // By setting it to OUTPUT, the function is defining DDRB as output
  gpioMode(ledPin, OUTPUT);
  
  while(1){
    // We can use gpioWrite to set pins to high or low when they are in output mode
    // Here we set the LED to stay at HIGH or on forever
    gpioWrite(ledPin, HIGH);
  }

}

