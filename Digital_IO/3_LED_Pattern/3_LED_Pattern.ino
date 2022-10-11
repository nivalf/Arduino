/*
  3-LED Pattern

  This program create a changing sequence of LEDs.The pattern on the LEDs 
  are changed at fixed time steps, e.g. every 0.5s, and loop through a 
  non-random sequence. An example of a non-random sequence could be counting 
  up in binary.

  Created on 12 Oct 2022 by Flavin Lee John.
*/

// Pins to which LEDs are connected
const int LED_COUNT = 3;
int LedPins [LED_COUNT] = {2, 3, 4};

// Counter
int counter = 0;

void setup() {
  // Open the Serial port at 9600 bps
  Serial.begin(9600);

  // put your setup code here, to run once:
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(i+2, OUTPUT);     // Start from pin 2
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < LED_COUNT; i++) {
    // bitRead reads i-th lsb from the counter integer
    digitalWrite(i+2, bitRead(counter,i));
  }

  // Hold
  delay(500);

  // Counter: Count till 7 then reset to 0;
  counter = (counter + 1) % 8;
  // Serial.println(counter);
}
