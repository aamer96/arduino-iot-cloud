#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "IoT-Cloud-Analog-Thing"
  https://create.arduino.cc/cloud/things/e90a59c8-6573-43dc-8973-0cbbf1316720 

  Arduino IoT Cloud Properties description

  The following variables are automatically generated and updated when changes are made to the Thing properties

  int pot_value;

  Properties which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#define pot_pin A1 

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  //Initialize
  pinMode(pot_p, INPUT);
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  int pot_reading = analogRead(pot_pin);
  pot_value = map(pot_reading, 0, 1023, 0, 270);
  
}



