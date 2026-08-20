// Blink an LED
#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio/gpio.h"


volatile bool ledState = false;

ISR(TIMER1_COMPA_vect)
{
    ledState = !ledState;
}

void timerSetup(){
  // Set the timer to CTC Mode
  TCCR1A = 0;
  TCCR1B |= (1 << WGM12);
  // Set Prescaler - 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // Set the compare value, will me roughly 1 sec
  OCR1A = 15624;
  // Enable the interupt
  TIMSK1 |= (1 << OCIE1A);
  // Enable golbal inerrupts, tells the CPU to listen for trigger
  sei();
}


Pin ledPin = {
  &DDRB,
  &PORTB,
  &PINB,
  PB0
};

int main(void){
  timerSetup();

  gpioMode(ledPin, OUTPUT);
  

  while(1){
    gpioWrite(ledPin, ledState);
  }

}

