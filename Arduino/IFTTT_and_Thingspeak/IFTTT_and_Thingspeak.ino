
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const int red = 15;
const int blue = 0;
const int green = 16;
const char ssid[] = "NETGEAR10";
const char password[] = "basicearth863";


const unsigned long channelId = 938015;  //Neopixel Channel
const char writeApiKey[] = "86TLMHB3729ZHFAF";
const char readApiKey[] = "8RW51DGC5X996G5M";


WiFiClient client;


void setup() {
  // put your setup code here, to run once:

pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
Serial.begin(9600);
delay(100);

  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }

Serial.println();


Serial.println("Connected!");

ThingSpeak.begin(client);


}

void loop() {
/*Write to ThingSpeak
 * 
 * 
int rando = random(1,101);

Serial.println("Posting " + String(rando) + " To ThingSpeak");
ThingSpeak.setField(1, rando);
ThingSpeak.writeFields(channelId, writeApiKey);
delay(30000);
*/

int Red = ThingSpeak.readIntField(channelId, 1, readApiKey);
int Green = ThingSpeak.readIntField(channelId, 2, readApiKey);
int Blue = ThingSpeak.readIntField(channelId, 3, readApiKey);
int State = ThingSpeak.readIntField(channelId, 4, readApiKey);
Serial.println(Red);
Serial.println(Green);
Serial.println(Blue);
Serial.println(State);
if (State == 1) {
  showColor(Red, Green, Blue);
}
if (State == 0) {
  showColor(0, 0, 0);
}
}

void showColor(byte r, byte g, byte b) {
  digitalWrite(red, r);
  digitalWrite(green, g);
  digitalWrite(blue, b);
}
