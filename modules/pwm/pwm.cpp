// Set up timer4 to generate a PWM output for the piezo buzzer

#include <stdint.h>
#include <avr/io.h>
#include "gpio.h"
#include "config.h"



void pwmInit(){
  // Set the timer4 to toggle OC4A on compare match, PH3, pin 5
  TCCR4A |= (1 << COM4A0);
  TCCR4A &= ~(1 << COM4C1);
  TCCR4B |= (1 << WGM42);

  // Set Prescaler - 64
  TCCR4B |= (1 << CS41) | (1 << CS40);
  // Set the compare value
  OCR4A = 1000;
}

void pwmSetFrequency(uint16_t freq){
  // Convert freq to desired OCR4A for proper frequency
  OCR4A = (125000 / freq) - 1;
}

void pwmEnable(){
  TCCR4A |= (1 << COM4A0);
}

void pwmDisable(){
  TCCR4A &= ~(1 << COM4A0);
}
