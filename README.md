# Rpi-and-Arduino-Car
Source code for controlling an Arduino via serial ports using a Raspberry Pi. Implemented on a small car

Instructions:

1.1 run ls /dev/tty* to list out existing serial devices connected to the Raspberry Pi\n
1.2 Connect arduino to Raspberry Pi via USB and run ls /dev/tty* again to find the serial port of the arduino\n
2. Upload code into arduino\n
3. Run python script on raspberry pi*\n


Note: if your arduino is not named /dev/ttyUSB0, edit the python script to reflect your arduino's serial port name.
