// This is the WiFi Braccio Controller Arduino code. It uses the Blynk
// IOT app. This is version 1.0. Have Fun!
//Do NOT OVERWORK servos. Unless it's an emergency(SOS*), keep SafeStop ON AT ALL TIMES! 
//*Save our servos!


#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include <BraccioRobot.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b7wmziHT3QS7WHddjN5-2i4vA20QZV0t";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "NETGEAR10";
char pass[] = "basicearth863";
int M1;
int M2;
int M3;
int M4;
int M5; 
int M6;
int Speed = 1;
int state = 0;
bool Connect;
int on = 0;      
Position myInitialPosition(120, 130, 160, 80, 45, 73);

// Reads the sliders and sets the motors
BLYNK_WRITE(V0) {
  M1 = param.asInt();
  Serial.print(M1);
}
BLYNK_WRITE(V1) {
  M2 = param.asInt();  
  Serial.println(M2);
}
BLYNK_WRITE(V2) {
  M3 = param.asInt();
  Serial.println(M3);
}
BLYNK_WRITE(V3) {
  M4 = param.asInt();
  Serial.println(M4);
}
BLYNK_WRITE(V4) {
  M5 = param.asInt();
  Serial.println(M5);
}
BLYNK_WRITE(V5) {
  M6 = param.asInt();
  Serial.println(M6);
}
BLYNK_WRITE(V7) {
  state = param.asInt();
}
BLYNK_WRITE(V8) {
  Speed = param.asInt();
}



void setup() {
  Serial.begin(9600);
  BraccioRobot.powerOn();
  BraccioRobot.init(myInitialPosition);
  Blynk.begin(auth, ssid, pass);
  Blynk.virtualWrite(V0, 120);
  Blynk.virtualWrite(V1, 130);
  Blynk.virtualWrite(V2, 160);
  Blynk.virtualWrite(V3, 80);
  Blynk.virtualWrite(V4, 45);
  Blynk.virtualWrite(V5, 73);
}

void loop() {
  Blynk.run();
  if (state == 0 and on == 0){
    BraccioRobot.moveToPosition(myInitialPosition.setGripper(73),30);
    BraccioRobot.powerOff();
    Serial.print("XCode");
    on = 1; 
  }
  if (state == 1 and on == 1){
    BraccioRobot.powerOn();
    on = 0; 
}
  Position posit(M1, M2, M3, M4, M5, M6);
  BraccioRobot.moveToPosition(posit.setGripper(M6), Speed); 
}
