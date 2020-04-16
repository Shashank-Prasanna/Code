#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
// for Blynk
#include <Arduino_MKRENV.h>
// For the ENV Shield
#include "Adafruit_seesaw.h"
#include <WidgetRTC.h>
#include <TimeLib.h>



char auth[] = "m75G4j6VeWMMFPCdsQStNuLcD8CAYcKP"; 
char ssid[] = "NETGEAR10/";
char pass[] = "basicearth863";
// Blynk credentials
int temperature; 
int illuminance;
int water;  
bool pumpState = false; 
unsigned long whenWater = 0; 
unsigned long Now; 


BlynkTimer timer;
WidgetBridge bridge1(V1); 
WidgetBridge bridge2(V6); 
WidgetLED led(V2); 
WidgetRTC rtc; 
Adafruit_seesaw ss;

void(* resetFunc) (void) = 0;


void Sensor() {
  water = analogRead(A1); 
  if (water == 0 and pumpState == false) { 
    Now = millis();
    if (Now - 60000 >= whenWater and pumpState == true) {
      Blynk.setProperty(V2, "color", "#23C48E"); 
      led.on(); 
    }
  }
  else if (water != 0) {
    Blynk.setProperty(V2, "color", "#D3435C"); 
    whenWater = millis();
  }
  
  temperature = ENV.readTemperature(FAHRENHEIT);
  Blynk.virtualWrite(V0, temperature - 5); 
  
  illuminance = ENV.readIlluminance(LUX);
  Serial.println(illuminance);
  Blynk.virtualWrite(V4, illuminance); 
  
  if (illuminance < 1400 and illuminance >1300) {
    bridge1.virtualWrite(V1, 1); 
  }
  
  else if (illuminance < 1300 and illuminance > 1200) {
    bridge1.virtualWrite(V1, 2);
  }
  
  else if (illuminance < 1200 and illuminance > 1100) {
    bridge1.virtualWrite(V1, 3);
  }
  
  else if (illuminance < 1100 and illuminance > 1000) {
    bridge1.virtualWrite(V1, 4);
  }
  
  else if (illuminance < 1000 and illuminance > 900) {
    bridge1.virtualWrite(V1, 5);
  }
  else if (illuminance > 1400) {
    bridge1.virtualWrite(V1, 6); 
  }
  else if (illuminance < 900) {
    bridge1.virtualWrite(V1, 5);  
  }
}

void Pour() {
  if (hour() == 19) {
      if (minute() == 0) {
        bridge2.virtualWrite(V6, 1); 
        pumpState = true; 
      }
      else if (minute() == 2) {
        bridge2.virtualWrite(V6, 0); 
        pumpState = false; 
      }
      }
  }


BLYNK_CONNECTED() {
  rtc.begin(); 
}

void setup() {
  
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass); 
  bridge1.setAuthToken("3M7_KAqE_eksQxq4uSuATTpknVCsjrdy");
  bridge2.setAuthToken("3M7_KAqE_eksQxq4uSuATTpknVCsjrdy");  
  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }
  else {
    Serial.println("Got 'em!"); 
  }
  if (!ss.begin(0x36)) {
    Serial.println("ERROR! seesaw not found");
    while(1);
  } else {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }
  timer.setInterval(2000L, Sensor); 
  timer.setInterval(1000L, Pour); 
  timer.setInterval(15000L, resetFunc); 
  setSyncInterval(2*60);   
  bridge2.virtualWrite(V6, 0); 
  }
  

void loop() { 
  Blynk.run();
  timer.run(); 
}
















  
