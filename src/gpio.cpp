#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

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