


#include <SoftPWM.h>

int cylonDelay = 45;
int cylonFadeup = 0;
int cylonFadedown = 300;
int pulseFade = 1500;
int pulsePause = 1100;
int noFade = 0;
int switchPin = 13;
int ledPins[] = {3,4,5,6,7,8,9,10,11,12};

void setup()
{
  // Initialize
  SoftPWMBegin();
  pinMode(switchPin, INPUT);  
  for(int i=0; i<=9; i++) {
      SoftPWMSet(ledPins[i], 0);
  }

}

void loop() {
  // MOT bypass function
  if (digitalRead(switchPin) == HIGH)  {
    for(int i=0; i<=9; i++) {
      digitalWrite(ledPins[i], HIGH);         
    }
  } 

  // Light all diodes for 2s for with no delay for instant braking  
  else if  (millis() <= 2000) {
  for(int i=0; i<=9; i++) { 
      digitalWrite(ledPins[i], HIGH); 
    }
  }

  // After 2s slow pulse all diodes for 13s more 
  else if (millis() <= 15000) {
  for(int i=0; i<=9; i++) {
      SoftPWMSetFadeTime(ledPins[i], pulseFade, pulseFade);
    }
      SoftPWMSetPercent(ALL, 75);
        delay(pulsePause);
      SoftPWMSetPercent(ALL, 20);
        delay(pulsePause);
      SoftPWMSetPercent(ALL, 100);
  } 

  // After 15s, cylon routine starts
  else {
  // loop from right to left:
  for(int i=0; i<=9; i++) {
      SoftPWMSetFadeTime(ledPins[i], cylonFadeup, cylonFadedown);
      SoftPWMSetPercent(ledPins[i], 100);
        delay(cylonDelay);
      SoftPWMSetPercent(ledPins[i], 0);
        delay(cylonDelay); 
    }
  // loop from left to right:
  for(int i=9; i>=0; i--) {
      SoftPWMSetPercent(ledPins[i], 100);
        delay(cylonDelay);
      SoftPWMSetPercent(ledPins[i], 0);
        delay(cylonDelay);     
    }
  } 
}
