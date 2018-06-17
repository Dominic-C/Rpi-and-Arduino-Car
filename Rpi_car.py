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
        arduino.write('w')
    elif key_press.lower() == 'x':
        arduino.write('x')
    elif key_press.lower() == 'a':
        arduino.write('a')
    elif key_press.lower() == 'd':
        arduino.write('d')
    elif key_press.lower() == 's':
	arduino.write('s')
    elif key_press.lower() == 'i':
	arduino.write('i')
    elif key_press.lower() == 'j':
	arduino.write('j')
    elif key_press.lower() == 'l':
	arduino.write('l')
    elif key_press.lower() == 'k':
	arduino.write('k')
    elif key_press.lower() == ',':
	arduino.write(',')
    elif key_press.lower() == 'o':
	arduino.write('o')
    else:
	arduino.write('s')

    time.sleep(0.03)

command = tk.Tk()
command.bind('<KeyPress>', key_input)
command.mainloop()

