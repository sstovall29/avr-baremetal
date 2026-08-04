#pragma once

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t value);
bool digitalRead(uint8_t pin);