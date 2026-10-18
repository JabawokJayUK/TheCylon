#include <SoftPWM.h>

int timeron = 50;
int timeroff = 50;
int fadeUp = 100;
int fadeDown = 500;

void setup()
{
  // Initialize
  SoftPWMBegin();
  // Create and set pins to 0 (off) and set timers
  for (int thisPin = 3; thisPin <=12; thisPin++) {
    SoftPWMSet(thisPin, 0);
    SoftPWMSetFadeTime(thisPin, fadeUp, fadeDown);
    }
}

void loop() {
  // Light all diodes for 5 seconds  
   if  (millis() <= 5000) {
      for (int thisPin = 3; thisPin <= 12; thisPin++) { 
        SoftPWMSetPercent(thisPin, 100);
        }
   } else {
   
   // loop from right to left:
   for (int thisPin = 3; thisPin <= 11; thisPin++) { 
     SoftPWMSetPercent(thisPin, 100);
       delay(timeron);
     SoftPWMSetPercent(thisPin, 0);
       delay(timeroff); 
    }
     
   // loop from left to right:
   for (int thisPin = 12; thisPin >= 4; thisPin--) { 
     SoftPWMSetPercent(thisPin, 100);
       delay(timeron);
     SoftPWMSetPercent(thisPin, 0);
       delay(timeroff);     
    }
  }
}
 

