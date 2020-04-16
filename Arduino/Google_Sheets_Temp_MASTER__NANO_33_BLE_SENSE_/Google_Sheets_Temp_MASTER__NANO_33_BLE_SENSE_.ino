
#include <Wire.h>
#include <Arduino_HTS221.h>
#include <math.h>

void setup() {
//Wire.begin();
}

void loop() {
 float temperature = HTS.readTemperature(FAHRENHEIT);
 int temp = round(temperature);
 //Wire.beginTransmission(9);
 //Wire.write(temp);
 //Wire.endTransmission();
 Serial.println(temp);
 //delay(60000);
delay(500);
}
