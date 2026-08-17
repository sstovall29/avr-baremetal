#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>

void encoder_init();

int16_t encoder_getCount();

void encoder_reset();

void encoder_set(int16_t count);

void encoder_wrap(int16_t val, int16_t low, int16_t high);

#endif