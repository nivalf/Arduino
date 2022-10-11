/*
  Blink

  Turns an LED on for some time, then turns it off repeatedly. The time delay
  is a series of values.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // Open the Serial port at 9600 bps
  Serial.begin(9600);
}

int loop_count = 1;

// the loop function runs over and over again forever
void loop() {
  int onTime = abs(500 + loop_count * 100) % 1000;
  int offTime = abs(500 - loop_count * 100) % 1000;

  digitalWrite(LED_BUILTIN , HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(onTime);                       // on Time
  digitalWrite(LED_BUILTIN , LOW);    // turn the LED off by making the voltage LOW
  delay(offTime);                       // off Time
  
  loop_count++;
  Serial.println(onTime);
}
