//*********************
//**** Name    : ASU_EMBEDDED_TEAM_3      *****
//**** Date    : 25/04/2023               *****
//**** SWC     : HAL_GPS                  *****
//**** Version : 1.0                      *****
//*********************
#include <math.h>
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */


/**< HAL */
#include "GPS_private.h"
#include "GPS_config.h"
#include "GPS_interface.h"
#include "UART_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

extern f32 latitude,longitude;

/** update them depending on your starting point */
const f32 startLatitude = 30.0461235;
const f32 startlongitude = 31.0461235;


/**
 * Description :
 * Receive a complete NMEA sentence from GPS module
 * $GNRMC,204520.00,A,5109.0262239,N,11401.8407338,W,0.004,102.3,130522,0.0,E,D*3B
 */


GPS_ERROR_State_t GPS_voidReceiveSentence(void){

    u8 j  = 0;
    u8 GPS_Sentence[100];
    char GPS_check[] = "$GNRMC,";
    GPS_ERROR_State_t functionErrorState= CheckA_OK;
    u8 check0;
    UART_voidReceiveByte(UART5,&check0);

        if (check0 == GPS_check[0]){
            u8 check1;
            UART_voidReceiveByte(UART5,&check1);
        if (check1 == GPS_check[1]){
            u8 check2;
            UART_voidReceiveByte(UART5,&check2);
        if (check2 == GPS_check[2]){
            u8 check3;
            UART_voidReceiveByte(UART5,&check3);
        if (check3 == GPS_check[3]){
            u8 check4;
            UART_voidReceiveByte(UART5,&check4);
        if (check4 == GPS_check[4]){
            u8 check5;
            UART_voidReceiveByte(UART5,&check5);
        if (check5 == GPS_check[5]){
            u8 check6;
            UART_voidReceiveByte(UART5,&check6);
        if (check6 == GPS_check[6]){
            u8 reading;
            UART_voidReceiveByte(UART5,&reading);
        while(reading != '*'){
           GPS_Sentence[j] = reading;
           UART_voidReceiveByte(UART5,&reading);
            j++;
        }
        GPS_voidExtractCoordinates(GPS_Sentence);
        }
        }
        }
        }
        }
        }
        }
        return functionErrorState = Done;


}

/*
 * Description :
 * return the coordinates of your current location using gps module
 */

GPS_ERROR_State_t GPS_voidExtractCoordinates(u8* sentence)
        {
             f32 deg,min,sec;
             GPS_ERROR_State_t functionErrorState = CheckA_OK;
             u8 commaCount = 0;
             u8 j = 0;
             u8 k = 0;
             u8 charACheck = 'A';
             u8 longARR[15] = {0};
             u8 altitudeARR[15] = {0};
             u8 i = 0;
             while(commaCount<5){
             if (sentence[i] == ','){
             commaCount++;
             i++;
             }

              if(commaCount == 1){
                       if (sentence[i]!=charACheck){
                       return functionErrorState = CheckA_NOK;
                       }
              }

              if(commaCount == 2){
                  altitudeARR[j++]=sentence[i];
              }

              if(commaCount == 4){
                  longARR[k++]=sentence[i];
              }

              i++;
             }

             latitude = atof(altitudeARR);
             deg = latitude/100;
             min = latitude - (f32)(deg*100);
             sec = min/60.0;
             latitude = deg + sec;

             longitude = atof(longARR);
              deg = longitude/100;
              min = longitude - (f32)(deg*100);
              sec = min/60.0;
              longitude = deg + sec;
              return functionErrorState = Done;
}

/*
 * Description :
 * calculate the distance from a constant starting latitude and longitude using haversine formula
 */

f64 GPS_f64getDistance(void){
    // convert all coordinates from Degrees into Radians
    f64 Local_f64startLat = startLatitude* M_PI/180;
    f64 Local_f64startLong = startlongitude* M_PI/180;
    f64 Local_f64endLat = latitude* M_PI/180;
    f64 Local_f64endLong = longitude* M_PI/180;

    // calculate latitude difference and longitude difference
    f64 Local_f64latDifference = Local_f64endLat - Local_f64startLat;
    f64 Local_f64longDifference = Local_f64endLong - Local_f64startLong;

    //use Haversine formula
    f64 Local_f64a = sin(Local_f64latDifference / 2) * sin(Local_f64latDifference / 2) + cos(Local_f64startLat) * cos(Local_f64endLat)
    * sin(Local_f64longDifference / 2) * sin(Local_f64longDifference / 2);
    f64 Local_f64c = 2 * atan2(sqrt(Local_f64a), sqrt(1 - Local_f64a));

    //Multipy by Earth's Radius to get the distance
    f64 copy_pf64distance = Local_f64c * Earth_Radius;
    return copy_pf64distance;
}
