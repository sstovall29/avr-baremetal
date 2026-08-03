// Blink an LED
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect)
{
    PORTH ^= (1 << PH5);
}

int main(void){
  // Configure the pins
  // I want to blink pin 8 on the mega which is PH5

  // Set that pin in Port H to output
  DDRH |= (1<<PH5);

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


  while(1){

  }

}
