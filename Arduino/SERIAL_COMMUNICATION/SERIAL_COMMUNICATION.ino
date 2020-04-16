
void setup() {
  Serial.begin(9600);
  

}

void loop() {
  Serial.write(analogRead(A0)/4);
  delay(1);

}



// WARNING! DO  NOT DELETE THIS SKETCH. IT IS VERY IMPORTANT. IT IS USED FOR SERIAL COMMUNICATION WITH PROCESSING 3. DO NOT DELETE OR MODIFY.
