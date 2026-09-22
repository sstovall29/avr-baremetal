// Control on a print statement with a button
#include <avr/io.h>
#include "gpio/gpio.h"
#include "usart/usart.h"
#include "button/button.h"


// This pin will be connected to a momentary push button to allow us to sense changes in input signal
Pin buttonPin = {
  &DDRB,
  &PORTB,
  &PINB,
  PB3
};

bool buttonPressed = false;

Button printButton(buttonPin);

int main(void){
  // Set the buttonPin as an input, we will use it to read in signal changes
  // The function will automatically set it to INPUT_PULLUP with the PORT register
  gpioMode(buttonPin, INPUT);
  initUSART();
  const char message[] = "Button was pressed\n";
  const char message2[] = "Button not pressed\n";
  
  while(1){
    // Pull in the state on the buttonPin
    printButton.update();

    if (printButton.wasPressed()){
      serialPrint(message);
    }
  }

}

