// Control on an LED with a button
// Basic input controls basic output
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

// This pin will be connected to a momentary push button to allow us to sense changes in input signal
Pin buttonPin = {
  &DDRB,
  &PORTB,
  &PINB,
  PB3
};

bool buttonPressed = false;

int main(void){

  // This is the custom GPIO Mode function used to define the direction register of the pin
  // By setting it to OUTPUT, the function is defining DDRB as output
  gpioMode(ledPin, OUTPUT);

  // Set the buttonPin as an input, we will use it to read in signal changes
  // The function will automatically set it to INPUT_PULLUP with the PORT register
  gpioMode(buttonPin, INPUT);
  
  while(1){
    // Pull in the state on the buttonPin
    // The pin is input pullup so it rests at HIGH, flip the state of the bit to go HIGH when pressed
    // Turn the LED on when the button is pressed 
    buttonPressed = !gpioRead(buttonPin);

    if (buttonPressed){
      gpioWrite(ledPin, HIGH);
    }
    else {
      gpioWrite(ledPin, LOW);
    }
    
  }

}

