const int tempPin = A0;
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage;
  float tempC;


  voltage = analogRead(tempPin) * 5.0 / 1023;
  tempC = 100.0 * voltage - 50;   

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" deg C: ");
  Serial.println(tempC); 
  delay(500); 

} 
