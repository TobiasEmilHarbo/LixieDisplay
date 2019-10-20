#ifndef LixieDigitColorEffect_h
#define LixieDigitColorEffect_h

#include "Arduino.h"
#include "LixieDigit.h"

class LixieDigitColorEffect
{
  public:
    LixieDigitColorEffect(LixieDigit* digits[10]);
    virtual void tick();
    void setColor(int red, int green, int blue);
    bool isDirty();
  protected:
    unsigned long _lastTick;
    LixieDigit** _digits;
    int _tickLength;
    bool _dirty;
};

#endif