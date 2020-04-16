const int pwmPin = 9;
const int dir1Pin = 12;
const int dir2Pin = 11;

void setup() {
pinMode (pwmPin, OUTPUT); 
pinMode (dir1Pin, OUTPUT);   
pinMode (dir2Pin, OUTPUT);   
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(dir1Pin, HIGH); 
     digitalWrite(dir2Pin, LOW); 
     analogWrite(pwmPin, 255); 
     delay(1000); 
}
