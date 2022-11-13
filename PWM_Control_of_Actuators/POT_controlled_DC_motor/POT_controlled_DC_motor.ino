// TB6612FNG Driver Board: Control DC motor using POT

const int potAnalogPin = 0; // FSR is connected to analog 0
int potReading;      // the analog reading from the FSR resistor divider

const int pinAI1 = 7;       // Pin allocation for AI1
const int pinAI2 = 8;       // Pin allocation for AI2
const int pinPWM = 5;       // Pin allocation for the PWM pin
const int pinStandBy = 9;   // Pin allocation for the standby pin

boolean AI1 = 0;            // AI1 pin value
boolean AI2 = 0;            // AI2 pin value
boolean standBy = 0;        // standBy pin Value

int pwmValue = 0;

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
  // Read value from potentiometer
  potReading = analogRead(potAnalogPin);
  Serial.print("Analog reading : ");
  Serial.print(potReading);
   
  // we'll need to change the range from the analog reading [0-1023] to the 
  // to the pwm value. Mapping to [-255, 255] to add direction of
  // rotation data: +ve:cw, -ve: ccw
  pwmValue = map(potReading, 0, 1023, -255, 255);

  // Set the motor direction using the AI1 and AI2 control function pins
  // pwm +ve -> forward else backwards. pwm = 0 -> AI1 = AI2 = false
  AI1 = pwmValue < 0 ? true : false;
  AI2 = pwmValue > 0 ? true : false;
  
  // Set the speed of the motor by adjusting the pwmValue
  pwmValue = abs(pwmValue);
  
  // Write the AI1 and AI2 values to the configuration pins
  digitalWrite(pinAI1, AI1);
  digitalWrite(pinAI2, AI2);

  // Write the pwnValue to the PWM pin
  analogWrite(pinPWM, pwmValue);

  // Display the board variable status to the Serial Monitor
  Serial.print(" - converted to PWM : ");
  Serial.print(pwmValue);
  Serial.print(", Standby = ");
  Serial.print(standBy);
  Serial.print(", AI1 : ");
  Serial.print(AI1);
  Serial.print(", AI2 : ");
  Serial.println(AI2);

  // wait 1000ms
  delay(1000);
}
