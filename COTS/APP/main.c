/******************************************************************/
/***************** Name    : ASU_EMBEDDED_TEAM_3      *************/
/***************** Date    : 25/04/2023               *************/
/***************** SWC     : APP_MAIN                 *************/
/***************** Version : 1.0                      *************/
/******************************************************************/

/******************************< SYSTEM ***************************/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/******************************< LIB ******************************/
#include "STD_TYPES.h"

/******************************< MCAL *****************************/
#include "DIO_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"

/******************************< HAL ******************************/
#include "LED_interface.h"
#include "LCD_interface.h"
#include "GPS_interface.h"

/******************************< APP ******************************/
#include "APP.h"

/******************************< Global Variables *****************/
char GPS_SpeedArr[5]; // Array to store GPS speed

/******************************< main *****************************/
int main(void)
{
    /******************************< Local Variables:Exceptional variables *******************/
    f64 Local_Latitude = 0;  // Current latitude
    f64 Local_Longitude = 0; // Current longitude
    u8 Local_Speed = 0;      // Current speed

    /******************************< functions which define the variables ********************/
    GPS_ReceiveSentence(&Local_Latitude, &Local_Longitude, &Local_Speed); // Receive GPS data

    /******************************< Local Variables *****************************************/
    f64 Local_OldLongitude = Local_Longitude; // Previous longitude
    f64 Local_OldLatitude = Local_Latitude;   // Previous latitude
    f64 Local_CurrentLongitude = 0;           // Updated longitude
    f64 Local_CurrentLatitude = 0;            // Updated latitude
    f32 Local_TotalDistance = 0;              // Total distance traveled
    f32 Local_DeltaDistance = 0;              // Distance between two consecutive points
    f64 Local_EndLongitude = 0;               // End longitude
    f64 Local_EndLatitude = 0;                // End latitude
    f32 Local_DistanceTilEnd = 0;             // Distance to end location
    u8  Local_EndLocationLatitudeArray[15] = {0}; // Array to store end latitude
    u8  Local_EndLocationLongitudeArray[15] = {0}; // Array to store end longitude

    /******************************< Init ****************************************************/
    LCD_Init(); // Initialize LCD
    UART_Init(UART5, UART_BDR_9600, UART_DATA_8, UART_PARITY_NONE, UART_STOP_BIT_1); // Initialize UART
    LED_LedInit(); // Initialize LEDs

    /****************************** Setup ****************************************************/
    LCD_SendString("Total Dist:"); // Display total distance on LCD
    LCD_GoToXYPos(0, 14);
    LCD_SendString(" m");
    LCD_GoToXYPos(1, 0);
    LCD_SendString("SPEED:");
    LCD_GoToXYPos(1, 12);
    LCD_SendString("knot");

    /******************************< Bluetooth Module **********************************************/
    UART_SendString(UART5, "Enter latitude of your end location\n");  // Prompt user for end latitude
    UART_ReceiveString(UART5, Local_EndLocationLatitudeArray);        // Receive end latitude
    Local_EndLatitude = atof(Local_EndLocationLatitudeArray);         // Convert end latitude to float
    UART_SendString(UART5, "Enter longitude of your end location\n"); // Prompt user for end longitude
    UART_ReceiveString(UART5, Local_EndLocationLongitudeArray); // Receive end longitude
    Local_EndLongitude = atof(Local_EndLocationLongitudeArray); // Convert end longitude to float

    /******************************< Super loop **********************************************/
    while(1)
    {
        GPS_ReceiveSentence(&Local_Latitude, &Local_Longitude, &Local_Speed); // Receive updated GPS data
        Local_CurrentLatitude = Local_Latitude;   // Update current latitude
        Local_CurrentLongitude = Local_Longitude; // Update current longitude
        APP_GetDistance(Local_OldLatitude, Local_OldLongitude,Local_CurrentLatitude, Local_CurrentLongitude, &Local_DeltaDistance); // Calculate distance between two points
        APP_GetDistance(Local_EndLatitude, Local_EndLongitude,Local_CurrentLatitude, Local_CurrentLongitude, &Local_DistanceTilEnd); // Calculate distance to end location
        LCD_GoToXYPos(1, 6);
        LCD_SendString(GPS_SpeedArr); // Display current speed on LCD
        if(Local_Speed > 0.5) // If speed is greater than 0.5 knots
        {
            Local_TotalDistance += Local_DeltaDistance;  // Update total distance
            Local_OldLongitude = Local_CurrentLongitude; // Update previous longitude
            Local_OldLatitude = Local_CurrentLatitude;   // Update previous latitude
            LCD_GoToXYPos(0, 11); // New Line in LCD @ position:(1, 0) 
            LCD_SendNumber(Local_TotalDistance); // Display updated total distance
            if(Local_DistanceTilEnd < 5) // If distance to end location is less than 5 meters
            {
                LED_LedOffAll();      // Turn off all LEDs
                LED_LedOn(LED_GREEN); // Turn on green LED
                LCD_GoToXYPos(1, 0);
                LCD_SendString("Mission Success!"); // Display mission success message
                break; // Exit loop
            }
            else if(Local_DistanceTilEnd < 15) // If distance to end location is less than 15 meters
            {
                // Green with Red makes Yellow
                LED_LedOn(LED_GREEN); // Turn on green LED
                LED_LedOn(LED_RED);   // Turn on red LED
            }
            else // If distance to end location is greater than or equal to 15 meters
            {
                LED_LedOn(LED_RED); // Turn on red LED
            }
        }
    }
    return 0; // Return 0 to indicate successful execution
}
