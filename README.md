# SensorDroid
This repo contains starting Code for the first iterations of the Sensor Droid Project. Through the use of sensor specific Arduino libraries, the code reads data from multiple sensors and outputs the corresponding measurments using the serial monitor. There is one main Arduino .ino file that calls various functions defined in the sensor specific header files. Each sensor's .h file has a setup and read function that takes in the address of the corresponding sensor object. This repo also contains a calc.h file with useful functions for performing RMS and RMSE calculations on different typed data sets. 

IMPROTANT: The I2C bus from the QT-PY pins corresponds to the object "Wire" whereas the I2C bus from the Stemma Qwiic Connect corresponds to "Wire1". The code above is implemented for the I2C bus from the pin outs (Wire). To change this, you have to manually go into each sensor file and change all references of Wire to Wire1.

Feel free to copy and modify this code however you'd like!
