

// ToDo:
// Debounce code to get millis since press for brakePin
// interrupt code to run current loop
// Can I remove mot check from loop?
// Can I send all HIGH first rather than light as PwM in loop left to right?

int cylonDelay = 45;
int cylonFadeup = 0;
int cylonFadedown = 300;
int pulseFade = 1500;
int pulsePause = 1100;
int noFade = 0;
int motPin = 13;
int brakePin = 2;


void setup() {
    pinMode(motPin, INPUT);
}

void loop() {
  // MOT bypass function
  if (digitalRead(motPin) == HIGH)  { 
//        do something
           } else
  // Light all diodes for with no delay for instant braking  
   if (millis() <= 150000) {

  }
}
