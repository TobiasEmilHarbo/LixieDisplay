#include "Arduino.h"
#include "LixieDigit.h"
#include "LixieDigitTransition.h"

LixieDigitTransition::LixieDigitTransition()
{
	Serial.begin(115200);
}

void LixieDigitTransition::transitionTo(LixieDigit* digits[10], int number, uint32_t color)
{
	_color 		= color;
	_digits 	= digits;
	_number 	= number;
}

void LixieDigitTransition::tick()
{
	for (int i = 0; i < 10; ++i)
	{
		if (_digits[i] != NULL)
			_digits[i]->turnOff();
	}

	if (_digits[_number] != NULL)
		_digits[_number]->turnOn(_color);
}