
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 2, 3, 4, 5);
const int speakerPin = 9; 
const int songPin = 8;
int song = 0;
int playPin = 11; 
int playState = LOW; 



void setup() {
  pinMode (speakerPin, OUTPUT);
  lcd.begin (16, 2);
  lcd.clear();
  lcd.print("Left:Change Song");
  lcd.setCursor(0, 1);
  lcd.print("Right:PLAY");

}

void loop() {

int songState = digitalRead(songPin);
int playState = digitalRead(playPin);

if (songState = HIGH){
  if (song == 1){
    song = 0; 
   if (song == 0){
    song = 1; 


if (playState == HIGH){
  if (song == 0){
    // Twinkle Twinkle Little Star
  tone(speakerPin, 293.665, 500); 
  delay(1000);  
   tone(speakerPin, 293.665, 500); 
  delay(1000);  
  tone(speakerPin, 440, 500); 
  delay(1000);
   tone(speakerPin, 440, 500); 
  delay(1000);
   tone(speakerPin, 493.883, 500); 
  delay(1000);
  tone(speakerPin, 493.883, 500); 
  delay(1000);
  tone(speakerPin, 440, 500); 
  delay(2000);
  tone(speakerPin, 391.995, 500); 
  delay(1000);
  tone(speakerPin, 391.995, 500); 
  delay(1000);
  tone(speakerPin, 369.994, 500); 
  delay(1000);
  tone(speakerPin, 369.994, 500); 
  delay(1000);
  tone(speakerPin, 329.628, 500); 
  delay(1000);
  tone(speakerPin, 329.628, 500); 
  delay(1000);
   tone(speakerPin, 293.665, 1000); 
  delay(5000);                    
  }                                                                 
  if (song == 1){ 
//G
tone(speakerPin, 195.998, 500);
delay(1000);
//C
tone(speakerPin, 261.626, 500);
delay(1000);
//D
tone(speakerPin, 293.665, 500);
delay(1000);
 


    

    
  }
}


 
   }
  }
}
 
  
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  

}  
  
