/**
 * @file sensor-veml7700.h
 * 
 * @author Ginn Sato
 * 
 * @brief All functions requried for compatibilty with veml7700 sensor
 * 
 * @date 2023-05-03
 * 
 */

//***********************************************************************************
// Include files
//***********************************************************************************

#include "Adafruit_VEML7700.h"

//***********************************************************************************
// Function Definitions
//***********************************************************************************

/**
 * @brief Set the up veml7700 sensor up 
 * 
 * @param veml Pointer to the veml7700 object to set up
 */
void setup_veml(Adafruit_VEML7700 *veml){

    if (!veml->begin()) {
        Serial.println("veml not found");
        while (1);
    }
    Serial.println("Sensor found");

    veml->setGain(VEML7700_GAIN_2);
    veml->setIntegrationTime(VEML7700_IT_800MS);

    Serial.print(F("Gain: "));
    switch (veml->getGain()) {
    case VEML7700_GAIN_1: Serial.println("1"); break;
    case VEML7700_GAIN_2: Serial.println("2"); break;
    case VEML7700_GAIN_1_4: Serial.println("1/4"); break;
    case VEML7700_GAIN_1_8: Serial.println("1/8"); break;
    }

    Serial.print(F("Integration Time (ms): "));
    switch (veml->getIntegrationTime()) {
    case VEML7700_IT_25MS: Serial.println("25"); break;
    case VEML7700_IT_50MS: Serial.println("50"); break;
    case VEML7700_IT_100MS: Serial.println("100"); break;
    case VEML7700_IT_200MS: Serial.println("200"); break;
    case VEML7700_IT_400MS: Serial.println("400"); break;
    case VEML7700_IT_800MS: Serial.println("800"); break;
    }

    veml->setLowThreshold(10000);
    veml->setHighThreshold(20000);
    veml->interruptEnable(true);
}

/**
 * @brief Read from the veml7700 sensor and print results
 * 
 * @param veml Pointer to the veml7700 object to read the measurments
 */
void read_veml(Adafruit_VEML7700 *veml){
    float ALS, White, Lux;

    ALS = veml->readALS();
    White = veml->readWhite();
    Lux = veml->readLux();

    Serial.print("ALS:");
    Serial.print(ALS);
    Serial.print("\t");
    Serial.print("White:");
    Serial.print(White);
    Serial.print("\t");
    Serial.print("Lux:");
    Serial.println(Lux);

    Serial.println();

    //delay(200);
}

