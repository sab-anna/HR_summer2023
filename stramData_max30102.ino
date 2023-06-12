#include <Wire.h>
#include "MAX30105.h"
MAX30105 sensor;
void setup() {
  
  Serial.begin(115200);
  
  if (sensor.begin() == false)
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  sensor.setup();

}

void loop() {
  Serial.println(sensor.getRed());
  delay(50);
  
}
