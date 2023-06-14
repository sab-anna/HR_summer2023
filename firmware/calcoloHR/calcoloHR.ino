#include <Wire.h>
#include "MAX30105.h"

int dataOld=0;
long int currentTime, lastTime;
float HR;
MAX30105 sensor;

void setup() {
  Serial.begin(115200);
  if (sensor.begin() == false){
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);}
  sensor.setup();
}

void loop() {
  int data=sensor.getRed();
  int delta=data-dataOld;
  currentTime=millis(); 
  if (delta < -50 && currentTime-lastTime> 500){
      HR=60.0/(currentTime-lastTime)*1000;
      lastTime=currentTime;
      //Serial.println(HR);
  }
  Serial.print(delta);
  Serial.print(" ");
  Serial.println(HR);
  dataOld=data;
  delay(50);
  
}

