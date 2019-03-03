#ifndef LixieDigitTransition_h
#define LixieDigitTransition_h

#include "Arduino.h"

class LixieDigitTransition
{
  public:
    LixieDigitTransition();
    void setDigits();
  private:
    uint32_t _color;
};

#endif