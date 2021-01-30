
// Include NewPing Library for HC-SR04 sensor
#include <NewPing.h>

// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9

// Hook up 4 HC-SR04 sensors in 1-pin mode
// Sensor 0
#define TRIGGER_PIN  8
#define ECHO_PIN    8


// Maximum Distance is 260 cm
#define MAX_DISTANCE 260

// Create objects for ultrasonic sensors
NewPing sensor0(TRIGGER_PIN_0, ECHO_PIN_0, MAX_DISTANCE);

// Define return data array, one element per sensor
int distance[4];

// Define counter to count bytes in response
int bcount = 0;

void setup() {

  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);
 
   // Function to run when data requested from master
  Wire.onRequest(requestEvent); 
  
}

void requestEvent() {
 
  // Define a byte to hold data
  byte bval;
  
  // Cycle through data
  // First response is always 255 to mark beginning
  switch (bcount) {
    case 0:
      bval = 255;
      break;
    case 1:
      bval = distance[0];
      break;
    case 2:
      bval = distance[1];
      break;
    case 3:
      bval = distance[2];
      break;
    case 4:
      bval = distance[3];
      break;
  }
  
  // Send response back to Master
  Wire.write(bval);
  
  // Increment byte counter
  bcount = bcount + 1;
  if (bcount > 4) bcount = 0;

}

void readDistance()
{
  distance[0] = sensor0.ping_cm();
  if (distance[0] > 254 ) {
    distance[0] = 254;
  }
  delay(20);
}

void loop()
{
  // Refresh readings every half second
  readDistance();
  delay(500);
}
