#ifndef TransitionRollAround_h
#define TransitionRollAround_h

#include "Arduino.h"
#include "LixieDigit.h"
#include "LixieDigitTransition.h"

class TransitionRollAround: public LixieDigitTransition
{
  public:
    TransitionRollAround();
    void transitionTo(LixieDigit* digits[10], int number, uint32_t color) override;
    void tick() override;

  public:
    int _fromIndex;
    int _toIndex;
    int _transitionIndex;
    unsigned long _lastTick;
    int tickLength;
};

#endif