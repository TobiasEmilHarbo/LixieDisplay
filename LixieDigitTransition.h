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
    bool isDirty();
  protected:
    LixieDigit** _digits;
    int _transitionIndex;
    uint32_t _color;
    int _fromIndex;
    int _toIndex;
    bool _dirty;
};

#endif