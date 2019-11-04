#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <LixieDisplay.h>
#include "Adafruit_NeoPixel.h"
#include "LixieDigitTransition.h"
#ifdef __AVR__
#include <avr/power.h>
#endif

#define A0 17

#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define D9 3
#define D10 1

#define SD2 9
#define SD3 10

LixieDisplay lixie = LixieDisplay(3);

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(lixie.pixelCount(), D1, NEO_GRB + NEO_KHZ800);

const char *ssid = "Troejborgvej36";
const char *password = "Denise8240";

WiFiUDP ntpUDP;

int UTC = 1; // timezone

NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", UTC * 3600, 60000);

unsigned long lastSecTick = 0;
int oneSec = 4000;

int counter = 0;

void setup()
{
	Serial.begin(115200);

	lixie.setup(&pixels);

	//lixie.setTransitionForDigit(1, new LixieDigitTransition());

	WiFi.begin(ssid, password);

	while ( WiFi.status() != WL_CONNECTED )
	{
		lixie.update(String(counter), true);
		counter++;
		delay(500);
	}

	counter = 0;

	timeClient.begin();
}

void loop()
{
	if (millis() > lastSecTick + oneSec)
	{
		lastSecTick = millis();

		timeClient.update();

		int h = timeClient.getHours();
		int m = timeClient.getMinutes();
		int s = timeClient.getSeconds();

		char number[6];
		// sprintf(number, "%02d%02d", m, s);
		sprintf(number, "%03d", counter);
		// sprintf(number, "%03d", random(1000));

		// Serial.println(number);

		lixie.update(number);

		counter++;

		//Serial.println(timeClient.getFormattedTime());
	}

	lixie.tick();

	delay(100);
}