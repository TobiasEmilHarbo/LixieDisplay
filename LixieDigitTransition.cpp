#include "Arduino.h"
#include "LixieDigit.h"
#include "LixieDigitTransition.h"

LixieDigitTransition::LixieDigitTransition()
{
	Serial.begin(115200);
}

void LixieDigitTransition::transitionTo(LixieDigit* digits[10], int number)
{
	_digits = digits;

	_fromIndex 	= _toIndex;
	_toIndex 	= number;
	_transitionIndex = _fromIndex;
}

void LixieDigitTransition::tick()
{
	_dirty = false;

	if(_transitionIndex == _toIndex) return;

	for (int i = 0; i < 10; ++i)
	{
		if (_digits[i] == NULL)
			break;

		if(i == _toIndex) _digits[i]->turnOn();
		else _digits[i]->turnOff();
	}

	_transitionIndex = _toIndex;

	_dirty = true;
}

bool LixieDigitTransition::isDirty()
{
	return _dirty;
}