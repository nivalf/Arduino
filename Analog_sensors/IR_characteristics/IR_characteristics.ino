// Characteristic curve of IR Sensor
/* The aim of this experiment is to obtain the characteristic curve
  of the IR sensor by measuring IR values at certain fixed distances. 
  The readings are recorded against the distance measured to create a 
  table and a graph is plotted with these values to which will 
  represent the characteristic curve of the IR sensor
*/
 
int IRAnalogPin = 1; // IR is connected to analog 1
int IRReading;      // the analog reading from the IR sensor
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
}
 
void loop(void) {
  IRReading = analogRead(IRAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(IRReading);
 
  delay(100);
}
