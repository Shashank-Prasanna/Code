#include <Arduino_MKRENV.h>
#include "config.h"

AdafruitIO_Feed *Humidity = io.feed("Humidity");
AdafruitIO_Feed *light_intensity = io.feed("light_intensity");
AdafruitIO_Feed *pressure = io.feed("pressure");
AdafruitIO_Feed *Temperature = io.feed("Temperature");

float temperature = 0; 
float Light_intensity = 0; 
float Pressure = 0; 
float humidity = 0; 

void setup() {
  io.connect(); 
  Serial.begin(9600);
  while (!Serial);

  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }
  Humidity->get();
  light_intensity->get();
  pressure->get();
  Temperature->get();
  
}

void loop() {
  io.run(); 
  // Passing in FAHRENHEIT as the unit parameter to ENV.readTemperature(...),
  // PSI to readPressure(...) and FOOTCANDLE to readIlluminance(...)
  // allows you to read the sensor values in imperial units
  temperature = ENV.readTemperature(FAHRENHEIT);
  humidity = ENV.readHumidity();
  Pressure = ENV.readPressure(PSI);
  Light_intensity = ENV.readIlluminance(FOOTCANDLE);

  Temperature->save(temperature);
  Humidity->save(humidity);
  light_intensity->save( Light_intensity);
  pressure->save(Pressure); 

  // print each of the sensor values
  /*Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °F");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure    = ");
  Serial.print(pressure);
  Serial.println(" psi");

  Serial.print("Illuminance = ");
  Serial.print(illuminance);
  Serial.println(" fc");
  */


  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}
