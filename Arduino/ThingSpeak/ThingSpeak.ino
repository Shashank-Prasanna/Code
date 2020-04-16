
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char ssid[] = "NETGEAR10";
const char password[] = "basicearth863";


const unsigned long channelId = 701502;
const char writeApiKey[] = "5P49Q75DZJOAYTVM";
const char readApiKey[] = "OXQEKVM7XXIX9EMQ";


WiFiClient client;


void setup() {
  // put your setup code here, to run once:

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

randomSeed(micros());


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


int myNum = ThingSpeak.readIntField(channelId, 1, readApiKey);
Serial.print("Number: ");
Serial.println(myNum);

delay(30000);


  

}
