//https://www.digikey.com/en/maker/blogs/2021/detect-obstacles-with-an-arduino-using-an-ir-sensor-and-led

#define IR_RECV_PIN 3
#define IR_SEND_PIN 2

unsigned long send_time = 0UL;
unsigned long recv_time = 0UL;

// Function prototypes
void falling_edge_detected(void);
void wait(unsigned long milliseconds);
void pulse_LED(int led_pin, unsigned long duration);

void setup()
{
  // Initialize the serial monitor. use a baud rate of 9600 bps
  Serial.begin(9600);

  // Initialize the I/O pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IR_SEND_PIN, OUTPUT);
  pinMode(IR_RECV_PIN, INPUT);

  // Attach an interrupt to the IR receiver's data pin
  // The purpose of this is that the Arduino is going to call the falling_edge_detected
  // method whenever it detects that the IR receiver outputs a LOW signal instead of HIGH
  attachInterrupt(digitalPinToInterrupt(IR_RECV_PIN), falling_edge_detected, FALLING);
 
  Serial.print("Ready!");
}

void falling_edge_detected(void)
{
  recv_time = millis();
}

void pulse_LED(int led_pin, unsigned long duration)
{
  digitalWrite(IR_SEND_PIN, HIGH);

  wait(10);

  digitalWrite(IR_SEND_PIN, LOW);

  wait(10);
}

void wait(unsigned long milliseconds)
{
  unsigned long start = millis();

  while(millis() - start < milliseconds);
}

void loop()
{
  // Get the time just before sending out the pulse over the IR LED
  send_time = millis();
  // Pulse the IR LED on and off for 10ms (10ms on, 10ms off)
  pulse_LED(IR_SEND_PIN, 10);

  // When the sensor can see the LED (i.e. there's no obstacle between the sensor and the LED)
  // Then the interrupt method will record the current send time and d contains a positive number
  // that describes how long it took until the sensor could see the short pulse of the LED
  // This number is typically small (practically always very close to zero).
  unsigned long d = recv_time - send_time;

  // Then check whether the sensor detected the pulse 'in time'.
  if(recv_time >= send_time && d <= 2)
  {
	Serial.print(send_time);
	Serial.print(", ");
	Serial.print(recv_time);
	Serial.print(", ");
	Serial.println(d);
	digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
	Serial.println("Obstacle detected!");
	digitalWrite(LED_BUILTIN, HIGH);
  }

  // Wait before performing the next check
  wait(250);
}
