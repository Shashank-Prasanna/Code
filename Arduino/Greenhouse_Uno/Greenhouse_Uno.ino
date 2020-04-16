#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 9
#define LED_COUNT 30
#define motorPin 10 

char auth[] = "3M7_KAqE_eksQxq4uSuATTpknVCsjrdy";
char ssid[] = "NETGEAR10";
char pass[] = "basicearth863";
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
uint32_t gLight1 = strip.Color(51, 0, 17);
uint32_t gLight2 = strip.Color(102, 0, 34);
uint32_t gLight3 = strip.Color(153, 0, 51);
uint32_t gLight4 = strip.Color(204, 0, 68);
uint32_t gLight5 = strip.Color(255, 0, 85);
int pinData; 
int pinData2; 
BlynkTimer timer; 
void (* resetFunc) (void) = 0; 
BLYNK_WRITE(V1){
  pinData = param.asInt(); // pinData variable will store value that came via Bridge
  Serial.println(pinData);
  if (pinData == 1) {
     strip.fill(gLight1, 0, 30); 
     strip.show();
  }

  else if (pinData == 2) {
     strip.fill(gLight2, 0, 30); 
     strip.show();
       
  }

  else if (pinData == 3) {
     strip.fill(gLight3, 0, 30); 
     strip.show();
       
  }
  else if (pinData == 4) {
     strip.fill(gLight4, 0, 30);
     strip.show();
       
  }
  else if (pinData == 5) {
     strip.fill(gLight5, 0, 30);
     strip.show();
       
  }
  else if (pinData == 6) {
    strip.clear();
    strip.show();  
  }
}
BLYNK_WRITE(V6){
  pinData2 = param.asInt(); 
  if (pinData2 == 1) {
    digitalWrite(motorPin, HIGH);
  }
  else if (pinData2 == 0) {
    digitalWrite(motorPin, LOW); 
  }
  Serial.println(pinData2); 
}


void setup() {
  Serial.begin(9600); 
  pinMode(motorPin, OUTPUT); 
  Blynk.begin(auth, ssid, pass);
  strip.setBrightness(127.5); 
  strip.begin(); 
  strip.show();  
  timer.setInterval(5000L, resetFunc); 

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();  
  timer.run(); 
  Blynk.syncVirtual(V1, V6); 
}





































    
