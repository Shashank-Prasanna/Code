
#include "config.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(14, 12, 15, 13, 0, 2); 

int Temperature; 
String Condition;
int Length; 
int tempLen;
int posit = 16; 
bool left = true; 

byte degree[8] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
};

AdafruitIO_Group *weather = io.group("weather");

void setup()  {
  Serial.begin(115200); 
  Serial.println("Hi!"); 
  io.connect(); 
  weather->onMessage("weather.temperature", handleTempNow);
  weather->onMessage("weather.condition", handleConditionNow);
  lcd.begin(16, 2); 
  lcd.setCursor(1, 0); 
  lcd.createChar(0, degree); 
  lcd.print("Connecting...");  
  while(io.mqttStatus() < AIO_CONNECTED) {
    delay(500);  
  }
  weather->get();
}


void loop() {
  io.run();
  Button();   
}

void handleTempNow (AdafruitIO_Data *data) {
  Temperature = data->toInt();  
}

void handleConditionNow (AdafruitIO_Data *data) {
  Condition = data->toString(); 
}

void Button() { 
  lcd.clear(); 
  if (Temperature > 99) {
    tempLen = 3; 
  }
  else if (Temperature < 10) {
    tempLen = 1 ;
  }
  else {
    tempLen = 2; 
  }
  Length = Condition.length() + tempLen + 4; 
  if (Length <= 16) {
    lcd.print(Condition);
    lcd.print("  "); 
    lcd.print(Temperature); 
    lcd.write(byte(0)); 
    lcd.print("F");
  }
  else if (Length - posit > 0 and left == true) {
    lcd.print(Condition);
    lcd.print("  "); 
    lcd.print(Temperature); 
    lcd.write(byte(0)); 
    lcd.print("F");
    lcd.scrollDisplayLeft();
    delay(500);  
  }

  else if (Length - posit == 0) {
    delay(500);
    left = false;  
  }
  else if (Length - posit >= 0 and left == false) {
    lcd.print(Condition);
    lcd.print("  "); 
    lcd.print(Temperature); 
    lcd.write(byte(0)); 
    lcd.print("F");
    lcd.scrollDisplayRight();
  }
}
