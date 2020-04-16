#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include <Arduino_LSM6DS3.h>
#include <TimeLib.h>
#include <WidgetRTC.h>

char auth[] = "DXDRnW2-IR4OYscrhElQhBBvyXKOGyO6"; 
char ssid[] = "Pixel_5941"; 
char pass[] = "codersrock17901"; 
int r = 3;
int g = 5;
int b = 10;
int on; 
int prevcase = 203; 
int curcase = 20; 
int option = 4;
float x, y, z; 
bool safety = false; 
int Time; 
String answer; 
WidgetTerminal terminal(V1); 
WidgetRTC rtc;
BlynkTimer timer; 
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


void setup() {
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600); 
  pinMode(3, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(5, OUTPUT); 
  Blynk.virtualWrite(V0, LOW); 
  Blynk.virtualWrite(V4, 0);
  Blynk.virtualWrite(V5, 0);
  Blynk.virtualWrite(V6, 0);  
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
  terminal.clear(); 
  terminal.println("Connected"); 
  terminal.println(); 
  terminal.println("Write commands into the terminal. Write 'help' to get instructions in further detail"); 
  terminal.println(); 
  terminal.flush(); 

}

void loop() {
  Blynk.run();
  rtc.begin(); 
}

BLYNK_APP_DISCONNECTED() { // When app is disconnected
  Serial.println("AHHHHHHHHHHHHH!"); 
  reset();
  digitalWrite(r, HIGH); 
  delay(100); 
  digitalWrite(r, LOW);
  delay(100);
  digitalWrite(r, HIGH); 
  delay(100); 
  digitalWrite(r, LOW);
  delay(100);
  digitalWrite(r, HIGH); 
  delay(100); 
  digitalWrite(r, LOW);
  delay(100);  
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
BLYNK_WRITE(V1) { // Terminal
  String in = param.asStr(); 
  in.toLowerCase(); 
  if (String("help") == in) { 
    Serial.println("HELP"); 
    terminal.println("Type in a color to make the LED turn that color. Type on or off to turn the LED on or off. You cannot type in specific values. You can also type 'Rainbow' and 'RGB Strobe'. Type 'erase' to erase the whole terminal. Type reset to reset the color." ); 
    terminal.flush(); 
    }
  if (on == 1) {
    if (String("red") == in) {
      reset(); 
      analogWrite(r, 255);  
    }
    if (String("orange") == in) {
      reset(); 
      analogWrite(r, 255); 
      analogWrite(g, 255);  
    }
    if (String("yellow") == in) {
      reset(); 
      analogWrite(r, 71);  
      analogWrite(g, 255);
    }
    if (String("green") == in) {
      reset();  
      analogWrite(g, 255);
    }
    if (String("light blue") == in) {
      reset(); 
      analogWrite(b, 255);  
      analogWrite(g, 255);
    }
    if (String("blue") == in) {
      reset(); 
      analogWrite(b, 255);  
    }
    if (String("purple") == in) {
      reset(); 
      analogWrite(r, 40);  
      analogWrite(b, 19);
    }
    if (String("pink") == in) {
      reset(); 
      analogWrite(r, 255);  
      analogWrite(b, 255);
    }
    if (String("white") == in) {
      reset(); 
      analogWrite(r, 19);
      analogWrite(g, 255);  
      analogWrite(b, 40);
    }
    if (String("rainbow") == in) {
      reset(); 
      rainbow(); 
    }
    if (String("rgb strobe") == in) {
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
    if (String("reset") == in) { 
      reset();  
    }
    
    }
    if (String("off") == in) { 
      reset(); 
      Blynk.virtualWrite(V0, LOW);
      on = 0; 
    }
  }
  if (String("on") == in) {
    Blynk.virtualWrite(V0, HIGH);
    on = 1;  
  }
  if (String("erase") == in) {
    terminal.clear(); 
  }
}

BLYNK_WRITE(V3) {
  Serial.println(param.asInt()); 
  switch (param.asInt()){
    case 1: { // RGB Sliders
      option = 1;  
      reset(); 
      break; 
    }
    case 2: { // Color Menu
      option = 2; 
      reset();  
      break;
    }
    case 3: { // Both
      option = 3;
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
