/*-----------------------[ Cylon Brake Light ]---------------------*\
| This is the V5 code for the "Cylon Brake Light" upgrade for the   |
| Alfa Romeo 159 / Brera. The unit replaces the default light bar   |
| and provides a 10 LED PWM controlled unit capable of interesting  |
| stuff like the larson effect.                                     |
|                                                                   |
| Code has three primary states of operation:                       |
|  State 1:  Full On                                                |
|  State 2:  Breathing Effect                                       |
|  State 3:  Larson Scanner                                         |
|                                                                   |
| Code also accounts for an MOT bypass fucntion incase the Rozzers  |
| get all up in yo face about the flashy lights on the back of your |
| sweet ride.                                                       |
|                                                                   |
|                          Code & Hardware by                       |
|                        ---{  Jay Abbott  }----                    |
|                                - AkA -                            |
|                                                                   |
|            #   ##   #####    ##   #    #  ####  #    # #          |
|            #  #  #  #    #  #  #  #    # #    # #   #  #          |
|            # #    # #####  #    # #    # #    # ####   #          |
|            # ###### #    # ###### # ## # #    # #  #   #          |
|       #    # #    # #    # #    # ##  ## #    # #   #  #          |
|        ####  #    # #####  #    # #    #  ####  #    # #          |
|                                                                   |
|                Check out at: http://jabawoki.com                  |
|                                                                   |
| Special thanks and credits to Rob C for expert support and advice |
|               - the man has some serious skillz -                 |
|                                                                   |
|                                                                   |
| This code makes use of the TLC 5940 Library available on Google   |
| Code: http://code.google.com/p/tlc5940arduino/ You will need this |
| To make the program run, so grab it and install it into your      |
| Libraries folder before compiling or it will just be 100% FAIL.   |
|                                                                   |
\*-----------------------------------------------------------------*/

// LED Notes: 39.06 / ohms of resitor = mA of drive
// so
// 800 ohm resistor from Pin 20 to GND for 48mA to LEDs
// + 10 x 220 ohm 1W resistors between +12 & each LEDs Anode
// or
// 300 ohm Resistor from Pin 20 to GND for 120mA to LEDs
// + 10 x 100 ohm 2W resistors between +12 & each LEDs Anode


// Library includes
#include "Tlc5940.h"
#include "tlc_fades.h"

// Variables for the larson effects
#define SCOPE_PERIOD      (1000 * NUM_TLCS)
#define LED_PERIOD        SCOPE_PERIOD / (NUM_TLCS * 16)

TLC_CHANNEL_TYPE channel;

void setup()
{
  Tlc.init(4095);                              // Set-up the TLC and put all LEDs on full (also known as State 1)
  pinMode(2, OUTPUT);                          // Arduino Digital Pin 2 or ATMega328P Chip Pin 4
  digitalWrite(2,LOW);                         // Disable the hardware instant on and let the TLC do its thing.
}

// State 2 - Breathing effect
void breathe(int qq)                            // qq is number of times to breathe :)
{
  Tlc.clear();
  for (int q=0; q<qq; q++)
    {
    for (int p=4095; p>=500; p-=10)             // decrease brightness to around 12%
      {
      for (int l=0; l<10; l++)
        {
        Tlc.set(l, p);
        }
      Tlc.update();
      delay(5);
      }
    for (int p=500; p<=4095; p+=10)             // increase brightness back to 100%
      {
      for (int l=0; l<10; l++)
        {
        Tlc.set(l, p);
        }
      Tlc.update();
      delay(5);
      }
    }
}

// State 3 Part 1 - Larson with Fades - Left to Right
void l2r(int rr)                               // rr provides a counter for the loop to increment each LED in the array
{
    for (int r=0; r<rr; r++)
    {
  uint32_t lastMillis = millis();
  tlc_addFade(channel,                         // led channel
    4095,                                      // start fade value (0-4095)
    0,                                         // end fade value (0-4095)
    lastMillis + 2,                            // start millis
    lastMillis + (uint16_t)SCOPE_PERIOD / 4    // end millis
  );

  if (channel++ == NUM_TLCS * 9) {
      channel = 0;
      }
  
      uint32_t currentMillis;
        do {
            currentMillis = millis();
            tlc_updateFades(currentMillis);
            } while (currentMillis - lastMillis <= LED_PERIOD);
    }
}

// State 3 Part 2 - Larson with Fades - Right to Left
void r2l(int ss)                               // ss provides a counter for the loop to increment each LED in the array
{
      for (int s=0; s<ss; s++)
    {
    uint32_t lastMillis = millis();
  tlc_addFade(channel,                         // led channel
    4095,                                      // start fade value (0-4095)
    0,                                         // end fade value (0-4095)
    lastMillis + 2,                            // start millis
    lastMillis + (uint16_t)SCOPE_PERIOD / 4    // end millis
  );
  if (channel-- == NUM_TLCS * 0) {
      channel = 9;
      }
  
      uint32_t currentMillis;
        do {
            currentMillis = millis();
            tlc_updateFades(currentMillis);
            } while (currentMillis - lastMillis <= LED_PERIOD);
    }
}

// Program Loop 
void loop()
{
  if (millis() < 2000){                        // Run the Program from boot!!
    delay(2000);                               // Allow the LEDs to stay full on for 2 seconds from boot
    breathe(6);                                // Then run the Breathe routine 6 times
      } else {                                 // Then fall into a permenant Larson loop
        l2r(9);
        r2l(9);
      }
}
