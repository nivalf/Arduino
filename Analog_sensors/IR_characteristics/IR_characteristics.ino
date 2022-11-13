// Characteristic curve of IR Sensor
/* The aim of this experiment is to obtain the characteristic curve
  of the IR sensor by measuring IR values at certain fixed distances. 
  The readings are recorded against the distance measured to create a 
  table and a graph is plotted with these values to which will 
  represent the characteristic curve of the IR sensor
*/
 
int IRAnalogPin = 1; // IR is connected to analog 1
int DistReading;      // the analog reading from the IR sensor
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
}
 
void loop(void) {
  // Averaging to reduce the effect of noise
  float DistReading = 0;
  int a=50;
  for (int n = 0; n < a; n++) {
    DistReading = DistReading + (float)analogRead(IRAnalogPin);
    delay(2);
  }
  DistReading = DistReading / (float)a;

  Serial.print("Analog reading = ");
  Serial.println(DistReading);
 
  delay(100);
}
