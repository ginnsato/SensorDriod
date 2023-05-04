/**
 * @file sensor-bno055.h
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

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/***********************************************************************************
// Function Definitions
//***********************************************************************************

/**
 * @brief Set the up bno055 sensor up 
 * 
 * @param bno Pointer to the bno055 object to set up
 */
void setup_bno055(Adafruit_BNO055 *bno){
  if(!bno->begin())      
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno->setExtCrystalUse(true);
}

/**
 * @brief Read from the bno055 sensor and print results
 * 
 * @param bno Pointer to the bno055 object to read the measurments
 */
void read_bno055(Adafruit_BNO055 *bno){
  sensors_event_t event; 
  bno->getEvent(&event);
  
  /* Display the floating point data */
  Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println();

  Serial.println();
  
  //delay(100);

}
