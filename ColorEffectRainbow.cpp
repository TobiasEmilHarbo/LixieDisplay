#include "Arduino.h"
#include "ColorEffectRainbow.h"
#include "LixieDigitColorEffect.h"

ColorEffectRainbow::ColorEffectRainbow(LixieDigit* digits[10]): LixieDigitColorEffect(_digits) {
	Serial.begin(115200);
	
	_digits = digits;

	_tickLength = 30;

	_red = 255;
	_green = 0;
	_blue = 0;
}

void ColorEffectRainbow::tick()
{
	_dirty = false;

	if (millis() > _lastTick + _tickLength)
	{
    	_lastTick = millis();

		if(_blue == 0)
		{
			_green++;
			_red--;
		} 
		
		if(_red == 0)
		{
			_green--;
 			_blue++;
		}

		if(_green == 0)
		{
			_red++;
			_blue--;
		}
		
		this->setColor(_red, _green, _blue);

		_dirty = true;
	}
}