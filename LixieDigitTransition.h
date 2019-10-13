#ifndef LixieDigitTransition_h
#define LixieDigitTransition_h

#include "Arduino.h"
#include "LixieDigit.h"

class LixieDigitTransition
{
  public:
    LixieDigitTransition();
    void transitionTo(LixieDigit* digits[10], int number, uint32_t color);
    void tick();
  private:
    uint32_t _color;
    int _from;
    int _to;
    unsigned long _lastTick;
    LixieDigit** _digits;
    int tickLength;
};

#endif