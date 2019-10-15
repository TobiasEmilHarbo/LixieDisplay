#include "Arduino.h"
#include "LixieDigit.h"
#include "TransitionRollAround.h"
#include "LixieDigitTransition.h"

TransitionRollAround::TransitionRollAround()
{
	Serial.begin(115200);
}

void TransitionRollAround::transitionTo(LixieDigit* digits[10], int number, uint32_t color)
{
	_color 	= color;
	_digits = digits;

	_fromIndex 	= _toIndex;
	_toIndex 	= number;
	_transitionIndex = _fromIndex;
}

void TransitionRollAround::tick()
{
	int tickLength = 10;

	if (millis() > _lastTick + tickLength)
	{
        Serial.println("TICK");
	
    	_lastTick = millis();

		if (_transitionIndex == _toIndex) return;

		_transitionIndex--;
		if (_transitionIndex < 0) _transitionIndex = 9;
		
		for (int i = 0; i < 10; ++i)
		{
			if (_digits[i] != NULL)
				_digits[i]->turnOff();
		}

		if (_digits[_transitionIndex] != NULL)
			_digits[_transitionIndex]->turnOn(_color);
	}
}