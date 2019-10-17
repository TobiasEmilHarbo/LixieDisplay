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

void LixieDigit::setColor(uint32_t color)
{
	_color = color;
	if(_on) this->_changeColor(color);
}

void LixieDigit::turnOn(uint32_t color)
{
	_on = true;

	if(color == NULL) return;
	
	_color = color;

	if(this->getColor() == _color) return;
	
	this->_changeColor(_color);
}

void LixieDigit::turnOff()
{
	_on = false;
	this->_changeColor(0);
}

int LixieDigit::getWidth()
{
	return _width;
}

uint32_t LixieDigit::getColor()
{
	return _pixels->getPixelColor(_digitIndex);
}

void LixieDigit::_changeColor(uint32_t color)
{
	for (int i = 0; i < _width; ++i)
	{
		int pixelIndex = (_digitIndex + i);
		_pixels->setPixelColor(pixelIndex, color);
	}
}