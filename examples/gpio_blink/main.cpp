// Blink an LED
#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio.h"


#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

volatile bool ledState = false;
constexpr uint8_t PORT_WIDTH = 5;

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
  // Set the compare value
  OCR1A = 15624;
  // Enable the interupt
  TIMSK1 |= (1 << OCIE1A);
  // Enable golbal inerrupts, tells the CPU to listen for trigger
  sei();
}

int main(void){
  timerSetup();
  // Configure the pins
  // I have 8 leds connected to every pin in PORTC
  for (int i=0; i<PORT_WIDTH; i++){
    pinMode(i, OUTPUT);
  }
  

  while(1){
    for (int i=0; i<PORT_WIDTH; i++){
      digitalWrite(i, ledState);
    }
  }

}

