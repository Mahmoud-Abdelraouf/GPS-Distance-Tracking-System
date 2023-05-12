

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
#include "../APP/main.h"
/******************************< Global Variables *****************/
f32 latitude, longitude;
f32 end_Lat, end_Long;
/******************************< main *****************************/
int main(void)
{
    /******************************< Init *****************************/
    LCD_voidInit();
    /******************************< Variables *************************/
    GPS_voidReceiveSentence();
    f32 Local_f32OldLongitude = longitude;
    f32 Lcoal_f32OldLatitude = latitude;
    f32 Local_f32CurrentLongitude = 0;
    f32 Lcoal_f32CurrentLatitude = 0;
    f32 Local_f32TotalDistance = 0;
    f32 Lcoal_f32DeltaDistance = 0;
    /****************************** Setup *****************************/
    LCD_voidSendString("Total Distance:");
    LCD_voidGoToXYPos(1, 0);
    LCD_voidSendNumber(latitude);
    /******************************< Super loop ***********************/
    while(1)
    {
        GPS_voidReceiveSentence();
    }


	return 0;
}
