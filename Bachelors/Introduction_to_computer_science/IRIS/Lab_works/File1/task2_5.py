import serial as sr
import time
ser = sr.Serial('COM5', 9600)
while True:
  ser.write(b'1')
  time.sleep(1)

