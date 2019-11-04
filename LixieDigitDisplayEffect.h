#ifndef LixieDigitDisplayEffect_h
#define LixieDigitDisplayEffect_h

#include "Arduino.h"
#include "LixieDigit.h"

class LixieDigitDisplayEffect
{
  public:
    LixieDigitDisplayEffect();
    String format(String number, int numOfDigits);
};

#endif