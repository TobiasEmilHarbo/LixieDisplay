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
    void turnOff();
    uint32_t getColor();
    int getWidth();
  private:
  	int _width;
  	int _digitIndex;
    Adafruit_NeoPixel * _pixels;
};

#endif