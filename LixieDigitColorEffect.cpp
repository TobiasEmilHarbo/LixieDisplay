#include "Arduino.h"
#include "LixieDigitColorEffect.h"

LixieDigitColorEffect::LixieDigitColorEffect(LixieDigit* digits[10])
{
	Serial.begin(115200);
	_digits = digits;
}

void LixieDigitColorEffect::setColor(int red, int green, int blue)
{
	for (int i = 0; i < 10; ++i)
	{
		if (_digits[i] != NULL)
			_digits[i]->setColor(red, green, blue);
	}
}

void LixieDigitColorEffect::tick()
{
	_dirty = false;
}

bool LixieDigitColorEffect::isDirty()
{
	return _dirty;
}