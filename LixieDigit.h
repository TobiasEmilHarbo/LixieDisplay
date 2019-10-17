#ifndef LixieDigit_h
#define LixieDigit_h

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"


class LixieDigit
{
  public:
    LixieDigit(int index, int width);
    void setPixels(Adafruit_NeoPixel * pixels);
    void turnOn(uint32_t color = NULL);
    void turnOff();
    uint32_t getColor();
    void setColor(uint32_t color);
    int getWidth();
  private:
  	int _width;
  	int _digitIndex;
    bool _on;
    uint32_t _color;
    Adafruit_NeoPixel * _pixels;
    void _changeColor(uint32_t color);
};

#endif