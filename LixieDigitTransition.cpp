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
	_digits = digits;

	_fromIndex 	= _toIndex;
	_toIndex 	= number;
	_transitionIndex = _fromIndex;
}

void LixieDigitTransition::tick()
{
	if(_transitionIndex == _toIndex) return;

	for (int i = 0; i < 10; ++i)
	{
		if (_digits[i] != NULL)
			_digits[i]->turnOff();
	}

	if (_digits[_toIndex] != NULL)
		_digits[_toIndex]->turnOn(_color);

	_transitionIndex = _toIndex;
	_dirty = true;
}

bool LixieDigitTransition::isDirty()
{
	return _dirty;
}