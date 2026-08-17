// Create a driver to give a user abstracted use of the 7 segment display
#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <gpio.h>
#include <config.h>

// For the seven segment display we have each segment of the digit on PORTC
// constexpr byte A = 0;
// constexpr byte B = 1;
// constexpr byte C = 2;
// constexpr byte D = 3;
// constexpr byte E = 4;
// constexpr byte F = 5;
// constexpr byte G = 6;
// constexpr byte DP = 7;

const uint8_t segmentPins[] = {
    PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7
};

const uint8_t digits[] = {
    0b10111111,    // 0
    0b10000110,    // 1
    0b11011011,    // 2
    0b11001111,    // 3
    0b11100110,    // 4
    0b11101101,    // 5
    0b11111101,    // 6
    0b10000111,    // 7
    0b11111111,    // 8
    0b11100111,   // 9
};


void displayDigit(uint8_t num){
  uint8_t segmentBitMask = digits[num];
  for (int i=0; i<8; i++){
    if (segmentBitMask & (1 << i)){
      digitalWrite(segmentPins[i], HIGH);
    }
    else {
      digitalWrite(segmentPins[i], LOW);
    }
  }
}


void clearDisplay(void){
  // Turn off all enable digit pins to wipe the screen
  for (uint8_t i=0; i<4; i++){
    PORTA |= (1 << i);
  }
}

void digitOn(uint8_t digit){
  PORTA &= ~(1 << digit);
}
  

