#ifndef LixieDigitTransition_h
#define LixieDigitTransition_h

#include "Arduino.h"
#include "LixieDigit.h"

class LixieDigitTransition
{
  public:
    LixieDigitTransition();
    void transitionTo(LixieDigit* digits[10], int number, uint32_t color);
  private:
    uint32_t _color;
    LixieDigit* _digits[10];
};

#endif