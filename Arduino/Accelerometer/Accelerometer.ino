
const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

const float sensitivity = 0.206;

void setup() {
  // put your setup code here, to run once:
  analogReference(EXTERNAL);
  Serial.begin(9600);

  

}

void loop() {
  // put your main code here, to run repeatedly:

  float x;
  float y;
  float z;


  x = (analogRead(xPin) - 512) * 3.3 / (sensitivity * 1023);
  y = (analogRead(yPin) - 512) *3.3 / (sensitivity * 1023);
  z = (analogRead(zPin) - 512) *3.3 / (sensitivity * 1023);



  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" Y: "); 
  Serial.print(y);
  Serial.print(" Z: ");
  Serial.println(z);


  delay(1000);


}
