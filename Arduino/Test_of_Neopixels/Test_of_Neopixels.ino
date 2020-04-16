#include <Adafruit_NeoPixel.h>
const int data_pin = 6; 
const int num_pixels = 1;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(num_pixels, data_pin, NEO_RGB + NEO_KHZ800);

void setup() {
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 256; i++) {
    pixels.setPixelColor(0, (255, 0, 250)); 
    pixels.setBrightness(i); 
    pixels.show();
    delay(75); 
  }

}
