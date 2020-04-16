 const int L1 = 22;
 const int L2 = 23;
 const int L3 = 24;

void setup() {
  // put your setup code here, to run once:

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);
  delay(500);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  delay(500);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  delay(500);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, HIGH);
  delay(500);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, HIGH);
  delay(500);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  delay(500);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);
  delay(500);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  delay(500ggvtfr);
  
}
