#include <SoftPWM.h>

int cylonDelay = 45;
int cylonFadeup = 0;
int cylonFadedown = 300;
int pulseFade = 1500;
int pulsePause = 1100;
int noFade = 0;
int switchPin = 2;


void setup()
{
  // Initialize
  SoftPWMBegin();
  // Create and set pins to 0 (off)
  for (int thisPin = 3; thisPin <=12; thisPin++) {
    SoftPWMSet(thisPin, 0);
    pinMode(switchPin, INPUT);
        }
      }

void loop() {
  // MOT bypass function
  if (digitalRead(switchPin) == HIGH)  {
     for (int thisPin = 3; thisPin <= 12; thisPin++) { 
     SoftPWMSetFadeTime(thisPin, noFade, noFade);
     }
     SoftPWMSetPercent(ALL, 100);
         } else
  // Light all diodes for with no delay for instant braking  
   if  (millis() <= 500) {
     for (int thisPin = 3; thisPin <= 12; thisPin++) { 
     SoftPWMSetFadeTime(thisPin, noFade, noFade);
     }
     SoftPWMSetPercent(ALL, 100);
         }
  // after 100ms slow pulse all diodes for 10 seconds 
    else if (millis() <= 10000) {
     for (int thisPin = 3; thisPin <= 12; thisPin++) { 
     SoftPWMSetFadeTime(thisPin, pulseFade, pulseFade);
     }
        SoftPWMSetPercent(ALL, 75);
        delay(pulsePause);
        SoftPWMSetPercent(ALL, 20);
        delay(pulsePause);
        SoftPWMSetPercent(ALL, 100);
    } else {
   
  // After 10 seconds, cylon routine starts
  // loop from right to left:
   for (int thisPin = 3; thisPin <= 12; thisPin++) { 
     SoftPWMSetFadeTime(thisPin, cylonFadeup, cylonFadedown);
     SoftPWMSetPercent(thisPin, 100);
       delay(cylonDelay);
     SoftPWMSetPercent(thisPin, 0);
       delay(cylonDelay); 
    }
  // loop from left to right:
   for (int thisPin = 12; thisPin >= 3; thisPin--) { 
     SoftPWMSetPercent(thisPin, 100);
       delay(cylonDelay);
     SoftPWMSetPercent(thisPin, 0);
       delay(cylonDelay);     
      }
    } 
  }
