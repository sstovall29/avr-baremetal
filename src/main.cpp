// Blink an LED

#include <avr/io.h>


int main(void){
  // Configure the pins
  // I want to flash pin 8 on the mega which is PH5

  // Set that pin in Port H to output
  DDRH |= (1<<PH5);


  while(1){
    // Drive PH5 HIGH
    PORTH |= (1 << PH5);

    // Wait 1 second, will need to figure timer

    // Write PH5 LOW
    PORTH &= ~(1 << PH5);

    // Wait 1 second

  }

}