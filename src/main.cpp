// Blink an LED

#include <avr/io.h>
#include <util/delay.h>

void delay();

int main(void){
  // Configure the pins
  // I want to flash pin 8 on the mega which is PH5

  // Set that pin in Port H to output
  DDRH |= (1<<PH5);


  while(1){
    // Drive PH5 HIGH
    PORTH |= (1 << PH5);

    // Wait 1 second, will need to figure timer
    //delay();
    _delay_ms(1000);
    // Write PH5 LOW
    PORTH &= ~(1 << PH5);

    // Wait 1 second
    //delay();
    _delay_ms(1000);
  }

}

void delay()
{
  // making he variable volatile keeps the compiler from opimizing it away
    volatile long count = 0;

    while(count < 100000)
    {
        count++;
    }
}