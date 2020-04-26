
#include <SPI.h>
#include <BraccioRobot.h>
#include <Servo.h>


const int trigPin = 4; 
const int pwPin = 7; 
const int trigDelay = 25; 
int M1;
int M2;
int M3;
int M4;
int M5; 
int M6;
int Speed = 1;
int state = 0; 
int distance;  
int Rep = 0;  
float cm;   
Position myInitialPosition; 
void Sense() {
  long duration; 
  pinMode(trigPin, OUTPUT); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(trigDelay); 
  digitalWrite(trigPin, LOW); 

  pinMode(pwPin, INPUT); 
  duration = pulseIn(pwPin, HIGH); 

  cm = duration/58.8;
  Serial.print(cm); 
  Serial.println(" cm"); 
  delay(100);
  return(cm); 
}

void setup() {
  Serial.begin(9600); 
  BraccioRobot.powerOn(); 
  myInitialPosition.set(120, 130, 160, 80, 45, 73);
  BraccioRobot.init(myInitialPosition);

}

void loop() {
    Sense(); 
   if (cm < 200 and Rep == 0) {
    Position posit(100,70, 165,30 , 135, 20); 
    BraccioRobot.moveToPosition(posit.setGripper(20), 30); 
    BraccioRobot.moveToPosition(posit.setGripper(64), 30);
    posit.set(150, 95, 165, 30, 135, 73);
    BraccioRobot.moveToPosition(posit.setGripper(40), 30);
    BraccioRobot.moveToPosition(posit.setGripper(10), 30);
    BraccioRobot.moveToPosition(myInitialPosition, 30);  
    BraccioRobot.powerOff();   
    Rep = 1; 
   }
}
