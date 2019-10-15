#ifndef LixieDigitTransition_h
#define LixieDigitTransition_h

#include "Arduino.h"
#include "LixieDigit.h"

class LixieDigitTransition
{
  public:
    LixieDigitTransition();
    virtual void transitionTo(LixieDigit* digits[10], int number, uint32_t color);
    virtual void tick();
  protected:
    uint32_t _color;
    int _number;
    LixieDigit** _digits;
};

#endif