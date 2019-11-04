#ifndef LixieDigitTransition_h
#define LixieDigitTransition_h

#include "Arduino.h"
#include "LixieDigit.h"

class LixieDigitTransition
{
  public:
    LixieDigitTransition();
    virtual void transitionTo(LixieDigit* digits[10], int number);
    virtual void tick();
    bool isDirty();
  protected:
    unsigned long _lastTick;
    LixieDigit** _digits;
    int _transitionIndex = -1;
    int _tickLength;
    int _fromIndex;
    int _toIndex = -1;
    bool _dirty;
};

#endif