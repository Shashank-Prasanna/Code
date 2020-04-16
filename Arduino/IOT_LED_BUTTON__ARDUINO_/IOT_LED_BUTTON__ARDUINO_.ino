
int onOff = 0; 
const int pin = A0; 
const int onOffPin = 5;
int converter;  
void setup() {
Serial.begin (9600);
pinMode (pin, INPUT);
pinMode (onOffPin, OUTPUT); 


}

void loop() {

  converter = digitalRead (pin);
  if (converter > 100) {
    onOff = 1; 
  if(converter < 100); 
    onOff = 0; 
    
  }

 if (onOff == 1) {
  digitalWrite(onOffPin, HIGH);
  Serial.println("On!"); 

 if (onOff == 0) {
  digitalWrite(onOffPin, LOW);
  Serial.println("Off"); 
   
 }
  
 }

}
