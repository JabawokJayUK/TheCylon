int timer = 75; // Higher number = longer scan... adjust the meeting in middle to look in time if you change this number

void setup() {
  // use a for loop to initialize each pin as an output, this also takes care of digital output set-up:
  for (int thisPin = 3; thisPin <= 12; thisPin++)  {
    pinMode(thisPin, OUTPUT);      
  }
}

void loop() {
  // loop from right to left:
  for (int thisPin = 3; thisPin <= 12; thisPin++) { 
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
