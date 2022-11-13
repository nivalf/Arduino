// TB6612FNG Driver Board Sample board
//
// Author: Ben Taylor
// University of Sheffield
// Date: September 2021

//
const int pinAI1 = 7;       // Pin allocation for AI1
const int pinAI2 = 8;       // Pin allocation for AI2
const int pinPWM = 5;       // Pin allocation for the PWM pin
const int pinStandBy = 9;   // Pin allocation for the standby pin


boolean AI1 = 0;            // AI1 pin value
boolean AI2 = 0;            // AI2 pin value
boolean standBy = 0;        // standBy pin Value

boolean rotDirect = 0;      // Rotation direction variable
unsigned char pwmValue = 0; // PWM value to be written to the output

void setup()
{
  // Assign the digital I/O pin directions
  pinMode(pinAI1, OUTPUT);
  pinMode(pinAI2, OUTPUT);
  pinMode(pinPWM, OUTPUT);
  pinMode(pinStandBy, OUTPUT);


  //Initialize the serial port
  Serial.begin(9600);

  // Drive the standby pin high to enable the output
  standBy = true;
  digitalWrite(pinStandBy, standBy);

  // Set Initial values for AI1 and AI2 control function pins
  AI1 = true;
  AI2 = false;

  // set an initial value for the PWM value
  pwmValue = 100;
}

void loop()
{

  // Set the motor direction using the AI1 and AI2 control function pins
  AI1 = true;
  AI2 = false;
  
  // Set the speed of the motor by adjusting the pwmValue
  pwmValue = 50;
  
  // Write the AI1 and AI2 values to the configuration pins
  digitalWrite(pinAI1, AI1);
  digitalWrite(pinAI2, AI2);

  // Write the pwnValue to the PWM pin
  analogWrite(pinPWM, pwmValue);

  // Display the board variable status to the Serial Monitor
  Serial.print("PWM output value = ");
  Serial.print(pwmValue);
  Serial.print(", Standby = ");
  Serial.print(standBy);
  Serial.print(", AI1 = ");
  Serial.print(AI1);
  Serial.print(", AI2 = ");
  Serial.println(AI2);

  // wait 2000ms
  delay(2000);
  
    // Reverse the Motor
  AI1 = false;
  AI2 = true;
  
  // Change the speed of the motor 
  pwmValue = 250;
  
    // Write the AI1 and AI2 values to the configuration pins
  digitalWrite(pinAI1, AI1);
  digitalWrite(pinAI2, AI2);

  // Write the pwnValue to the PWM pin
  analogWrite(pinPWM, pwmValue);

  // Display the board variable status to the Serial Monitor
  Serial.print("PWM output value = ");
  Serial.print(pwmValue);
  Serial.print(", Standby = ");
  Serial.print(standBy);
  Serial.print(", AI1 = ");
  Serial.print(AI1);
  Serial.print(", AI2 = ");
  Serial.println(AI2);

  // wait 2000ms
  delay(2000);
}
