

/**
 * main.c
 */
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
/******************************< Global Variables *****************/
f32 GPS_f32Latitude,GPS_f32Longitude;
f32 GPS_f32EndLatitude, GPS_f32EndLongitude;
/******************************< main *****************************/
int main(void)
{
    /******************************< Init *************************/
    LCD_voidInit();
    GPS_voidReceiveSentence();
    /******************************< Variables ********************/
    f32 Local_f32OldLongitude = GPS_f32Longitude;
    f32 Lcoal_f32OldLatitude = GPS_f32Latitude;
    f32 Local_f32CurrentLongitude = 0;
    f32 Lcoal_f32CurrentLatitude = 0;
    f32 Local_f32TotalDistance = 0;
    f32 Lcoal_f32DeltaDistance = 0;
    /****************************** Setup *****************************/
    LCD_voidSendString("Total Distance:");
    LCD_voidGoToXYPos(1, 0);
    /******************************< Super loop ***********************/
    while(1)
    {
        GPS_voidReceiveSentence();
        Lcoal_f32CurrentLatitude = GPS_f32Latitude;
        Local_f32CurrentLongitude = GPS_f32Longitude;
        STK_voidDelay(4000);
        APP_voidGetDistance(Lcoal_f32OldLatitude, Local_f32OldLongitude,Lcoal_f32CurrentLatitude, Local_f32CurrentLongitude, &Lcoal_f32DeltaDistance);
        Local_f32TotalDistance += Lcoal_f32DeltaDistance;
        Local_f32OldLongitude = Local_f32CurrentLongitude;
        Lcoal_f32OldLatitude = Lcoal_f32CurrentLatitude;
        LCD_voidSendNumber(Local_f32TotalDistance);
        LCD_voidGoToXYPos(1, 0);
    }
	return 0;
}
