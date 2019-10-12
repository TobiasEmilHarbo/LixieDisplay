#include "Arduino.h"
#include "LixieDigitEffect.h"

LixieDigitEffect::LixieDigitEffect()
{
	Serial.begin(115200);
	Serial.println("LixieDigitEffect");
}

void LixieDigitEffect::setDigits()
{
	Serial.println("LixieDigitEffect::setDigits");
}