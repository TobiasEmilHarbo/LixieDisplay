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
    void setup(Adafruit_NeoPixel * pixels);
    int pixelCount();
    void setColor(uint32_t color);
    void setColors(uint32_t colors[]);
    void setTransitionForDigit(int position, LixieDigitTransition* transition);
    void display(String number);
    void turnOff();
  private:
    int _numOfDigits;
    Adafruit_NeoPixel * _pixels;
    LixieDigitPosition * _digitPositions[10];
};

#endif