import RPi.GPIO as GPIO
import time

buttonPin = 16
GPIO.setmode(GPIO.BOARD)

GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

while True:
    input_state = GPIO.input(buttonPin)
    if input_state == False:
        print("Button Pressed")
        time.sleep(0.3)
        
GPIO.cleanup();
        
