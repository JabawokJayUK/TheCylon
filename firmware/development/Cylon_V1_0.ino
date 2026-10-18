/*
Cylon Brake Light V1.0

Courtesy of JabawokJayUK

10 LED's Indipendnetly controlled

2 States of opperation:

State 1 - 0-3000ms = All On
State 2 - > 3000ms = Larsen cylon effect

Enjoy
 */
 
int timer = 75; // Higher number = longer scan... adjust the meeting in middle to look in time if you change this number
int indLED = 75; //This is the delay on the meet in the middle sequence, updated to use an integer function


void setup() {
  // use a for loop to initialize each pin as an output, this also takes care of digital output set-up:
  for (int thisPin = 3; thisPin < 13; thisPin++)  {
    pinMode(thisPin, OUTPUT);      
  }
}

void loop() {
  if  (millis() <= 5000) {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);

  } else {
    // loop from right to left:  
  for (int thisPin = 3; thisPin < 12; thisPin++) { 
    // turn the pin on:
    digitalWrite(thisPin, HIGH);   
    delay(timer);                  
    // turn the pin off:
    digitalWrite(thisPin, LOW);    
  }
  // loop from left to right:
  for (int thisPin = 12; thisPin >= 3; thisPin--) { 
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
  } 
}
}
 // whole thing starts over and continually runs...
