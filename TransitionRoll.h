#ifndef TransitionRoll_h
#define TransitionRoll_h

#include "Arduino.h"
#include "LixieDigit.h"
#include "LixieDigitTransition.h"

class TransitionRoll: public LixieDigitTransition
{
  public:
    TransitionRoll();
    void transitionTo(LixieDigit* digits[10], int number) override;
    void tick() override;
};

#endif