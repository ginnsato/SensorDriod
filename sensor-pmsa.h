/**
 * @file sensor-pmsa.h
 * 
 * @author Ginn Sato and 
 * 
 * @brief All functions requried for compatibilty with bno055 sensor
 * 
 * @date 2023-05-03
 * 
 */

//***********************************************************************************
// Include files
//***********************************************************************************

#include "Adafruit_PM25AQI.h"

/***********************************************************************************
// Function Definitions
//***********************************************************************************

/**
 * @brief Set the up pmsa sensor up 
 * 
 * @param aqi Pointer to the pmsa object to set up
 */

void setup_pmsa(Adafruit_PM25AQI *aqi) {

  // Wait one second for sensor to boot up!
  delay(1000);

  // If using serial, initialize it and set baudrate before starting!
  // Uncomment one of the following
  //Serial1.begin(9600);
  //pmSerial.begin(9600);

  // There are 3 options for connectivity!
  if (!aqi->begin_I2C(&Wire)) {      // connect to the sensor over I2C
  //if (! aqi.begin_UART(&Serial1)) { // connect to the sensor over hardware serial
  //if (! aqi.begin_UART(&pmSerial)) { // connect to the sensor over software serial 
    Serial.println("Could not find PM 2.5 sensor!");
    while (1) delay(10);
  }
  Serial.println("PM25 found!");
}

/***********************************************************************************
// Function Definitions
//***********************************************************************************

/**
 * @brief Set the up pmsa sensor up 
 * 
 * @param aqi Pointer to the pmsa object to set up
 */
void read_pmsa(Adafruit_PM25AQI *aqi){
    PM25_AQI_Data data;
  
  if (!aqi->read(&data)) {
    Serial.println("Could not read from AQI");
    delay(500);  // try again in a bit!
    return;
  }
  Serial.println(F("---------------------------------------"));
  Serial.println(F("Concentration Units (standard)"));
  Serial.println(F("---------------------------------------"));
  Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_standard);
  Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_standard);
  Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_standard);
  Serial.println(F("Concentration Units (environmental)"));
  Serial.println(F("---------------------------------------"));
  Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_env);
  Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_env);
  Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_env);
  Serial.println(F("---------------------------------------"));
  Serial.print(F("Particles > 0.3um / 0.1L air:")); Serial.println(data.particles_03um);
  Serial.print(F("Particles > 0.5um / 0.1L air:")); Serial.println(data.particles_05um);
  Serial.print(F("Particles > 1.0um / 0.1L air:")); Serial.println(data.particles_10um);
  Serial.println();
  /*
  Serial.print(F("Particles > 2.5um / 0.1L air:")); Serial.println(data.particles_25um);
  Serial.print(F("Particles > 5.0um / 0.1L air:")); Serial.println(data.particles_50um);
  Serial.print(F("Particles > 10 um / 0.1L air:")); Serial.println(data.particles_100um);
  Serial.println(F("---------------------------------------"));
  */
  //delay(5000);
  
}

