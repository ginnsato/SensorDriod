/**
 * @file MultiSensor.ino
 * 
 * @author Ginn Sato
 * 
 * @brief Arduino code for running multiple sensors on the same i2c bus
 * 
 * @date 2023-05-01
 * 
 */

//***********************************************************************************
// Include files
//***********************************************************************************
#include <Arduino.h>
#include <Wire.h>
#include <stdint.h>

#include "sensor-scd41.h"
#include "sensor-veml7700.h"
#include "sensor-bno055.h"
#include "sensor-bme688.h"
#include "sensor-pmsa.h"
#include "calc.h"

//***********************************************************************************
// Global variables
//***********************************************************************************
#define SAMPLE_SIZE 50

SensirionI2CScd4x scd4x;                         // i2c address: 0x62
Adafruit_VEML7700 veml = Adafruit_VEML7700();    // i2c address: 0x10
Adafruit_BNO055 bno = Adafruit_BNO055(55);       // i2c address: 0x28
Adafruit_BME680 bme;                             // i2c address: 0x77
Adafruit_PM25AQI aqi = Adafruit_PM25AQI();       // i2c address: 0x12


void setup() {
    // Begin connection with serial 
    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }
    // Setup sensors
    Wire.begin();
    setup_veml(&veml);
    setup_scd41(&scd4x);
    setup_bno055(&bno);
    setup_bme688(&bme);
    setup_pmsa(&aqi);
}

void loop() {
    // Read from sensors and print output
    read_scd41(&scd4x);         // delay of 5000 in this func
    read_veml(&veml);
    read_bno055(&bno);
    read_bme688(&bme);
    read_pmsa(&aqi);
}