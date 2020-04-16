void setup() {
  pinMode(8, INPUT); 
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  if (digitalRead(8) == HIGH) {
    digitalWrite(LED_BUILTIN, LOW); 
  }
  else if (digitalRead(8) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH); 
  }


}
