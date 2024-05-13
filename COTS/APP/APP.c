/***********************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_3      *************/
/********** Date    : 25/04/2023               *************/
/********** SWC     : HAL_GPS                  *************/
/********** Version : 1.0                      *************/
/***********************************************************/

/******************************< SYSTEM ***************************/
#include <math.h>
/******************************< LIB ******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/******************************< HAL ******************************/
#include "LED_interface.h"
#include "CLCD_interface.h"
/******************************< APP ******************************/
#include "APP.h"

void APP_GetDistance(f32 StartLatitude, f32 StartLongitude,f32 EndLatitude, f32 EndLongitude, f32 *Distance)
{
    // convert all coordinates from Degrees into Radians
    f32 Local_startLat = truncate(&StartLatitude) * M_PI/180;
    f32 Local_startLong = truncate(&StartLongitude) * M_PI/180;
    f32 Local_endLat = truncate(&EndLatitude) * M_PI/180;
    f32 Local_endLong = truncate(&EndLongitude) * M_PI/180;

    // calculate latitude difference and longitude difference
    f32 Local_f32latDifference = Local_endLat - Local_startLat;
    f32 Local_f32longDifference = Local_endLong - Local_startLong;

    //use Haversine formula
    f32 Local_f32a = sin(Local_f32latDifference / 2) * sin(Local_f32latDifference / 2) + cos(Local_startLat) * cos(Local_endLat)
    * sin(Local_f32longDifference / 2) * sin(Local_f32longDifference / 2);
    f32 Local_f32c = 2 * atan2(sqrt(Local_f32a), sqrt(1 - Local_f32a));

    //Multipy by Earth's Radius to get the distance
    *Distance = Local_f32c * Earth_Radius;
}

u8 APP_LightLED(LCD_Config_t *LCD, f32 StartLatitude, f32 StartLongitude, f32 EndLatitude, f32 EndLongitude)
{
    LED_LedInit();
    //calc distance to endpoint
    f32 Local_f32distanceToEndPoint = 0;
    // function to get distance has been moved so we need to update this
    APP_GetDistance(StartLatitude, StartLongitude, EndLatitude, EndLongitude, &Local_f32distanceToEndPoint);

    if (Local_f32distanceToEndPoint > 5){
        //assuming this call is needed
        LED_LedOn(LED_RED);
        return 0;
    } else if (Local_f32distanceToEndPoint < 5 && Local_f32distanceToEndPoint > 2){//yellow
        //assuming this call is needed
        LED_LedOn(LED_RED);
        LED_LedOn(LED_GREEN);
        return 0;
    } else if (Local_f32distanceToEndPoint < 2){//green
        //assuming this call is needed
        LED_LedOn(LED_GREEN);
        CLCD_GoToXYPos(LCD, 1, 8);
        CLCD_SendString(LCD, "Arrived!");
        return 1;
    }
    return 0;
}

f32 truncate(f32 *FloatValue)
{
    *FloatValue = floor(*FloatValue * 10000) / (f64)10000.0;
    return *FloatValue;
}
