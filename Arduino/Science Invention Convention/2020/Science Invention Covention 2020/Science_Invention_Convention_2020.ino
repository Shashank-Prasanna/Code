#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include <Arduino_LSM6DS3.h>
# include <EEPROM.h>

char auth[] = "b7wmziHT3QS7WHddjN5-2i4vA20QZV0t"; 
char ssid[] = "NETGEAR10"; // change for MHS!
char pass[] = "basicearth863"; // change for MHS!
int r = 3;
int g = 5;
int b = 10;
int on; 
int prevcase = 203; 
int curcase = 20; 
int option = 4;
float x, y, z; 
bool safety = true;
long Time; 
unsigned long then; 
unsigned long now;    

void setup() {
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600); 
  pinMode(3, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(7, INPUT); 
  Blynk.virtualWrite(V0, LOW);
  option = EEPROM.read(option);  
  for (int x = 0; x <= 255; x++) {
    analogWrite(r, x);
    delay(1); 
  }
  for (int x = 255; x >= 0; x--) {
    analogWrite(r, x);
    delay(1); 
  }
  for (int x = 0; x <= 255; x++) {
    analogWrite(g, x);
    delay(1); 
  }
  for (int x = 255; x >= 0; x--) {
    analogWrite(g, x);
    delay(1); 
  }
  for (int x = 0; x <= 255; x++) {
    analogWrite(b, x);
    delay(1); 
  }
  for (int x = 255; x >= 0; x--) {
    analogWrite(b, x);
    delay(1); 
  }
  

}

void loop() {
  check(); 
  Blynk.run();
  IMU.readAcceleration(x, y, z); 
  if (safety == true and z > 1.03 or z < 0.92) {
    Blynk.email("shashankprasanna1@gmail.com", "Extreme Movement", "The Arduino Uno WiFi Rev2"
    "has just experienced extreme movement in safety mode. It might have fallen. Go check on it! ");  
  }
}

BLYNK_APP_DISCONNECTED() { // When app is disconnected
  Serial.println("AHHHHHHHHHHHHH!"); 
  reset();
  digitalWrite(r, HIGH); 
  delay(10); 
  digitalWrite(r, LOW);
  delay(10);
  digitalWrite(r, HIGH); 
  delay(10); 
  digitalWrite(r, LOW);
  delay(10);
  digitalWrite(r, HIGH); 
  delay(10); 
  digitalWrite(r, LOW);
  delay(10);  
}
BLYNK_WRITE(V0){
  on = param.asInt(); 
  Serial.println(on); 
  if (on == 0) {
    analogWrite(r, 0);
    analogWrite(g, 0);
    analogWrite(b, 0); 
  }
}
BLYNK_WRITE(V1) { // Timer
  if (on == 1) {
    if (Time == 0) {
      Time = param[0].asLong(); // Convert the time to seconds
      then = millis(); 
    }
    if (Time != 0) {
      now = millis(); 
      if ((now-then)%1000 == 0){
        Serial.println("WHew");
      Blynk.virtualWrite(V1, then-1);      
      }
      if (now - 1000 == then) {
        Time == 0; 
        digitalWrite(r, HIGH); 
        delay(50); 
        digitalWrite(r, LOW);
        delay(50);
        digitalWrite(r, HIGH); 
        delay(50); 
        digitalWrite(r, LOW);
        delay(50);
        digitalWrite(r, HIGH); 
        delay(50); 
        digitalWrite(r, LOW);
        delay(50); 
      }
    }
  }
}

BLYNK_WRITE(V3) {
  Serial.println(param.asInt()); 
  switch (param.asInt()){
    case 1: { // RGB Sliders
      option = 1; 
      EEPROM.write(option, 1); 
      reset(); 
      break; 
    }
    case 2: { // Color Menu
      option = 2;
      EEPROM.write(option, 2); 
      reset();  
      break;
    }
    case 3: { // Both
      option = 3;
      EEPROM.write(option, 3); 
      reset();  
      break; 
    }
  }
}

