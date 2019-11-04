#include "Arduino.h"
#include "LixieDisplay.h"
#include "LixieDigitPosition.h"
#include "LixieDigitDisplayEffect.h"
#include "LixieDigitTransition.h"

#include "Adafruit_NeoPixel.h"

LixieDisplay::LixieDisplay(int digits)
{
	Serial.begin(115200);

	_numOfDigits = digits;
	
	uint32_t defaultColor = _pixels->Color(244,212,66);

	for (int i = 0; i < _numOfDigits; ++i)
	{
		_digitPositions[i] = new LixieDigitPosition(i, 2, 10); 
	}

	_displayEffect = new LixieDigitDisplayEffect();
}

void LixieDisplay::setup(Adafruit_NeoPixel * pixels)
{
	_pixels = pixels;

	_pixels->begin();

	for (int i = 0; i < _numOfDigits; ++i)
	{
		if (_digitPositions[i] != NULL)
	 		_digitPositions[i]->setup(_pixels);
	}

	_pixels->setBrightness(50);
	_pixels->show(); // Initialize all pixels to 'off'
}

void LixieDisplay::setTransitionForDigit(int position, LixieDigitTransition * transition)
{
	if (_digitPositions[position] != NULL)
		_digitPositions[position]->setTransition(transition);
}

void LixieDisplay::update(String number, bool force)
{
	String display = _displayEffect->format(number, _numOfDigits);

	//int digitCount = number.length();
	//char digits[digitCount];

	// int diff = _numOfDigits - digitCount;
	// int padding = (diff > 0) ? diff : 0;

	//display.toCharArray(digits, digitCount);

	// for(char& digit : number) {

	// char digits = display;

	// for (int i = 0; i < digitCount; ++i)
	// for(int i = 0; digits[i] != '\0'; ++i)
	int place = 0;

	for (char &d: display)
	{
		int digit = d - '0'; // convert char to int

		if (_digitPositions[place] != NULL)
			_digitPositions[place]->update(digit);

		place++;
	}

	if(force) this->tick();
}

int LixieDisplay::pixelCount()
{
	int count = 0;

	for (int i = 0; i < _numOfDigits; ++i)
	{
		if (_digitPositions[i] != NULL)
	 		count += _digitPositions[i]->pixelCount();
	}

	return count;
}

void LixieDisplay::turnOff()
{
	for (int i = 0; i < this->pixelCount(); ++i)
	{
		_pixels->setPixelColor(i, 0);
	}
}

void LixieDisplay::tick()
{
	bool update = false;

	for (int i = 0; i < _numOfDigits; ++i)
	{
		if(_digitPositions[i] == NULL) return;

		_digitPositions[i]->tick();
		update = (_digitPositions[i]->isDirty() || update);
	}

	if(update) _pixels->show();
}
