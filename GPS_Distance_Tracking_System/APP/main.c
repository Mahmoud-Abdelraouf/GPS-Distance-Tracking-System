

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


/******************************< main *****************************/
int main(void)
{

    /******************************< Local Variables:Exceptional variables *******************/
    f64 Local_f64Latitude = 0;
    f64 Local_f64Longitude = 0;
    /******************************< functions which define the variables ********************/
    GPS_voidReceiveSentence(&Local_f64Latitude,&Local_f64Longitude);
    /******************************< Local Variables *****************************************/
    f64 Local_f32OldLongitude = Local_f64Longitude;
    f64 Lcoal_f32OldLatitude = Local_f64Latitude;
    f64 Local_f32CurrentLongitude = 0;
    f64 Lcoal_f32CurrentLatitude = 0;
    f32 Local_f32TotalDistance = 0;
    f32 Lcoal_f32DeltaDistance = 0;
    /******************************< Init ****************************************************/
    LCD_voidInit();
    /****************************** Setup ****************************************************/
    LCD_voidSendString("Total Distance:");
    LCD_voidGoToXYPos(1, 0);
    /******************************< Super loop **********************************************/
    while(1)
    {
        GPS_voidReceiveSentence(&Local_f64Latitude,&Local_f64Longitude);
        Lcoal_f32CurrentLatitude = Local_f64Latitude;
        Local_f32CurrentLongitude = Local_f64Longitude;
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
