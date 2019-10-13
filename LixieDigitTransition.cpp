#include "Arduino.h"
#include "LixieDigit.h"
#include "LixieDigitTransition.h"

LixieDigitTransition::LixieDigitTransition()
{
	Serial.begin(115200);
	Serial.println("LixieDigitTransition");
}

void LixieDigitTransition::transitionTo(LixieDigit* digits[10], int number, uint32_t color)
{
	Serial.println("LixieDigitTransition::transitionTo");
	
	if (digits[number] != NULL)
	{
		digits[number]->turnOn(color);
	}

	_lastNumber = number;
}