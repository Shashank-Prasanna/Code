#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <Adafruit_SleepyDog.h>
#define BLYNK_GREEN "#23C48E"
#define BLYNK_RED "#D3435C"
#define BLYNK_YELLOW "#ED9D00"
#define BLYNK_PRINT Serial 


// Sensor Order: From left to right when looking at the sensors directly: Ultra1, PIR, Ultra2. 
// The credentials for Wi-Fi and Blynk:
char auth[] = "ngsCZFQnFcKgl_szH5p2qK0BnPUFa7s6"; 

char ssid[] = "NETGEAR10"; 
char pass[] = "basicearth863";
//The variables for basic person counting
int peopleIn = 0; 
int threshold;
int availableSlots;  
int buzzerState = 0; //state of the buzzer, 0 for off, 1 for on 
String dir = "null"; 

//The pin definitions for the LEDs
int redLed = 3; //stop led
int greenLed = 4;//go led
int lowLed = 7; //low battery led
int chargedLed = 6; //good battery led 

//More definitions, this time booleans
bool tooManyState = false; 
bool canGo = true; 
int timerState = 1; 

// the following are integers for the PIR sensor
int pirPin = 2; 
int pirState = LOW; 
int pirVal = 0; 
bool Person = false; 

//the following are integers for both Ultra1 and Ultra2
const int trigDelay = 25; // 25 Microseconds
int rxPin = 1; 

//The following are integers for Ultra1
float cmLeft = 0;  

//The following are for Ultra2 
float cmRight = 0;  

//The following are for the battery and the PowerBoost 500C
int batPin = 8; 
int batState = HIGH; 

WidgetLED batLed(V5);
Adafruit_LiquidCrystal lcd(0);  
BlynkTimer timer; 
WidgetTerminal terminal(V3); 


 void setup() {
  Serial.begin(9600);
  //Pin mode 
  pinMode(redLed, OUTPUT); 
  pinMode(greenLed, OUTPUT);
  pinMode(batPin, INPUT);  
  pinMode(lowLed, OUTPUT); 
  pinMode(chargedLed, OUTPUT); 
  pinMode(rxPin, OUTPUT); 
  //set both Go and Stop leds to HIGH
  digitalWrite(redLed, HIGH); 
  digitalWrite(greenLed, HIGH); 
  lcd.begin(16, 2); 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("People: ");
  //Delay a few to calibrate the PIR sensor, may still be erratic after but only for a minute or two. 
  //connects to Blynk
  digitalWrite(rxPin, HIGH); 
  delay(1); 
  digitalWrite(rxPin, LOW); 
  Blynk.begin(auth, ssid, pass);
  Serial.println("All systems go!");    
  Serial.println("Check 1"); 
  Serial.println("Check 1.5");  
  digitalWrite(redLed, LOW); 
  digitalWrite(greenLed, LOW); 
  Serial.println("Check 2");  
  Serial.println("Check 3");  
  Battery(); 
  Serial.println("Check 4"); 
  Blynk.syncVirtual(V2); 
  availableSlots = threshold - peopleIn; 
  Blynk.virtualWrite(V0, peopleIn); 
  Blynk.virtualWrite(V1, availableSlots);
  terminal.clear(); 
  terminal.println("************************");  
  terminal.println("Initialized And Connected!");
  terminal.flush(); 
  timer.setInterval(300000L, Battery); 
  timer.setInterval(100L, Sense); 
  int countdownMS = Watchdog.enable(10000);
  lcd.print(peopleIn);  
  lcd.print("/"); 
  lcd.print(threshold); 
  lcd.print("   ");  
  lcd.setCursor(0, 1); 
  lcd.print("6 Feet Apart!");
}
void loop() {
  Blynk.run(); 
  timer.run(); 
  Watchdog.reset();
}

BLYNK_WRITE(V4) {
  timerState = param.asInt(); 
}
BLYNK_WRITE(V0){
  if (timerState == 1) {
    peopleIn = param.asInt(); 
    availableSlots = threshold - peopleIn; 
    Blynk.virtualWrite(V1, availableSlots); 
    tooMany(); 
    lcd.setCursor(8,0);  
    lcd.print(peopleIn);  
    lcd.print("/"); 
    lcd.print(threshold);
    lcd.print("   ");  
  }
}
BLYNK_WRITE(V3) {
  String termIn;
  termIn = param.asStr(); 
  termIn.toLowerCase();
  if (String("clear terminal") == termIn) {
    terminal.clear(); 
    terminal.flush(); 
  }
  else if (String("battery check") == termIn) {
    terminal.println("Checking..."); 
    terminal.flush(); 
    Battery(); 
    if (batState == LOW) {
      terminal.println("Battery Low! Recharge soon."); 
       terminal.flush(); 
    }
    else if (batState == HIGH) {
      terminal.println("Battery Charged!");
      terminal.flush();  
    }
  }
  else if (String("reset") == termIn) {
    terminal.println("Resetting..."); 
    terminal.flush(); 
    lcd.clear(); 
    lcd.print("Resetting..."); 
    Watchdog.disable(); 
    int countdownMS = Watchdog.enable(500);
   }
  else {
    terminal.println("ERROR: Invalid Command"); 
    terminal.flush(); 
  }
  
}
BLYNK_WRITE(V2) {
  if (timerState == 1) {
    threshold = param.asInt();
    Blynk.virtualWrite(V2, threshold); 
    availableSlots = threshold - peopleIn; 
    Blynk.virtualWrite(V1, availableSlots);  
    tooMany();
    lcd.setCursor(8,0); 
    lcd.print(peopleIn);  
    lcd.print("/"); 
    lcd.print(threshold); 
    lcd.print("   ");  
  }
} 


