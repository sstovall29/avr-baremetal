#pragma once

#include <stdint.h>
#include "gpio.h"

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