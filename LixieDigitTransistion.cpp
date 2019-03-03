#include "Arduino.h"
#include "LixieDigitTransistion.h"

#include "Adafruit_NeoPixel.h"

LixieDigitTransistion::LixieDigitTransistion(uint32_t color)
{
	_color = color;
}