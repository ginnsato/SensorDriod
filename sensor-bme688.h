/**
 * @file sensor-bme688.h
 * 
 * @author Ginn Sato
 * 
 * @brief All functions requried for compatibilty with bno055 sensor
 * 
 * @date 2023-05-03
 * 
 */

//***********************************************************************************
// Include files
//***********************************************************************************

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

//***********************************************************************************
// Global Variables
//***********************************************************************************

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

/***********************************************************************************
// Function Definitions
//***********************************************************************************

/**
 * @brief Set the up bme688 sensor up 
 * 
 * @param bme Pointer to the bme688 object to set up
 */
void setup_bme688(Adafruit_BME680 *bme) {
    if (!bme->begin()) {
        Serial.println("Could not find a valid BME680 sensor, check wiring!");
        while (1);
    }
    // Set up oversampling and filter initialization
    bme->setTemperatureOversampling(BME680_OS_8X);
    bme->setHumidityOversampling(BME680_OS_2X);
    bme->setPressureOversampling(BME680_OS_4X);
    bme->setIIRFilterSize(BME680_FILTER_SIZE_3);
    //bme->setGasHeater(320, 150); // 320*C for 150 ms
}

/**
 * @brief Read from the bme688 sensor and print results
 * 
 * @param bme Pointer to the bme688 object to read the measurments
 */
void read_bme688(Adafruit_BME680 *bme) {
    if (!bme->performReading()) {
        Serial.println("Failed to perform reading :(");
        return;
    }
    Serial.print("Temperature = ");
    Serial.print(bme->temperature);
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bme->pressure / 100.0);
    Serial.println(" hPa");

    Serial.print("Humidity = ");
    Serial.print(bme->humidity);
    Serial.println(" %");

    Serial.print("Gas = ");
    Serial.print(bme->gas_resistance / 1000.0);
    Serial.println(" KOhms");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme->readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.println();

    //delay(2000);
}


/***************************************************************************
  This is a library for the BME680 gas, humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME680 Breakout
  ----> http://www.adafruit.com/products/3660

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/