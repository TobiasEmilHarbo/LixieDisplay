
#ifndef LixieDigitTransistion_h
#define LixieDigitTransistion_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"
#include "LixieDigitPosition.h"

class LixieDigitTransistion
{
  public:
    LixieDigitTransistion(uint32_t color);
  private:
    uint32_t _color;
};

#endif