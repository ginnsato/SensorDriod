/**
 * @file calc.h
 *
 * @author
 *  Ginn Sato
 *
 * @date
 *  2023-05-01
 *
 * @brief
 *  Define the calculation functions
 *
 */


//***********************************************************************************
// Include files
//***********************************************************************************

#include <stdint.h>

//***********************************************************************************
// Function Definitions
//***********************************************************************************

/**
 * @brief Calculate the Root Mean Square (RMS) for an array of ints
 * 
 * @param data  Array of the data set values
 * @param size  Size of the data set
 * @return float 
 */
float calcRMS_int(uint32_t data[], int size){
    uint32_t sumOfSquares = 0;
    for(int i=0; i < size; i++){
        sumOfSquares += (data[i] * data[i]);
    }
    return sqrt(sumOfSquares/size);
}


/**
 * @brief Calculate the Root Mean Square Error (RMSE) for an array of ints
 * 
 * @param data  Array of the data set values
 * @param size  Size of the data set
 * @return float 
 */
float calcRMSE_int(uint32_t data[], int size){
    uint32_t average = 0, sumOfSquares = 0;

    // Calculate average of data
    for(int i=0; i < size; i++){
        average += data[i];
    }
    average = average / size;

    // Use average to normalize the data
    for(int i=0; i < size; i++){
        sumOfSquares += sq(data[i] - average);
    }
    return sqrt(sumOfSquares/size);
}



/**
 * @brief Calculate the Root Mean Square (RMS) for an array of floats
 * 
 * @param data  Array of the data set values
 * @param size  Size of the data set
 * @return float 
 */
float calcRMS_float(float data[], float size){
    float sumOfSquares = 0;
    for(int i=0; i < size; i++){
        sumOfSquares += (data[i] * data[i]);
    }
    return sqrt(sumOfSquares/size);
}


/**
 * @brief Calculate the Root Mean Square Error (RMSE) for an array of floats
 * 
 * @param data  Array of the data set values
 * @param size  Size of the data set
 * @return float 
 */
float calcRMSE_float(float data[], float size){
    float average = 0, sumOfSquares = 0;

    // Calculate average of data
    for(int i=0; i < size; i++){
        average += data[i];
    }
    average = average / size;

    // Use average to normalize the data
    for(int i=0; i < size; i++){
        sumOfSquares += sq(data[i] - average);
    }
    return sqrt(sumOfSquares/size);
}
