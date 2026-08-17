#pragma once

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

struct Pin
{
    volatile uint8_t* ddr;
    volatile uint8_t* port;
    volatile uint8_t* pin;
    uint8_t bit;
};

void gpioMode(const Pin& pin, uint8_t mode);
void gpioWrite(const Pin& pin, uint8_t state);
bool gpioRead(const Pin& pin);

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t value);
bool digitalRead(uint8_t pin);