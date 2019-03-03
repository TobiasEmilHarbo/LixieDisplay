#ifndef LixieDigit_h
#define LixieDigit_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

class LixieDigit
{
  public:
    LixieDigit(int index, int width);
    void setPixels(Adafruit_NeoPixel * pixels);
    void turnOn(uint32_t color);
    int getWidth();
  private:
  	int _index;
  	int _width;
    Adafruit_NeoPixel * _pixels;
};

#endif