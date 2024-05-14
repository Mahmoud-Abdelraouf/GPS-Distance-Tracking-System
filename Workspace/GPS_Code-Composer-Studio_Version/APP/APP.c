/*
 * APP.c
 *
 *  Created on: May 13, 2023
 *      Author: karim
 */
/******************************< SYSTEM ***************************/
#include <math.h>
/******************************< LIB ******************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/******************************< HAL ******************************/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"
/******************************< APP ******************************/
#include "../APP/APP.h"

void APP_voidGetDistance(f32 copy_f32startLatitude, f32 copy_f32startLongitude,f32 copy_f32endLatitude, f32 copy_f32endLongitude, f32 *copy_pf32distance)
{
    // convert all coordinates from Degrees into Radians
    f32 Local_f32startLat = truncate(&copy_f32startLatitude)* M_PI/180;
    f32 Local_f32startLong = truncate(&copy_f32startLongitude)* M_PI/180;
    f32 Local_f32endLat = truncate(&copy_f32endLatitude)* M_PI/180;
    f32 Local_f32endLong = truncate(&copy_f32endLongitude)* M_PI/180;

    // calculate latitude difference and longitude difference
    f32 Local_f32latDifference = Local_f32endLat - Local_f32startLat;
    f32 Local_f32longDifference = Local_f32endLong - Local_f32startLong;

    //use Haversine formula
    f32 Local_f32a = sin(Local_f32latDifference / 2) * sin(Local_f32latDifference / 2) + cos(Local_f32startLat) * cos(Local_f32endLat)
    * sin(Local_f32longDifference / 2) * sin(Local_f32longDifference / 2);
    f32 Local_f32c = 2 * atan2(sqrt(Local_f32a), sqrt(1 - Local_f32a));

    //Multipy by Earth's Radius to get the distance
    *copy_pf32distance = Local_f32c * Earth_Radius;
}

u8 APP_u8LightLED(f32 copy_f32startLatitude, f32 copy_f32startLongitude, f32 copy_f32endLatitude, f32 copy_f32endLongitude)
{
    LED_voidLedInit();
    //calc distance to endpoint
    f32 Local_f32distanceToEndPoint = 0;
    // function to get distance has been moved so we need to update this
    APP_voidGetDistance(copy_f32startLatitude, copy_f32startLongitude, copy_f32endLatitude, copy_f32endLongitude, &Local_f32distanceToEndPoint);

    if (Local_f32distanceToEndPoint > 5){//red
        //assuming this call is needed
        LED_voidLedOn(LED_RED);
        return 0;
    } else if (Local_f32distanceToEndPoint < 5 && Local_f32distanceToEndPoint > 2){//yellow
        //assuming this call is needed
        LED_voidLedOn(LED_RED);
        LED_voidLedOn(LED_GREEN);
        return 0;
    } else if (Local_f32distanceToEndPoint < 2){//green
        //assuming this call is needed
        LED_voidLedOn(LED_GREEN);
        LCD_voidGoToXYPos(1, 8);
        LCD_voidSendString("Arrived!");
        return 1;
    }
    return 0;
}

f32 truncate(f32 *copy_f32FloatValue)
{
    *copy_f32FloatValue = floor(*copy_f32FloatValue * 10000) / (f64)10000.0;
    return *copy_f32FloatValue;
}
