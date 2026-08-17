// Create a class to abstract the buttons for the alarm clock
// Uses polling to simplfy defintions and setup
#include "config.h"
#include "button.h"
#include "gpio.h"

Button::Button(const Pin& pin)
  : pin(pin)
{
  gpioMode(pin, INPUT);
}

void Button::update(){
  currentState = gpioRead(pin);
}

bool Button::wasPressed(){
  if (currentState != previousState){
    previousState = currentState;
    if (currentState == LOW){
      return true;
    }
  }
  return false;
}

bool Button::isPressed(){
  if (currentState == LOW){
    return true;
  }
  else {
    return false;
  }
}