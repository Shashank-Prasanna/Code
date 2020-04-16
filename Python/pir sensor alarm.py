import RPi.GPIO as GPIO
import time

GPIO.setwarnings (False)

pirPin = 7
buzzerPin = 11
GPIO.setmode(GPIO.BOARD)

GPIO.setup(pirPin, GPIO.IN);
GPIO.setup(buzzerPin, GPIO.OUT);
GPIO.output(buzzerPin, GPIO.LOW)


def soundAlarm(pirPin):
    
    print("Sound Alarm!")
    GPIO.output(buzzerPin, GPIO.HIGH)
    time.sleep(11)
    turnOffAlarm(pirPin)
    
def turnOffAlarm(pirPin):
    
    GPIO.output(buzzerPin, GPIO.LOW)
    
GPIO.add_event_detect(pirPin, GPIO.RISING,  callback=soundAlarm);
    