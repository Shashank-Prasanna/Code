const int photoPin = 0; 
int lightLevel; 
int baseLevel;

void setup() {
  // put your setup code here, to run once:
  delay(5000); 
  Serial.begin(9600); 
  baseLevel = analogRead(photoPin); 
  pinMode(13, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  lightLevel = analogRead(photoPin); 
  Serial.println(lightLevel); 
  if (baseLevel - 10 >= lightLevel) {
    Serial.println("Sphero detected! Initiate P2"); 
    Serial.end(); 
    digitalWrite(13, HIGH); 
    delay(5000); 
    digitalWrite(13, LOW); 
    
  }
}
