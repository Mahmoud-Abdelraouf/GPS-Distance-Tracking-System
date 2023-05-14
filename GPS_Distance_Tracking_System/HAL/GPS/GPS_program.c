//*************************************************
//**** Name    : ASU_EMBEDDED_TEAM_3      *********
//**** Date    : 25/04/2023               *********
//**** SWC     : HAL_GPS                  *********
//**** Version : 1.0                      *********
//*************************************************
/******************************< SYSTEM ****************************/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/******************************< LIB ******************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/**< MCAL */
#include "../../MCAL/UART/UART_interface.h"

/******************************< HAL ******************************/
/**< GPS */
#include "../../HAL/GPS/GPS_private.h"
#include "../../HAL/GPS/GPS_interface.h"
#include "../../HAL/GPS/GPS_config.h"
/**< LCD */
#include "../../HAL/LCD/LCD_interface.h"
/******************************< Global Variables *****************/
extern char GPS_u8SpeedArr[5];
/******************************<  ******************************/

// Reverses a string 'str' of length 'len'
void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}


void ftoa(float n, char* res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
/******************************<  ******************************/

/**
 * Description :
 * Receive a complete NMEA sentence from GPS module
 * $GNRMC,204520.00,A,5109.0262239,N,11401.8407338,W,0.004,102.3,130522,0.0,E,D*3B
 */


void GPS_voidReceiveSentence(f64 *copy_f64Latitude,f64 *copy_f64Longitude, u8 *copy_u8Speed)
{
    static u8 Local_u8UART_InitFlag = 0;
    u8 Local_u8ReadCounter  = 0;
    u8 Local_u8GPS_Sentence[100];
    u8 Local_u8GPS_Check[] = "$GNRMC,";
    u8 Local_u8ReceivedChar;
    if(Local_u8UART_InitFlag == 0)
    {
        UART_voidInit(UART2, UART_BDR_9600, UART_DATA_8, UART_PARITY_NONE, UART_STOP_BIT_1);
        Local_u8UART_InitFlag++;
    }
    do
    {
        UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
        if (Local_u8ReceivedChar == Local_u8GPS_Check[0])
        {
            UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
            if (Local_u8ReceivedChar == Local_u8GPS_Check[1])
            {
                UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
                if (Local_u8ReceivedChar == Local_u8GPS_Check[2])
                {
                    UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
                    if (Local_u8ReceivedChar == Local_u8GPS_Check[3])
                    {
                        UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
                        if (Local_u8ReceivedChar == Local_u8GPS_Check[4])
                        {
                            UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
                            if (Local_u8ReceivedChar == Local_u8GPS_Check[5])
                            {
                                UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
                                if (Local_u8ReceivedChar == Local_u8GPS_Check[6])
                                {
                                    UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
                                    while(Local_u8ReceivedChar != '*')
                                    {
                                        Local_u8GPS_Sentence[Local_u8ReadCounter] = Local_u8ReceivedChar;
                                        UART_voidReceiveByte(UART2,&Local_u8ReceivedChar);
                                        Local_u8ReadCounter++;
                                    }
                                    GPS_voidExtractCoordinates(Local_u8GPS_Sentence,copy_f64Latitude,copy_f64Longitude,copy_u8Speed);
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(Local_u8ReadCounter == 0);
}
/*
 * Description :
 * return the coordinates of your current location using gps module
 */

void GPS_voidExtractCoordinates(u8 *copy_pu8Sentence,f64 *copy_f64Latitude,f64 *copy_f64Longitude, u8 *copy_u8Speed)
{
    f32 Local_f32Deg,Lcoal_f32Min,Local_f32Sec;
    u8 Local_u8CommaCount = 0;
    u8 j = 0;
    u8 k = 0;
    u8 l = 0;
    char longARR[15] = {0};
    char altitudeARR[15] = {0};
    u8 i = 0;
    char speedArr[10];
    while(Local_u8CommaCount<7)
    {
        if (copy_pu8Sentence[i] == ',')
        {
            Local_u8CommaCount++;
            i++;
        }
        if(Local_u8CommaCount == 1)
        {
            if (copy_pu8Sentence[i]!='A')
            {
                GPS_voidReceiveSentence(copy_f64Latitude,copy_f64Longitude,copy_u8Speed);
            }
        }
        if(Local_u8CommaCount == 2)
        {
            altitudeARR[j++]=copy_pu8Sentence[i];
        }
        if(Local_u8CommaCount == 4)
        {
            longARR[k++]=copy_pu8Sentence[i];
        }
        if(Local_u8CommaCount == 6)
        {
            speedArr[l++]=copy_pu8Sentence[i];
        }
        i++;
    }
    *copy_f64Latitude = atof(altitudeARR);
    Local_f32Deg = *copy_f64Latitude/100;
    Lcoal_f32Min = *copy_f64Latitude - (f32)(Local_f32Deg*100);
    Local_f32Sec = Lcoal_f32Min/60.0;
    *copy_f64Latitude = Local_f32Deg + Local_f32Sec;

    *copy_f64Longitude = atof(longARR);
    Local_f32Deg = *copy_f64Longitude/100;
    Lcoal_f32Min = *copy_f64Longitude - (f32)(Local_f32Deg*100);
    Local_f32Sec = Lcoal_f32Min/60.0;
    *copy_f64Longitude = Local_f32Deg + Local_f32Sec;

    for(int i = 0 ;i<5;i++)
    {
        GPS_u8SpeedArr[i] = speedArr[i];
    }
    *copy_u8Speed = atof(speedArr);

}

/*
 * Description :
 * calculate the distance from a constant starting latitude and longitude using haversine formula
 */
//
//f64 GPS_f64GetDistance(void){
//    // convert all coordinates from Degrees into Radians
//    f64 Local_f64startLat = startLatitude* M_PI/180;
//    f64 Local_f64startLong = startlongitude* M_PI/180;
//    f64 Local_f64endLat = latitude* M_PI/180;
//    f64 Local_f64endLong = longitude* M_PI/180;
//
//    // calculate latitude difference and longitude difference
//    f64 Local_f64latDifference = Local_f64endLat - Local_f64startLat;
//    f64 Local_f64longDifference = Local_f64endLong - Local_f64startLong;
//
//    //use Haversine formula
//    f64 Local_f64a = sin(Local_f64latDifference / 2) * sin(Local_f64latDifference / 2) + cos(Local_f64startLat) * cos(Local_f64endLat)
//    * sin(Local_f64longDifference / 2) * sin(Local_f64longDifference / 2);
//    f64 Local_f64c = 2 * atan2(sqrt(Local_f64a), sqrt(1 - Local_f64a));
//
//    //Multipy by Earth's Radius to get the distance
//    f64 copy_pf64distance = Local_f64c * Earth_Radius;
//    return copy_pf64distance;
//}
//
