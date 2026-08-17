#pragma once

#include <stdint.h>

// Return the system running time in millis
uint32_t millis(void);

void systemClockTick(void);

void timer3Setup(void);
