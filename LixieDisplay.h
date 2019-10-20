#ifndef LixieDisplay_h
#define LixieDisplay_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"
#include "LixieDigitPosition.h"
#include "LixieDigitTransition.h"

class LixieDisplay
{
  public:
    LixieDisplay(int digits);
    void setup(Adafruit_NeoPixel* pixels);
    int pixelCount();
    void setTransitionForDigit(int position, LixieDigitTransition* transition);
    void update(String number, bool force = false);
    void turnOff();
    void tick();
  private:
    int _numOfDigits;
    Adafruit_NeoPixel* _pixels;
    LixieDigitPosition* _digitPositions[10];
};

#endif