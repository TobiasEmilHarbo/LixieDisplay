#ifndef LixieDigitPosition_h
#define LixieDigitPosition_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"
#include "LixieDigit.h"

class LixieDigitPosition
{
  public:
    LixieDigitPosition(int index, int digitWidth, int base, uint32_t color);
    void setPixels(Adafruit_NeoPixel * pixels);
    int pixelCount();
    void setColor(uint32_t color);
    void display(int number);
  private:
  	int _index;
    int _number;
  	int _startPixel;
    uint32_t _color;
  	LixieDigit * _digits[10];
    Adafruit_NeoPixel * _pixels;
};

#endif