void Sense() {
  //PIR code starts
  pirVal = digitalRead(pirPin); 
  if (pirVal == HIGH) {
    if (pirState == LOW) {
      Serial.println("Motion Detected");  
      pirState = HIGH;  
      Person = true;   
    }
  }
  else if (pirState == HIGH) {
    Serial.println("Motion Ended"); 
    pirState = LOW; 
    Person = false; 
  }

  //PIR code ends
  //Ultra1 code starts
  digitalWrite(rxPin, HIGH); 
  delayMicroseconds(40); 
  digitalWrite(rxPin, LOW); 
  //for(int i = 0; i<10; i++) {
    cmLeft = analogRead(1); 
  //}
  //cmLeft /=10; 
  Serial.println(cmLeft); 
  if (cmLeft < 200 and Person == true and dir == "null") {   
    dir = "In"; 
    tooMany();  
    Serial.println("IN!"); 
  }
  else if (cmLeft < 200 and Person == true and dir == "Out") {   
    if (peopleIn > 0) {
      dir = "null"; 
      peopleIn = peopleIn - 1; 
      tooMany();  
      lcd.setCursor(8,0); 
      lcd.print(peopleIn);  
      lcd.print("/"); 
      lcd.print(threshold); 
      lcd.print("   ");
      Blynk.virtualWrite(V0, peopleIn);
    }
  }

  //Ultra1 code ends
  //Ultra2 code starts
  digitalWrite(rxPin, HIGH); 
  delayMicroseconds(40); 
  digitalWrite(rxPin, LOW); 
  //for(int j = 0; j<10; j++) {
    cmRight = analogRead(2); 
  //}
 // cmRight /=10; 
  Serial.println(cmRight); 
  if (cmRight < 400 and Person == true and dir == "null") {   
    dir = "Out"; 
    tooMany();  
    Serial.println("OUT!"); 
  }
  else if (cmRight < 400 and Person == true and dir == "In") {  
    dir = "null";  
    peopleIn++;
    tooMany();  
    lcd.setCursor(8,0); 
    lcd.print(peopleIn);  
    lcd.print("/"); 
    lcd.print(threshold); 
    lcd.print("   ");
    Blynk.virtualWrite(V0, peopleIn);
    dir = "null";
  }
  }




void Battery() {
  if (digitalRead(batPin) == HIGH) {
    batState = HIGH; 
    Blynk.setProperty(V5, "color", BLYNK_GREEN); 
    digitalWrite(chargedLed, HIGH); 
    digitalWrite(lowLed, LOW); 
  }
  else {
    batState = LOW; 
    Blynk.setProperty(V5, "color", BLYNK_RED);
    digitalWrite(chargedLed, LOW); 
    digitalWrite(lowLed, HIGH);  
  }
    
  }
 
void tooMany() {
  if (timerState == 1) { 
    if (peopleIn > threshold) {
      if (tooManyState == false) {
        tone(5, 500); 
        Blynk.notify("{DEVICE_NAME} has reported as excess of person(s) entering the store") ;
        digitalWrite(redLed, HIGH); 
        digitalWrite(greenLed, LOW); 
        canGo = false;  
        lcd.setCursor(0,1); 
        lcd.print("PLEASE GO BACK!");
        lcd.print("    ");  
      }
      bool tooManyState = true; 
    }
    else if (peopleIn < threshold){
      noTone(5); 
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);  
      if (canGo == false) {
        canGo = true; 
        lcd.setCursor(0,1); 
        lcd.print("6 Feet Apart!"); 
        lcd.print("    "); 
      } 
    }
  
    else if (peopleIn == threshold) {
      noTone(5); 
      digitalWrite(redLed, HIGH); 
      digitalWrite(greenLed, LOW); 
      canGo = false; 
      lcd.setCursor(0,1); 
      lcd.print("               "); 
      lcd.setCursor(0,1); 
      lcd.print("FULL!"); 
      lcd.print("    "); 
    }
  }
}
