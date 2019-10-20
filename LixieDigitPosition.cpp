#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

#include "LixieDigit.h"
#include "LixieDigitPosition.h"

#include "LixieDigitColorEffect.h"
#include "ColorEffectRainbow.h"

#include "LixieDigitTransition.h"
#include "TransitionRollAround.h"
#include "TransitionRoll.h"

LixieDigitPosition::LixieDigitPosition(int index, int digitWidth, int base)
{
	Serial.begin(115200);

	_index = index;
	_startPixel = index * digitWidth * base;
	
	for (int i = 0; i < base; ++i)
	{
		int digitIndex = (i * digitWidth) + _startPixel;
	 	_digits[i] = new LixieDigit(digitIndex, digitWidth);
	}
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