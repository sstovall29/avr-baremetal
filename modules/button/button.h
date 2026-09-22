#pragma once

#include <stdint.h>
#include "../gpio/gpio.h"

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

class Button
{
public:
  Button(const Pin& pin);

  void update();

  bool wasPressed();

  bool isPressed();

private:
  Pin pin;

  bool currentState;
  bool previousState;
  bool pressedEvent;

};