#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

#include "LixieDigit.h"
#include "LixieDigitPosition.h"

#include "LixieDigitColorEffect.h"
#include "ColorEffectRainbow.h"


#include "LixieDigitTransition.h"
#include "TransitionRollAround.h"
#include "TransitionRoll.h"

LixieDigitPosition::LixieDigitPosition(int index, int digitWidth, int base, uint32_t color)
{
	Serial.begin(115200);

	_index = index;
	_color = color;
	_startPixel = index * digitWidth * base;
	
	for (int i = 0; i < base; ++i)
	{
		int digitIndex = (i * digitWidth) + _startPixel;
	 	_digits[i] = new LixieDigit(digitIndex, digitWidth);
	}

	// _colorEffect 	= new ColorEffectRainbow(_digits);
}

void LixieDigitPosition::setup(Adafruit_NeoPixel * pixels)
{
	_pixels = pixels;

	for (int i = 0; i < sizeof(_digits) / sizeof(_digits[0]); ++i)
	{
		if (_digits[i] != NULL)
		 	_digits[i]->setPixels(_pixels);
	}

	_transition 	= new LixieDigitTransition();
	_colorEffect 	= new LixieDigitColorEffect(_digits);
	
	_colorEffect->setColor(244,212,66);

	// _colorEffect 	= new LixieDigitColorEffect(_digits);
}

void LixieDigitPosition::setPixels(Adafruit_NeoPixel * pixels)
{
	_pixels = pixels;

	for (int i = 0; i < sizeof(_digits) / sizeof(_digits[0]); ++i)
	{
		if (_digits[i] != NULL)
		 	_digits[i]->setPixels(_pixels);
	}
}

void LixieDigitPosition::update(int number)
{
	_number = number;
	_transition->transitionTo(_digits, number);
}

void LixieDigitPosition::setColor(uint32_t color)
{
	_color = color;
	_digits[_number]->turnOn(color);
}

void LixieDigitPosition::setTransition(LixieDigitTransition* transition)
{
	_transition = transition;
}

int LixieDigitPosition::pixelCount()
{
	int count = 0;

	for (int i = 0; i < sizeof(_digits) / sizeof(_digits[0]); ++i)
	{
		if (_digits[i] != NULL)
		 	count += _digits[i]->getWidth();
	}

	return count;
}

void LixieDigitPosition::tick()
{
	if(_transition != NULL)
		_transition->tick();

	if(_colorEffect != NULL)
		_colorEffect->tick();
}

bool LixieDigitPosition::isDirty()
{
	return (
			(_transition != NULL && _transition->isDirty())
		||  (_colorEffect != NULL && _colorEffect->isDirty())
	);
}