import serial
import time
import sys
import Tkinter as tk

arduino = serial.Serial("/dev/ttyUSB0", 9600) # connecting to arduino with baud rate 9600
time.sleep(1)

print "Initialze complete.. \n"

def key_input(event):
    print 'key:', event.char # printing key input just to check if keystroke is registered
    key_press = event.char

    # using keypress events to trigger the arduino's functions
    # each letter sent to the arduino corresponds to either movement of the motors or movement of the servos
    if key_press.lower() == 'w':
        arduino.write('w')
    elif key_press.lower() == 's':
        arduino.write('x')
    elif key_press.lower() == 'a':
        arduino.write('a')
    elif key_press.lower() == 'd':
        arduino.write('d')
    elif key_press.lower() == 'x':
	arduino.write('s')
    elif key_press.lower() == 'i':
	arduino.write('i')
    elif key_press.lower() == 'j':
	arduino.write('j')
    elif key_press.lower() == 'l':
	arduino.write('l')
    elif key_press.lower() == ',':
	arduino.write('k')
    elif key_press.lower() == 'k':
	arduino.write(',')
    elif key_press.lower() == 'o':
	arduino.write('o')
    else:
	arduino.write('s')

    time.sleep(0.03)

def brake(event): # making a brake function to stop movement upon key release
    # so that car stops when we stop pressing w, a, s, d 
    arduino.write('s')
    # so that servo stops when we release the keys
    arduino.write('k')

command = tk.Tk()
command.bind('<KeyPress>', key_input)
command.bind('<KeyRelease>', brake) # Key release triggers the brake function
command.mainloop()

