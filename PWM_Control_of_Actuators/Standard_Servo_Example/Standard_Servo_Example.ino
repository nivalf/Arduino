// This Example code is for use with the Controlling a Standard Servomotor exercise
//

// Include the servo library to allow for connection and control of servo motors
#include <Servo.h>

// define the macro pinServo1 as 9, to use for connecting the servo to pin 9
#define pinServo1 9

// Declare a servo motor class variable servo 1
Servo servo1;

// -------------------------------------
// Setup function
void setup()
{
  // "attach"  servo 1 to the defined pin
  servo1.attach(pinServo1);

  // set the neutral, centre, position for the servo
  servo1.write(90);

  // Alternte command for setting the neutral position
  //servo1.writeMicroseconds(1500);

  // wait until the servo has moved into position, (1000ms is more time than needed)
  delay(1000);
}

// -------------------------------------
// Loop Function
void loop()
{
  // start from the nuetral position, (90 degrees from the fully clockwise position)
  servo1.write(90);
  //servo1.writeMicroseconds(1500);  // Alternate Command

  // wait until the servo has moved into position
  delay(1000);

  // move to  0 degrees, (fully clockwise)
  servo1.write(0);
  //servo1.writeMicroseconds(500);  // Alternate Command

  // wait until the servo has moved into position
  delay(1000);

  // move to 180 degrees, (fully anti cloclwise position)
  servo1.write(180);
  //servo1.writeMicroseconds(2500);  // Alternate Command

  // wait until the servo has moved into position
  delay(1000);

}
