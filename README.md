# RaspberryPi controlled Arduino car

## Requirements
* pyserial
* arduino IDE

## Instructions
1. Wire up the arduino to the motor as indicated in the code. Do note that you have to connect the motors through a motor driver. In my case, i used a TB6612FNG motor driver.
2. upload code and run `python Rpi_car.py`.
3. After initialization, click on the square box created by tkinter.
4. Move around with w, a, s, d
5. additionally, you could mount servos and a camera and control it in 2 axis with i, j, k, l. re-center the camera with o

## Other resources
if you would like to attach an Rpi camera and stream over wifi, heres a link you can check out: http://picamera.readthedocs.io/en/latest/recipes2.html#web-streaming