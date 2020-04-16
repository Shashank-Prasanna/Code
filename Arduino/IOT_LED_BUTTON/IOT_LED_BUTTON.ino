#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char ssid[] = "NETGEAR10";
const char password[] = "basicearth863";
const int basePin = 4;

const unsigned long channelId = 701607;
const char writeApiKey[] = "070UY9AAZRWGJZ01";
const char readApiKey[] = "9SOTAZDUDVOBFN0V";


WiFiClient client;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(basePin, OUTPUT);
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
  // put your main code here, to run repeatedly:
int myNum = ThingSpeak.readIntField(channelId, 2, readApiKey);
Serial.println(myNum); 

 if (myNum == 1) {
    digitalWrite(basePin, HIGH);
  Serial.println("On!");
      
    }
  

  if (myNum == 0) {
    digitalWrite(basePin, LOW);
  Serial.println("Off");
      
    }
  


    
 
}
