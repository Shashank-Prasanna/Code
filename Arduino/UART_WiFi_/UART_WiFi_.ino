
#include <ESP8266WiFi.h>


const char ssid[] = "NETGEAR10";
const char password[] = "basicearth863";

const String iftttTrigger = "Reminder";
const String iftttKey = "b5EA5rVT1NDX2kliTvZpmw";


const char hostname[] = "maker.ifttt.com";
const String uri = "/trigger/" + iftttTrigger +
                   "/with/key/" + iftttKey;
const int port = 80;



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

}




void loop() {

String req = "POST " + uri + " HTTP/1.1\r\n" +
             "Host: " + hostname + "r\n" +
             "Connection: close\r\n" +
             "\r\n";


 Serial.print (" Connecting to ");
 Serial.println(hostname);

 if (client.connect(hostname, port) == 0){
  Serial.println("Connection Failed");

 }
  

client.print(req);
delay(500);


while(client.available() ) {
  String ln = client.readStringUntil('\r');
  Serial.print(ln);
  }

client.stop();
Serial.println();
Serial.println("Connection closed");


delay(60000);
           
            

} 
