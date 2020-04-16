
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;


void setup() {

 lcd.begin(16,2);
 pinMode(switchPin,INPUT);
 

}

void loop() {

  switchState = digitalRead(switchPin);

  if (switchState == LOW) {
    lcd.print("Merry Christmas!");
    lcd.setCursor(0,1);
    lcd.print("Press Button NOW");
  }

  if (switchState == HIGH) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Step 1:");
    lcd.setCursor(0,1);
    lcd.print("Cut the tape");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Step 2:");
    lcd.setCursor(0,1);
    lcd.print("Open box. Enjoy!");
    delay(100000000);
    
    
  }

}
