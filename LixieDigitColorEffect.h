#ifndef LixieDigitColorEffect_h
#define LixieDigitColorEffect_h

#include "Arduino.h"
#include "LixieDigit.h"

class LixieDigitColorEffect
{
  public:
    LixieDigitColorEffect(LixieDigit* digits[10]);
    void tick();
    bool isDirty();
  private:
    uint32_t _color;
    bool _dirty;
};

#endif