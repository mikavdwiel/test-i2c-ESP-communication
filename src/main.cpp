#include <Arduino.h>

#include <Wire.h>

#define SDA_PIN 4  // Custom SDA pin number
#define SCL_PIN 5  // Custom SCL pin number

// // Include the required Wire library for I2C<br>#include 
// int x = 0;
// void setup() {
//   // Start the I2C Bus as Master
//   Wire.begin(SDA_PIN, SCL_PIN); 
//   Serial.begin(115200);
// }
// void loop() {
//   Wire.beginTransmission(9); // transmit to device #9
//   Wire.write(x);              // sends x 
//   Wire.endTransmission();    // stop transmitting
//   Serial.print("Sending:");
//   Serial.println(x);
//   x++; // Increment x
//   delay(1000);
// }

#include <Wire.h>
int x = 0;

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
  Serial.print("Received");
  Serial.println(x);
}

void setup() {
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9, SDA_PIN, SCL_PIN); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);
}

void loop() {
}


