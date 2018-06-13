import serial
import time
import sys
import Tkinter as tk

arduino = serial.Serial("/dev/ttyUSB0", 9600)
time.sleep(1)

print "Initialze complete.. \n"

def key_input(event):
    print 'key:', event.char
    key_press = event.char

    if key_press.lower() == 'w':
        arduino.write('f')
    elif key_press.lower() == 's':
        arduino.write('v')
    elif key_press.lower() == 'a':
        arduino.write('l')
    elif key_press.lower() == 'd':
        arduino.write('r')
    else:
        arduino.write('b')

    time.sleep(0.03)

command = tk.Tk()
command.bind('<KeyPress>', key_input)
command.mainloop()

