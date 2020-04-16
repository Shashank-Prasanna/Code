import RPi.GPIO as GPIO
from gpiozero import Robot
from signal import pause
from subprocess import call
from bluedot import MockBlueDot

GPIO.setmode(GPIO.BCM)
bd = MockBlueDot()
robot = Robot(right=(13,19),left=(16,20))
#En1 = 26
#En2 = 21
count = 0
GPIO.setup(21, GPIO.OUT)
GPIO.setup(26, GPIO.OUT)

bd.launch_mock_app()
def shutdown():
    global count
    count += rotation.value
    if count == 5:
        call("sudo reboot -h now", shell=True)
def reset():
    GPIO.output(26, GPIO.LOW)
    GPIO.output(21, GPIO.LOW)
def En1():
    GPIO.output(26, GPIO.HIGH)
def En2():
    GPIO.output(21, GPIO.HIGH)
    
def move(pos):
    if pos.top:
        reset()
        En1()
        En2()
        robot.forward(pos.distance)
    elif pos.bottom:
        reset()
        En1()
        En2()
        robot.backward(pos.distance)
    elif pos.left:
        reset()
        En1()
        robot.left(pos.distance)
    elif pos.right:
        reset()
        En2()
        robot.right(pos.distance)
def stop():
    robot.stop()
    
bd.when_pressed = move
bd.when_moved = move
bd.when_released = stop
bd.when_rotated = shutdown

pause()
        