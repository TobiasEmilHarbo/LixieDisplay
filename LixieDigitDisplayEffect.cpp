#include "Arduino.h"
#include "LixieDigitDisplayEffect.h"

LixieDigitDisplayEffect::LixieDigitDisplayEffect()
{
	Serial.begin(115200);
}

String LixieDigitDisplayEffect::format(String number, int numOfDigits)
{
	// int digitCount = number.length();
	// char digits[numOfDigits];

	// int diff = numOfDigits - digitCount;
	// int padding = (diff > 0) ? diff : 0;

	// number.toCharArray(digits, numOfDigits);

	return number;
}