#include "Arduino.h"
#include "LixieDigit.h"

#include "Adafruit_NeoPixel.h"

LixieDigit::LixieDigit(int index, int width)
{
	Serial.begin(115200);

	_index = index;
	_width = width;
}

void LixieDigit::setPixels(Adafruit_NeoPixel * pixels)
{
	_pixels = pixels;
}

void LixieDigit::turnOn(uint32_t color)
{
	for (int i = 0; i < _width; ++i)
	{
		int pixelIndex = (_index + i);
		_pixels->setPixelColor(pixelIndex, color);
	}
}

int LixieDigit::getWidth()
{
	return _width;
}