from picamera import PiCamera
from time import sleep

camera = PiCamera()

camera.start_preview()
for i in range(5):
    sleep(0.1)
    camera.capture('/home/pi/Downloads/Photos/image%s.jpg' % i)
camera.stop_preview()