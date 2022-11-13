
 
int IRAnalogPin = 1; // IR is connected to analog 1
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int IRReading;      // the analog reading from the IR sensor
int LEDbrightness;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
}
 
void loop(void) {
  IRReading = analogRead(IRAnalogPin);
  Serial.print("Analog reading = ");
  Serial.print(IRReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness = map(IRReading, 0, 650, 0, 255);
  
  // LED gets brighter the closer you are to the IR sensor
  analogWrite(LEDpin, LEDbrightness); // here you are using PWM !!!

  Serial.print(", LED brightness = ");
  Serial.println(LEDbrightness);
 
  delay(10);
}
