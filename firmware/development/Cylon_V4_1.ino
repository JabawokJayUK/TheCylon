/* Cylon Brake Light Dev
/ V4.1
/ 3 primary states of operation:
/  state 1: instant on - 100% illumination for 2 seconds
/  state 2: pulse from 100% to 20% and back for 13 seconds
/  state 3: larson scanner effect indefinatley
/  MOT bypass function to keep light fixed in state 1 indefinatley
/
/ Dev work courtesy of Jay Abbott & Rob C?
/
*/

#include <SoftPWM.h>

int cylonDelay = 45;
int cylonFadeup = 0;
int cylonFadedown = 300;
int pulseFade = 1500;
int pulsePause = 1100;
int noFade = 0;
int switchPin = 13;
int pwmPin = 3;
int ledPins[] = {2,4,5,6,7,8,9,10,11,12};

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
      analogWrite(pwmPin, 0);
        delay(pulsePause);
      analogWrite(pwmPin, 255);
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
