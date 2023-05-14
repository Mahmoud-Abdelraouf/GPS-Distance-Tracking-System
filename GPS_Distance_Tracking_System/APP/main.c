

/**
 * main.c
 */
/******************************< SYSTEM ***************************/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/******************************< LIB ******************************/
#include "../LIB/STD_TYPES.h"
/******************************< MCAL *****************************/
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/STK/STK_interface.h"
#include "../MCAL/UART/UART_interface.h"
/******************************< HAL ******************************/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/GPS/GPS_interface.h"
/******************************< APP ******************************/
#include "../APP/APP.h"
/******************************< main *****************************/
int main(void)
 {
    /******************************< Local Variables:Exceptional variables *******************/
    f64 Local_f64Latitude = 0;
    f64 Local_f64Longitude = 0;
    u8 Local_u8Speed = 0;
    /******************************< functions which define the variables ********************/
    GPS_voidReceiveSentence(&Local_f64Latitude,&Local_f64Longitude,&Local_u8Speed);
    /******************************< Local Variables *****************************************/
    f64 Local_f32OldLongitude = Local_f64Longitude;
    f64 Local_f32OldLatitude = Local_f64Latitude;
    f64 Local_f32CurrentLongitude = 0;
    f64 Local_f32CurrentLatitude = 0;
    f32 Local_f32TotalDistance = 0;
    f32 Local_f32DeltaDistance = 0;
    f64 Local_f32EndLongitude = 0;
    f64 Local_f32EndLatitude = 0;
    f32 Local_f32DistanceTilEnd = 0;
    u8  Local_u8EndLocationLatitudeArray[15] = {0};
    u8  Local_u8EndLocationLongitudeArray[15] = {0};
    /******************************< Init ****************************************************/
    LCD_voidInit();
    UART_voidInit(UART5, UART_BDR_9600, UART_DATA_8, UART_PARITY_NONE, UART_STOP_BIT_1);
    LED_voidLedInit();
    /****************************** Setup ****************************************************/
    LCD_voidSendString("Total Distance:");
    LCD_voidGoToXYPos(1, 0);
    /******************************< Bluetooth Module **********************************************/
    UART_voidSendString(UART5,"Enter latitude of your end location\n");
    UART_voidReceiveString(UART5,Local_u8EndLocationLatitudeArray);
    Local_f32EndLatitude = atof(Local_u8EndLocationLatitudeArray);
    UART_voidSendString(UART5,"Enter longitude of your end location\n");
    UART_voidReceiveString(UART5,Local_u8EndLocationLongitudeArray);
    Local_f32EndLongitude = atof(Local_u8EndLocationLongitudeArray);
    /******************************< Super loop **********************************************/
    while(1)
    {
        LED_voidLedOff(LED_GREEN);
        LED_voidLedOff(LED_RED);
        GPS_voidReceiveSentence(&Local_f64Latitude,&Local_f64Longitude, &Local_u8Speed);
        Local_f32CurrentLatitude = Local_f64Latitude;
        Local_f32CurrentLongitude = Local_f64Longitude;
        APP_voidGetDistance(Local_f32OldLatitude, Local_f32OldLongitude,Local_f32CurrentLatitude, Local_f32CurrentLongitude, &Local_f32DeltaDistance);
        APP_voidGetDistance(Local_f32EndLatitude, Local_f32EndLongitude,Local_f32CurrentLatitude, Local_f32CurrentLongitude, &Local_f32DistanceTilEnd);
        if(Local_u8Speed > 0)
        {
            Local_f32TotalDistance += Local_f32DeltaDistance;
            Local_f32OldLongitude = Local_f32CurrentLongitude;
            Local_f32OldLatitude = Local_f32CurrentLatitude;
            LCD_voidSendNumber(Local_f32TotalDistance);
            LCD_voidGoToXYPos(1, 0);
            if((((Local_f32EndLongitude-Local_f32CurrentLongitude)>0.01) || ((Local_f32EndLongitude-Local_f32CurrentLongitude)<0.01))   &&  (((Local_f32EndLatitude-Local_f32CurrentLatitude)>0.01) || ((Local_f32EndLatitude-Local_f32CurrentLatitude)<0.01)))
            {
                LED_voidLedOn(LED_GREEN);
                LCD_voidSendString("Mission Success!");
                break;
            }
            else if (Local_f32TotalDistance > 100 && Local_f32TotalDistance<120)
            {
                LED_voidLedOn(LED_GREEN);
                LED_voidLedOn(LED_RED);   //green with red makes yellow
            }
            else
            {
                LED_voidLedOn(LED_RED);
            }
        }
    }
    return 0;
}
