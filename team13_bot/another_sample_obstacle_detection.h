// https://theorycircuit.com/arduino-ir-sensor-obstacle-detection/

/* Arduino IR Sensor Obstacle Detection Code
 *  www.theorycircuit.com  
 *  Analog Mode Code
 */
int LED = 13; // Onboard LED for Detection Indication
 
void setup() {
pinMode(LED, OUTPUT);
Serial.begin(9600);
}
void loop() {
int sensorValue = analogRead(A0); // Analog A0 Pin as Input pin (Connect IRmodule Out - A0) 
Serial.println(sensorValue);
delay(100);
if (sensorValue>200)
{
Serial.print("OBSTACLE DETECTED...!");
digitalWrite(LED, HIGH);
}
else
{
Serial.print("no obstacle");
digitalWrite(LED, LOW);
}
delay(200);
}

/* Arduino IR Sensor Obstacle Detection Code
 *  www.theorycircuit.com  
 *  Digital Mode Code
 */
int LED = 13; // Onboard LED for Detection Indication
int IRsensorPin = 2; // Naming Digital Pin 2 
void setup() {
pinMode(LED, OUTPUT);
pinMode(IRsensorPin, INPUT); // Digital 2 Pin as Input pin (Connect IRmodule Out - 2) 
Serial.begin(9600);  // initialize serial communication at 9600 bits per second:
}
void loop() {
int IRsensorVal = digitalRead(IRsensorPin); 
Serial.println(IRsensorVal);
delay(100);
if (IRsensorVal==1)
{
Serial.print("OBSTACLE DETECTED...!");
digitalWrite(LED, HIGH);
}
else
{
Serial.print("no obstacle");
digitalWrite(LED, LOW);
}
delay(200);
}
