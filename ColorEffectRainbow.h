#ifndef ColorEffectRainbow_h
#define ColorEffectRainbow_h

#include "Arduino.h"
#include "LixieDigit.h"
#include "LixieDigitColorEffect.h"

class ColorEffectRainbow: public LixieDigitColorEffect
{
  public:
    ColorEffectRainbow(LixieDigit* digits[10]);
    void tick() override;
  private:
      int _red;
      int _green;
      int _blue;
};

#endif