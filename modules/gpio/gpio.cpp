#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"




void gpioMode(const Pin& pin, uint8_t mode)
{
    if(mode == OUTPUT)
    {
        *pin.ddr |= (1 << pin.bit);
    }
    else
    {
        *pin.ddr &= ~(1 << pin.bit);
        *pin.port |= (1 << pin.bit);
    }
}

void gpioWrite(const Pin& pin, uint8_t state){
  if (state){
    *pin.port |= (1 << pin.bit);
  }
  else {
    *pin.port &= ~(1 << pin.bit);
  }
}

bool gpioRead(const Pin& pin){
  if (*pin.pin & (1 << pin.bit)){
    return true;
  }
  else {
    return false;
  }
}


void pinMode(uint8_t pin, uint8_t mode){
  if (mode){
    // Set as output
    DDRC |= (1 << pin);
  }
  else {
    // Set as input
    DDRC &= ~(1 << pin);
  }
}

void digitalWrite(uint8_t pin, uint8_t mode){
  if (mode){
    // Set output to high
    PORTC |= (1 << pin);
  }
  else {
    // Set output to low
    PORTC &= ~(1 << pin);
  }
}

bool digitalRead(uint8_t pin){
  if(PINC & (1 << pin))
    {
        return true;
    }
    else
    {
        return false;
    }
}