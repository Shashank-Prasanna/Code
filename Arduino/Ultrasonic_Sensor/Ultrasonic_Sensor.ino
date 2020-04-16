
const int trigPin = 4;
const int pwPin = 7;
const int piezoPin = 8; 
const int trigDelay = 25; 

void setup() {
  Serial.begin(9600);    

}

void loop() { 
  // Sensor code
long duration;
float cm;



  pinMode (trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(trigDelay); 
  digitalWrite(trigPin, LOW);



  pinMode(pwPin, INPUT);
  duration = pulseIn(pwPin, HIGH); 


  cm = duration / 58.8;
  Serial.print(cm);
  Serial.println(" cm");

  delay(100); 

  }
  // End of Sensor code
  
  }
}