BLYNK_WRITE(V4){ // Red slider
  if (on == 1 and option !=2) {
    analogWrite(r, param.asInt()); 
  }
}
BLYNK_WRITE(V5){ // Green slider
  if (on == 1 and option !=2) {
    analogWrite(g, param.asInt()); 
  }
}
BLYNK_WRITE(V6){ // Blue slider
  if (on == 1 and option !=2) {
    analogWrite(b, param.asInt()); 
  }
}

 BLYNK_WRITE(V2){ // Color Menu
  curcase = param.asInt();
  Serial.println(curcase); 
  if (curcase == 11) {
    prevcase = 1; 
  }
  if (curcase == 12) {
    prevcase = 1; 
  }
  while (on == 1 and curcase != prevcase and option != 1){
    switch (curcase) {
      case 1: { // Off
        reset(); 
        prevcase = curcase;
        break;  
      }
      case 2: { // Red
        reset(); 
        analogWrite(r, 255);
        if (option == 3) {
          Blynk.virtualWrite(V4, 255);  
        }
        prevcase = curcase;
        break;
      }
      case 3: {// Orange
        reset(); 
        analogWrite(r, 255);
        analogWrite(g, 255); 
        if (option == 3) {
          Blynk.virtualWrite(V4, 255);
          Blynk.virtualWrite(V5, 255);  
        } 
        prevcase = curcase;
        break;
      }
      case 4: { // Yellow
        reset();
        analogWrite(g, 255); 
        analogWrite(r, 71);
        if (option == 3) {
          Blynk.virtualWrite(V4, 71);
          Blynk.virtualWrite(V5, 255);  
        }
        prevcase = curcase;
        break;
      }
      case 5: { // Green
        reset();
        analogWrite(g, 255); 
        prevcase = curcase;
        if (option == 3) {
          Blynk.virtualWrite(V5, 255);  
        }
        break;
      }
      case 7: { // Blue
        reset();
        analogWrite(b, 255); 
        if (option == 3) {
          Blynk.virtualWrite(V6, 255);
        }
        prevcase = curcase;
        break;
      }
      case 6: { // Light Blue
        reset();
        analogWrite(g, 255);
        analogWrite(b, 255); 
        if (option == 3) {
          Blynk.virtualWrite(V5, 255);
          Blynk.virtualWrite(V6, 255);  
        }
        prevcase = curcase;
        break;
      }
      case 8: { // Purple
        reset();
        analogWrite(b, 40);
        analogWrite(r, 19); 
        if (option == 3) {
          Blynk.virtualWrite(V6, 40);
          Blynk.virtualWrite(V4, 19);  
        }
        prevcase = curcase;
        break;
      }
      case 9: { // Pink
        reset();
        analogWrite(b, 255);
        analogWrite(r, 255); 
        if (option == 3) {
          Blynk.virtualWrite(V4, 255);
          Blynk.virtualWrite(V6, 255);  
        }
        prevcase = curcase;
        break;
      }
      case 10: { // White
        reset();
        analogWrite(g, 255);
        analogWrite(b, 40);
        analogWrite(r, 19); 
        if (option == 3) {
          Blynk.virtualWrite(V4, 19);
          Blynk.virtualWrite(V5, 255);
          Blynk.virtualWrite(V6, 40);  
        } 
        prevcase = curcase;
        break;
      }
      case 11: { // Rainbow
        rainbow();
        prevcase = curcase;
        break;  
      }
      case 12: { // RGB Strobe
        reset(); 
        for (int x = 0; x <= 255; x++) {
          analogWrite(r, x);
          delay(1); 
        }
        for (int x = 255; x >= 0; x--) {
          analogWrite(r, x);
          delay(1); 
        }
        for (int x = 0; x <= 255; x++) {
          analogWrite(g, x);
          delay(1); 
        }
        for (int x = 255; x >= 0; x--) {
          analogWrite(g, x);
          delay(1); 
        }
        for (int x = 0; x <= 255; x++) {
          analogWrite(b, x);
          delay(1); 
        }
        for (int x = 255; x >= 0; x--) {
          analogWrite(b, x);
          delay(1); 
        }
  
      }
      default: {
        prevcase = curcase;
         break;
      }
    }
  }
}

void reset() {
  digitalWrite(r, 0);
  digitalWrite(g, 0);
  digitalWrite(b, 0); 
  Blynk.virtualWrite(V4, 0);
  Blynk.virtualWrite(V5, 0);
  Blynk.virtualWrite(V6, 0);  
}
void rainbow() {
  if (true) {
    reset(); 
    analogWrite(r, 255);
  for (int x = 0; x <= 255; x++) {
    analogWrite(g, x);
    delay(10); 
  }
  for (int x = 255; x >= 0; x--) {
    analogWrite(r, x);
    delay(10); 
  }
  for (int x = 0; x <= 255; x++) {
    analogWrite(b, x);
    delay(10); 
 }
  for (int x = 255; x >= 0; x--) {
    analogWrite(g, x);
    delay(10); 
  }
  for (int x = 0; x <= 255; x++) {
    analogWrite(r, x);
    delay(10);
  }
  for (int x = 255; x >= 0; x--) {
    analogWrite(b, x);
    delay(10); 
  }
  for (int x = 255; x >= 0; x--) {
    analogWrite(r, x);
    delay(10); 
  }
}
}

void check() {
  int state = digitalRead(7); 
  if (state == HIGH) {
    if (safety == false) {
      safety = true;
      Serial.println(safety); 
      digitalWrite(LED_BUILTIN, HIGH);
      delay(450);
    }
    else if (safety == true) {
      safety = false; 
      Serial.println(safety);
      digitalWrite(LED_BUILTIN, LOW);
      delay(450); 
    }
  }
}
