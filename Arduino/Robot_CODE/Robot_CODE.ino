// This is for the mini 3 layer 2wd robot. Have fun playing with it, me! LOL :) Below is a link for the wiring!
//https://www.udemy.com/arduino-programming-and-hardware-fundamentals-with-hackster/learn/v4/t/lecture/7440072?start=180
const int trigDelay = 25; 
const int pwmPin = 3;
const int pwm2Pin = 5;
const int dir1Pin = 12;
const int dir2Pin = 11;
const int dir3Pin = 9;
const int dir4Pin = 8; 
const int pwPin = 7;
const int speakerPin = 6;
const int trigPin = 4;
int i = 0; 
int a = 0; 
int reaction = 0; 
int c = 2; 


void setup() {
pinMode (pwmPin, OUTPUT); 
Serial.begin(9600); 
pinMode (dir1Pin, OUTPUT);   
pinMode (dir2Pin, OUTPUT);   
pinMode (pwm2Pin, OUTPUT); 
pinMode (dir3Pin, OUTPUT);   
pinMode (dir4Pin, OUTPUT);
}

void loop() {
  digitalWrite(dir1Pin, HIGH); 
  digitalWrite(dir2Pin, LOW); 
  analogWrite(pwmPin, 255);
  digitalWrite(dir3Pin, HIGH); 
  digitalWrite(dir4Pin, LOW); 
  analogWrite(pwm2Pin, 255);
  long duration;
  float cm;


 //Sensor Code
  pinMode (trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(trigDelay); 
  digitalWrite(trigPin, LOW);



  pinMode(pwPin, INPUT);
  duration = pulseIn(pwPin, HIGH); 


  cm = duration / 58.8;
  
  if ((cm < 17) and (cm > 1)) {
  Serial.print(cm);
  Serial.println(" cm---good");
  }
  
  if ((cm < 15) and (cm > 11) and(a == 0)){ 
    i = 1;
    cm = 0;  
    a = 1; 
    c = 1; 
    Serial.println("if statement cleared!"); 
  }
    if ((i > 0) and (8 > i ) and (reaction == 0)) {
     tone(speakerPin, 2000, 25 );
     delay(60); 
      Serial.println(i); 
     i++;
    }
    
    if(i == 8) {
    i++;
    }
    
   if ( i == 9) {
  digitalWrite(dir3Pin, LOW); 
  digitalWrite(dir4Pin, LOW); 
  analogWrite(pwm2Pin, 0);
     reaction = 1; 
     delay(1000);  
   }
            

  if ((cm == 0) and (reaction == 1)){
    reaction = 0; 
    a = 0; 
  }

    if (c != 1){
      Serial.println("If statement 1 failed"); 
}
  
     

  
  
}
    
