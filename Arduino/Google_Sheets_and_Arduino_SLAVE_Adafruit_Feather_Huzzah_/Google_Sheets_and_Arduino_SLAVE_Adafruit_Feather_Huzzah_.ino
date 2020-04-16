
#include <Wire.h>                                       
//#include "config.h"
//AdafruitIO_Feed *Temperature  = io.feed("Temperature");
int x = 0;
void setup() {
  Serial.begin(9600);
  Wire.begin(9);
 // io.connect();
}
void loop() {
 // io.run();
  x = Wire.read();
  //Temperature->save(x);

  Serial.println(x);
  //delay(3000);

}
