#include "Arduino.h"
#include "LixieDigit.h"
#include "TransitionRollAround.h"
#include "LixieDigitTransition.h"

TransitionRollAround::TransitionRollAround()
{
	Serial.begin(115200);
}

void TransitionRollAround::transitionTo(LixieDigit* digits[10], int number)
{
	_digits = digits;

	_fromIndex 	= _toIndex;
	_toIndex 	= number;
	_transitionIndex = _fromIndex;

	_tickLength = 20;
}

void TransitionRollAround::tick()
{
	_dirty = false;

	if (millis() > _lastTick + _tickLength)
	{
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
			_digits[_transitionIndex]->turnOn();

		_dirty = true;
	}
}