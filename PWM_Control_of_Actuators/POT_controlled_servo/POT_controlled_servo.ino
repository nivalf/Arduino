/* MAP ANGLE OF POTENTIOMETER KNOB TO SERVO
  This program maps the potentiometer knob angle to servo angle
  Both angles are printed to the serial monitor
  - map function is used to map the reading from 
    potentiometer [0, 1023] to [-150,150]
  - this is then mapped to servo angle [180, 0]
*/
 
// Include the servo library to allow for connection and control of servo motors
#include <Servo.h>

// define the macro pinServo1 as 9, to use for connecting the servo to pin 9
#define pinServo1 9
#define potAnalogPin 0

// Declare a servo motor class variable servo 1
Servo servo1;

int servoAngle;     // The mapped servo angle

int potReading;      // the analog reading from the FSR resistor divider
int potAngle;        // the calculated potentiometer knob's angle

void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  // Potentiometer is connected to A0 (analog input)
  // It is not required to declare the pinMode for analog input for the values to be read from.
  
  // "attach"  servo 1 to the defined pin
  servo1.attach(pinServo1);
}
 
void loop(void) {
  potReading = analogRead(potAnalogPin);
  Serial.print("Pot Analog reading : ");
  Serial.print(potReading);
 
  // we'll need to change the range from the analog reading (0-1023) to the 
  // angle of the potentiometer knob. Since the knob can turn 300 degrees,
  // we map the potentiometer reading to [-150,150].
  potAngle = map(potReading, 0, 1023, -150, 150);

  // Now the potAngle [-150, 150] is mapped to [180, 0] servo angle 
  // 180 - 0 to align the direction of rotation (cw & ccw)
  servoAngle = map(potAngle, -150, 150, 180, 0);

  // Output
  Serial.print(", Potentiometer angle : ");
  Serial.print(potAngle);
  Serial.print(", Servo angle : ");
  Serial.println(potAngle);
 
  servo1.write(servoAngle);

  // wait until the servo has moved into position
  delay(1000);
}
