/* MAP ANGLE OF POTENTIOMETER KNOB
  This program prints the angle of the potentiometer knob to the serial monitor
  - map function is used to map the reading from potentiometer to [-150,150]
*/
 
const int potAnalogPin = 0; // FSR is connected to analog 0
int potReading;      // the analog reading from the FSR resistor divider
int potAngle;        // the calculated potentiometer knob's angle

void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  // Potentiometer is connected to A0 (analog input)
  // It is not required to declare the pinMode for analog input for the values to be read from.
}
 
void loop(void) {
  potReading = analogRead(potAnalogPin);
  Serial.print("Analog reading = ");
  Serial.print(potReading);
 
  // we'll need to change the range from the analog reading (0-1023) to the 
  // angle of the potentiometer knob. Since the knob can turn 300 degrees,
  // we map the potentiometer reading to [-150,150].
  potAngle = map(potReading, 0, 1023, -150, 150);

  // Output
  Serial.print(", Potentiometer angle= ");
  Serial.println(potAngle);
 
  delay(300);
}
