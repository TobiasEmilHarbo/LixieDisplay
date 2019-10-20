#include "Arduino.h"
#include "LixieDigit.h"
#include "TransitionRoll.h"
#include "LixieDigitTransition.h"

TransitionRoll::TransitionRoll()
{
	Serial.begin(115200);
}

void TransitionRoll::transitionTo(LixieDigit* digits[10], int number)
{
	_digits = digits;

	_fromIndex 	= _toIndex;
	_toIndex 	= number;
	_transitionIndex = _fromIndex;

	_tickLength = 20;
}

void TransitionRoll::tick()
{
	_dirty = false;
	
	if (millis() > _lastTick + _tickLength)
	{
    	_lastTick = millis();

		if(_transitionIndex == _toIndex) return;

		int incrementer = (_fromIndex > _toIndex) ? -1 : 1;

		_transitionIndex += incrementer;

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