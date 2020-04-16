 #include <Adafruit_NeoPixel.h>
 #define LED_PIN 6
 #define LED_COUNT 30

 Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); 
 
 void setup() {
  strip.begin(); 
  strip.show(); 

}

void loop() {
  for(int i = 0; i <= 30; i++) {
    strip.setPixelColor(i, 191.25, 0, 63.75); 
    strip.show(); 
    delay(30); 
  }
  strip.clear(); 

}
