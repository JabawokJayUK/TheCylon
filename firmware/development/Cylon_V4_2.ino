#include <SoftPWM.h>

int cylonDelay = 45;
int cylonFadeup = 0;
int cylonFadedown = 300;
int pulseFade = 1500;
int larson_cnt = 0;
int noFade = 0;
int switchPin = 13;
int state = 0;
int pwmPin = 3;
int ledPins[] = {2,4,5,6,7,8,9,10,11,12};

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
//		SoftPWMBegin(SOFTPWM_INVERTED);
		SoftPWMBegin();
                for(int i=0; i<=9; i++) {
		{
			  // Create and set pin 13 to 0 (high) as  we have inverted the polarity
			  SoftPWMSet(ledPins[i], 255);
//                          SoftPWMSetFadeTime(thisPin, pulseFade, pulseFade);
		}
		// set fade up down time
		SoftPWMSetFadeTime(ALL, pulseFade, pulseFade);
		// Go to Larson state and
		state = 1;
	}
}
}

void loop() {

	switch (state)
	{
	case 0:	// MOT bypass state
		for(int i=0; i<=9; i++)
		{
			// make all digital outputs high
			digitalWrite(ledPins[i], HIGH);
		}
		// go to idle state and do nothing till next brake sequence
		state = 3;
		break;
	case 1:	// Pulse state after 500ms
		if  (millis() >= 500)
		{
			analogWrite(pwmPin, 0);	// fade down to 20%
			delay(pulseFade);
			analogWrite(pwmPin, 255);	// fade up to 100%
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
		// Cylon State
                // loop from right to left:
		for(int i=0; i<=9; i++)
		{
			 SoftPWMSetPercent(ledPins[i], 100);
			 delay(cylonDelay);
			 SoftPWMSetPercent(ledPins[i], 0);
			 delay(cylonDelay);
		}
		// loop from left to right:
		for(int i=9; i>=0; i--)
		{
			 SoftPWMSetPercent(ledPins[i], 100);
			 delay(cylonDelay);
			 SoftPWMSetPercent(ledPins[i], 0);
			 delay(cylonDelay);
		}
		break;
	case 3:  // idle state do nothing
	default:
		break;
	}

}

