#include "Arduino.h"
#include "LixieDigitTransition.h"

LixieDigitTransition::LixieDigitTransition()
{
	Serial.begin(115200);
	Serial.println("LixieDigitTransition");
}

void LixieDigitTransition::setDigits()
{
	Serial.println("LixieDigitTransition::setDigits");
}