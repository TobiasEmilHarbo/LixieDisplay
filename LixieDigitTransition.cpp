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
	if(_lastNumber == number) return;

	Serial.println("LixieDigitTransition::transitionTo");
	
	for (int i = 0; i < 10; ++i)
	{
		if (digits[i] != NULL)
		 	digits[i]->turnOn(0);
	}

	if (digits[number] != NULL)
	{
		digits[number]->turnOn(color);
	}

	_lastNumber = number;
}

void LixieDigitTransition::tick()
{
	int tickLength = 200;
	if (millis() > _lastTick + tickLength)
	{
		_lastTick = millis();
		Serial.println("LixieDigitTransition::tick");
	}
}