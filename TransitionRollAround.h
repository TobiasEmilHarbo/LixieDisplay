#ifndef TransitionRollAround_h
#define TransitionRollAround_h

#include "Arduino.h"
#include "LixieDigit.h"
#include "LixieDigitTransition.h"

class TransitionRollAround: public LixieDigitTransition
{
  public:
    TransitionRollAround();
    void transitionTo(LixieDigit* digits[10], int number) override;
    void tick() override;

  public:
};

#endif