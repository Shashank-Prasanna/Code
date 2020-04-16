// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
int a = 200; 
int b = 100;
int c = 0;
int a1 = 0;
int b1 = 0;
int c1 = 0; 
  // For a se
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            12

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100 ; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
Serial.begin(9600);
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  if(1 == 1){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(0, pixels.Color(a,b,c)); 
  pixels.setPixelColor(1, pixels.Color(c,b,a));                          
  pixels.setPixelColor(2, pixels.Color(c,a,b)); 
  pixels.setPixelColor(3, pixels.Color(b,a,c)); 
    pixels.show(); // This sends the updated pixel color to the hardware.
   
    delay(delayval); // Delay for a period of time (in milliseconds).
    
    if (a1 == 0){
     a = a - 10; 
    }
    
       if (a1 == 1) {
        a = a + 10; 
       }
      
        
        if ((1 > a) and (a1 == 0)){
          a1 = 1;
          a = a + 1; 
        }
         if (( 255 < a) and (a1 = 1)){
          a = a - 1;
          a1 = 0;
         }


         
    if (b1 == 0){
     b = b - 10; 
    }
    
       if (b1 == 1) {
        b = b + 10; 
       }
      
        
        if ((1 > b) and (b1 == 0)){
          b1 = 1;
         b = b + 1; 
        }
         if (( 255 < a) and (a1 = 1)){
          b = b - 1;
          b1 = 0;
         }



         
    if (c1 == 0){
     c = c - 10; 
    }
    
       if (c1 == 1) {
        c = c + 10; 
       }
      
        
        if ((1 > c) and (c1 == 0)){
          c1 = 1;
          c= c + 1; 
        }
         if (( 255 < c) and (c1 = 1)){
          c = c - 1;
          c1 = 0;
         }
        
      
    
  }
                
      
      
       
       
      Serial.println("a = "); 
      Serial.print(a);
       Serial.println("b = "); 
      Serial.print(b);
       Serial.println("c = "); 
      Serial.print(c);
     
  
     
    }
      
    
           
    

  
