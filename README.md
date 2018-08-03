# RaspberryPi controlled Arduino car

## Requirements
* pyserial
* arduino IDE

## Instructions
* Wire up and arduino to a motor driver, with pins as stated in `Arduino_car.ino`. Make sure to ground everything properly. Then upload the code to your arduino.
    * In my case, I used a TB6612FNG. A guide for wiring up this particular driver can be found [here](https://learn.sparkfun.com/tutorials/tb6612fng-hookup-guide)
* Copy `Rpi_car.py` to your raspberrypi, then run `python Rpi_car.py` in your command prompt.
* After initialization, a pop up box should appear. It's a window created by tkinter. Click on it.
* Now, you can move around with w, a, s, d. Additionally, you could mount servos and a camera and control it in 2 axis with i, j, k, l. re-center the camera with o

## Other resources
If you would like to attach an Rpi camera and stream over wifi, [heres](http://picamera.readthedocs.io/en/latest/recipes2.html#web-streaming) a link you can check out.