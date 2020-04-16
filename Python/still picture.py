from picamera import PiCamera
from time import sleep

camera = PiCamera()
imagenum = 0

camera.start_preview()
sleep(5)
camera.capture('/home/pi/Downloads/Photos/image.jpg')
camera.stop_preview()
