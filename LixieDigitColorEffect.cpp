#include "Arduino.h"
#include "LixieDigitColorEffect.h"

LixieDigitColorEffect::LixieDigitColorEffect(LixieDigit* digits[10])
{
	Serial.begin(115200);
}

void LixieDigitColorEffect::tick()
{

}

bool LixieDigitColorEffect::isDirty()
{
	return _dirty;
}