#include "Arduino.h"
#include "LixieDigit.h"
#include "LixieDigitTransition.h"

LixieDigitTransition::LixieDigitTransition()
{
	Serial.begin(115200);
}

void LixieDigitTransition::transitionTo(LixieDigit* digits[10], int number, uint32_t color)
{
	_color 	= color;
	_from 	= _to;
	_to 	= number;
	_digits = digits;
}

void LixieDigitTransition::tick()
{
	int tickLength = 100;
	if (millis() > _lastTick + tickLength)
	{
		_lastTick = millis();
		Serial.println("LixieDigitTransition::tick");		
	
		for (int i = 0; i < 10; ++i)
		{
			if (_digits[i] != NULL)
				_digits[i]->turnOn(0);
		}

		if (_digits[_to] != NULL)
			_digits[_to]->turnOn(_color);
	}
}