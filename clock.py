import serial #REQUIRES "pip install pyserial"
import time

arduino = serial.Serial(port = 'COM4', timeout=0)

print(arduino.readline())

'''
for x in range(6):
    arduino.write(bytearray([1]))
    time.sleep(.5)
    print(arduino.readline())
    time.sleep(1)
    '''

def reportIn():
    arduino.write(bytearray([1]))
    lines = arduino.readline()
    print(lines)
    for i in range(len(lines)):
        if lines[i] == "0":
            return False
        if lines[i] == "1":
            return True

while True:
    delay = input()
    print(reportIn())