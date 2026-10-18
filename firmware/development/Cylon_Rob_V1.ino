#include <SoftPWM.h>

int cylonDelay = 45;
int cylonFadeup = 0;
int cylonFadedown = 300;
int pulseFade = 1500;
int larson_cnt = 0;
int noFade = 0;
int switchPin = 2;
int state = 0;


void setup()
{
	// Initialize Software PWM
	SoftPWMBegin();
	// Inialise MOT switch input
	pinMode(switchPin, INPUT);

	if (digitalRead(switchPin) == HIGH)
	{
		// go to MOT state
		state = 0;
	}
	else
	{
		// Initalise SoftPWM make all output high
		SoftPWMBegin(SOFTPWM_INVERTED);
		for (int thisPin = 3; thisPin <=12; thisPin++)
		{
			  // Create and set pin 13 to 0 (high) as  we have inverted the polarity
			  SoftPWMSet(thisPin, 0);
		}
		// set fade up down time
		SoftPWMSetFadeTime(ALL, pulseFade, pulseFade);
		// Go to Larson state and
		state = 1;
	}
}

void loop() {

	switch (state)
	{
	case 0:	// MOT bypass state
		for (int thisPin = 3; thisPin <=12; thisPin++)
		{
			// make all digital outputs high
			DigitalWrite(thisPin, HIGH);
		}
		// go to idle state and do nothing till next brake sequence
		state = 3;
		break;
	case 1:	// Larson state after 500ms
		if  (millis() >= 500)
		{
			SoftPWMSetPercent(ALL, 20);	// fade down to 20%
			delay(pulseFade);
			SoftPWMSetPercent(ALL, 100);	// fade up to 100%
			delay(pulseFade);
			if (larson_cnt  > 3) // do this 3 times ( total time = pulseFade x larson_cnt x 2)
			{
				// go to Cylon state
				SoftPWMSetFadeTime(ALL, cylonFadeup, cylonFadedown);
				state = 2;
			}
			larson_cnt = larson_cnt + 1;
		}
		break;
	case 2:
		// loop from right to left:
		for (int thisPin = 3; thisPin <= 12; thisPin++)
		{
			 SoftPWMSetPercent(thisPin, 100);
			 delay(cylonDelay);
			 SoftPWMSetPercent(thisPin, 0);
			 delay(cylonDelay);
		}
		// loop from left to right:
		for (int thisPin = 12; thisPin >= 3; thisPin--)
		{
			 SoftPWMSetPercent(thisPin, 100);
			 delay(cylonDelay);
			 SoftPWMSetPercent(thisPin, 0);
			 delay(cylonDelay);
		}
		break;
	case 3:  // idle state do nothing
	default:
		break;
	}

}

