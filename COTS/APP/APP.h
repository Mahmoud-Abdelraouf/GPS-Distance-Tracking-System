/***********************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_3      *************/
/********** Date    : 25/04/2023               *************/
/********** SWC     : HAL_GPS                  *************/
/********** Version : 1.0                      *************/
/***********************************************************/
#ifndef APP_APP_H__
#define APP_APP_H__

#define M_PI            3.1415926
#define Earth_Radius    6371000

/**
 * @brief Calculates the distance between two geographical points using the Haversine formula.
 *
 * This function calculates the distance between two geographical points specified by their latitude 
 * and longitude coordinates using the Haversine formula. The distance is stored in the provided 
 * pointer variable.
 *
 * @param StartLatitude The latitude of the starting point in degrees.
 * @param StartLongitude The longitude of the starting point in degrees.
 * @param EndLatitude The latitude of the ending point in degrees.
 * @param EndLongitude The longitude of the ending point in degrees.
 * @param Distance Pointer to store the calculated distance between the two points.
 *
 * @note All coordinates should be provided in degrees.
 * @note The Earth's radius is assumed to be defined elsewhere as 'Earth_Radius'.
 */
void APP_GetDistance(f32 StartLatitude, f32 StartLongitude, f32 EndLatitude, f32 EndLongitude, f32 *Distance);

/**
 * @brief Controls LED indication based on the distance between two geographical points.
 *
 * This function initializes the LED and calculates the distance between the starting and ending points.
 * Based on the calculated distance, it controls the LED indication:
 * - If the distance to the endpoint is greater than 5 units, the red LED is turned on.
 * - If the distance is between 2 and 5 units, both the red and green LEDs are turned on.
 * - If the distance is less than 2 units, only the green LED is turned on, and an "Arrived!" message 
 *   is displayed on an LCD.
 *
 * @param StartLatitude The latitude of the starting point in degrees.
 * @param StartLongitude The longitude of the starting point in degrees.
 * @param EndLatitude The latitude of the ending point in degrees.
 * @param EndLongitude The longitude of the ending point in degrees.
 * @return 0 if the LED indication is not related to arrival, 1 if "Arrived!" message is displayed.
 *
 * @note All coordinates should be provided in degrees.
 */
u8 APP_LightLED(f32 StartLatitude, f32 StartLongitude, f32 EndLatitude, f32 EndLongitude);

/**
 * @brief Truncates a floating-point number to four decimal places.
 *
 * This function truncates the given floating-point number to four decimal places.
 * It multiplies the number by 10,000, floors the result, and then divides it by 10,000.
 * The truncated value is stored back in the input variable.
 *
 * @param FloatValue Pointer to the floating-point number to be truncated.
 * @return The truncated floating-point value.
 */
f32 truncate(f32 *FloatValue);

 #endif /* APP_APP_H__ */
