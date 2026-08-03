// Blink an LED
#include <avr/io.h>
#include <avr/interrupt.h>

volatile bool ledState = true;

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

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t mode);



int main(void){
  timerSetup();
  // Configure the pins
  // I have 8 leds connected to every pin in PORTC
  pinMode(2, 1);
  

  while(1){
    digitalWrite(2, ledState);
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