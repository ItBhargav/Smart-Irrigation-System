#include <Servo.h>

Servo servo1;  // Servo motor 1
Servo servo2;  // Servo motor 2

int moisturePin = A0;    // Analog pin for soil moisture sensor
int threshold = 500;     // Adjust threshold based on moisture level
int moistureValue;

void setup() {
  servo1.attach(9);      // Pin connected to servo motor 1
  servo2.attach(10);     // Pin connected to servo motor 2
  Serial.begin(9600);    // Initialize serial communication
} 

void loop() {
  moistureValue = analogRead(moisturePin);  // Read moisture value
  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue < threshold) {
    // If soil is dry, turn on servo1 and turn off servo2
    servo1.write(90);   // Adjust the angle as needed
    servo2.write(0);    // Ensure servo2 is off
    Serial.println("Soil is dry, Servo 1 ON, Servo 2 OFF");
  } else {
    // If soil has enough moisture, turn off servo1 and turn on servo2
    servo1.write(0);    // Ensure servo1 is off
    servo2.write(90);   // Adjust the angle as needed
    Serial.println("Soil has moisture, Servo 1 OFF, Servo 2 ON");
  }

  delay(1000);  // Wait for 1 second before the next reading
}
