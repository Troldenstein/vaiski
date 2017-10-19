import RPi.GPIO as GPIO
import sys

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

if int(sys.argv[1]) < 2 or int(sys.argv[1]) > 20:
    print "Invalid argument, give gpio pin number from 3 to 20: ",str(sys.argv[1]) 
elif int(sys.argv[2]) < 0 or int(sys.argv[2]) > 1:
    print "Invalid second argument, give 1 or 0 to define the uotput state for pin: ",str(sys.argv[2])
else:
    print "You gave values: ",str(sys.argv[1]),str(sys.argv[2])
    gp1 = int(sys.argv[1])
    d1 = int(sys.argv[2])
    GPIO.setup(gp1,GPIO.OUT)
    GPIO.output(gp1,d1)
