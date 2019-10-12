#ifndef LixieDigitEffect_h
#define LixieDigitEffect_h

#include "Arduino.h"

class LixieDigitEffect
{
  public:
    LixieDigitEffect();
    void setDigits();
  private:
    uint32_t _color;
};

#endif