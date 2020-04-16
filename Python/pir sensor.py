import RPi.GPIO as GPIO
import time

pirPin = 7
GPIO.setmode(GPIO.BOARD)
GPIO.setup(pirPin, GPIO.IN)
count = 0;

while True:
    input_state = GPIO.input(pirPin)
    if input_state == True:
        print("Motion Detected --" + str(count))
        count+=1
        time.sleep(0.3)
        
GPIO.cleanup();