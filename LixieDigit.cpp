#include "Arduino.h"
#include "LixieDigit.h"
#include "Adafruit_NeoPixel.h"

LixieDigit::LixieDigit(int index, int width)
{
	Serial.begin(115200);

	_width = width;
	_digitIndex = index;
}

void LixieDigit::setPixels(Adafruit_NeoPixel * pixels)
{
	_pixels = pixels;
}

void LixieDigit::turnOn(uint32_t newColor)
{
	if(this->getColor() == newColor) return;

	for (int i = 0; i < _width; ++i)
	{
		int pixelIndex = (_digitIndex + i);
		_pixels->setPixelColor(pixelIndex, newColor);
	}
}

int LixieDigit::getWidth()
{
	return _width;
}

uint32_t LixieDigit::getColor()
{
	return _pixels->getPixelColor(_digitIndex);
}