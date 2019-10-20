#ifndef LixieDigitPosition_h
#define LixieDigitPosition_h

#include "Arduino.h"
#include "LixieDigit.h"
#include "Adafruit_NeoPixel.h"
#include "LixieDigitTransition.h"
#include "LixieDigitColorEffect.h"

class LixieDigitPosition
{
  public:
    LixieDigitPosition(int index, int digitWidth, int base);
    void setup(Adafruit_NeoPixel* pixels);
    void setPixels(Adafruit_NeoPixel* pixels);
    void setTransition(LixieDigitTransition* transition);
    void update(int number);
    int pixelCount();
    bool isDirty();
    void tick();
  private:
  	int _index;
    int _number;
  	int _startPixel;
    LixieDigitColorEffect* _colorEffect;
    LixieDigitTransition* _transition;
  	LixieDigit* _digits[10];
    Adafruit_NeoPixel* _pixels;
};

#endif