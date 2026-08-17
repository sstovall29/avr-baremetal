// Module for reading changes in an encoder

#include "encoder.h"
#include <avr/io.h>
#include <avr/interrupt.h>

static volatile int16_t encoder_transition_count = 0;
static volatile uint8_t lastEncoderState = 0b11;
static volatile int16_t steps = 0;

static void updateEncoder();
void convertCount(void);

ISR(INT1_vect)
{
    updateEncoder();
}

ISR(INT2_vect)
{
    updateEncoder();
}

void encoder_init()
{
  EIMSK |= (1 << INT1) | (1 << INT2);
  EICRA |= (1 << ISC20) | (1 << ISC10);
  EICRA &= ~((1 << ISC21) | ( 1 << ISC11));
  
  DDRD &= ~((1 << PD2) | (1 << PD1));
  PORTD |= (1 << PD2) | (1 << PD1);
  lastEncoderState = (PIND >> 1) & 0x03;
}


void updateEncoder(void){
  uint8_t current = (PIND >> 1) & 0x03;

  if((lastEncoderState == 0b00 && current == 0b01) ||
      (lastEncoderState == 0b01 && current == 0b11) ||
      (lastEncoderState == 0b11 && current == 0b10) ||
      (lastEncoderState == 0b10 && current == 0b00))
  {
      encoder_transition_count++;
  }

  else if((lastEncoderState == 0b00 && current == 0b10) ||
          (lastEncoderState == 0b10 && current == 0b11) ||
          (lastEncoderState == 0b11 && current == 0b01) ||
          (lastEncoderState == 0b01 && current == 0b00))
  {
      encoder_transition_count--;
  }
  lastEncoderState = current;
  convertCount();
}

void convertCount(void){
  if (encoder_transition_count >= 4)
    {
        steps++;
        encoder_transition_count = 0;
    }
  if (encoder_transition_count <= -4)
  {
      steps--;
      encoder_transition_count = 0;
  }
}

void encoder_wrap(int16_t val, int16_t low, int16_t high) {
  if (val < low){
    encoder_set(high);
  }
  if (val > high){
    encoder_set(low);
  }
}

int16_t encoder_getCount(void){
  return steps;
}

void encoder_reset(){
  steps = 0;
  encoder_transition_count = 0;
}

void encoder_set(int16_t count){
  steps = count;
}