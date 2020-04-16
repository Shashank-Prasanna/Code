
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

lcd.begin(16,2);
  

}

void loop() {
  
 
  lcd.print("Hello");
  lcd.scrollDisplayRight();
  delay(500);
  lcd.scrollDisplayRight();
  delay(500);
  lcd.scrollDisplayRight();
  delay(500);
   lcd.scrollDisplayRight();
  delay(500);
   lcd.scrollDisplayRight();
  delay(500);
   lcd.scrollDisplayRight();
  delay(500);
   lcd.scrollDisplayRight();
  delay(500);
   lcd.scrollDisplayRight();
  delay(500);
   lcd.scrollDisplayRight();
  delay(500);
   lcd.scrollDisplayRight();
  delay(500);
  lcd.clear();
  
  }


// lcd.scrollDisplayRight();
// For more information, go to www.Arduino.cc/lcd
