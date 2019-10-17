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
    LixieDigitPosition(int index, int digitWidth, int base, uint32_t color);
    void setPixels(Adafruit_NeoPixel* pixels);
    int pixelCount();
    void setTransition(LixieDigitTransition* transition);
    void setColor(uint32_t color);
    void update(int number);
    void tick();
  private:
  	int _index;
    int _number;
  	int _startPixel;
    LixieDigitColorEffect* _colorEffect;
    LixieDigitTransition* _transition;
    uint32_t _color;
  	LixieDigit* _digits[10];
    Adafruit_NeoPixel* _pixels;
};

#endif