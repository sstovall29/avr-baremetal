#include <stdint.h>
#include <avr/io.h>
#include "system_time.h"


volatile uint32_t systemMillis = 0;

// Timer 3 is being used to triger an ISR every 1 ms that will increment the variable

void timer3Setup(void){
  // Set the timer to CTC Mode, function as a 1 ms tick
  TCCR3A = 0;
  TCCR3B |= (1 << WGM32);
  // Set Prescaler - 64
  TCCR3B |= (1 << CS31) | (1 << CS30);
  // Set the compare value
  OCR3A = 250;
  // Enable the interupt
  TIMSK3 |= (1 << OCIE1A);
}

uint32_t millis(void){
  return systemMillis;
}

void systemClockTick(void){
  systemMillis++;
}

