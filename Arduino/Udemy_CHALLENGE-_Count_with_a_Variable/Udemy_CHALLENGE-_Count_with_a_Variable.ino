
const int redPin = 10;
const int bluePin = 11;
const int greenPin = 9;
int red = 0;
int blue = 0;
int green = 0;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

 
void loop() {
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);

  red ++;
  blue ++;
  blue ++;
  green ++;
  green ++;
  green ++;
  delay(5);

  if(red > 255){
    red == 0;
}
  if (blue > 255){
    blue == 100;
  }
  if(green > 255){
    green == 50;
  }
  
  

    
  

}


 
  
