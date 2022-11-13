
 
const int potAnalogPin = 0; // FSR is connected to analog 0
const int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int potReading;      // the analog reading from the FSR resistor divider
int LEDbrightness;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
}
 
void loop(void) {
  potReading = analogRead(potAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(potReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness = map(potReading, 0, 1023, 0, 255);
  
  // LED gets brighter the harder you press
  analogWrite(LEDpin, LEDbrightness); // here you are using PWM !!!
 
  delay(10);
}
