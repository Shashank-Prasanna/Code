
#include <Adafruit_NeoPixel.h>

const int dataPin = 4; 
const int numPixels = 1; 


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, dataPin, NEO_RGB+ NEO_KHZ800); 

void setup() {
  pixels.begin(); 
  pixels.setPixelColor(); 


}

void loop() {


}








(strip.Color(127, 127, 127), 50);
