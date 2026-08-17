#pragma once

#include <stdint.h>

void pwmInit();

void pwmSetFrequency(uint16_t freq);

void pwmEnable();

void pwmDisable();