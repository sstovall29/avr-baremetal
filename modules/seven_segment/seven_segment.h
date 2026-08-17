#pragma once

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

void displayDigit(uint8_t num);
void clearDisplay(void);
void digitOn(uint8_t digit);