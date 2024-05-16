/********************************************************************/
/************* Name    : ASU_EMBEDDED_TEAM_NO?!      ****************/
/************* Date    : 14/04/2023                  ****************/
/************* SWC     : APP_MAIN                    ****************/
/************* Version : 1.0                         ****************/
/********************************************************************/
/*<------------------------------< LIB ------------------------------*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*<------------------------------< MCAL ------------------------------*/
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"

/*<------------------------------< HAL ------------------------------*/
#include "CLCD_interface.h"
#include "GPS_interface.h"
#include "LED_interface.h"

/*<------------------------------< APP ------------------------------*/
#include "APP.h"

/*<------------------------------< Global Variables Section ------------------------------*/
char GPS_SpeedArr[5]; // Array to store GPS speed

int main() {

    /*<--------------------< Local Variables: Exceptional variables --------------------*/
    f64 Local_Latitude = 0;  // Current latitude
    f64 Local_Longitude = 0; // Current longitude
    u8 Local_Speed = 0;      // Current speed

    /*<--------------------< Local Variables --------------------*/
    GPS_ReceiveSentence(&Local_Latitude, &Local_Longitude, &Local_Speed); // Receive GPS data

    /*<--------------------< Local Variables --------------------*/
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

    /*<--------------------< LCD Configuration --------------------*/
    // Declare an instance of LCD configuration structure.
    LCD_Config_t lcd1;

    // Set the mode of operation to 4-bit mode.
    lcd1.mode = LCD_4BitMode;

    // Configure data pins for 4-bit mode operation.
    for (u8 i = 0; i < 4; i++) {
        // Set the port ID for data pin i to GPIO_PORTA.
        lcd1.dataPins[i].LCD_PortId = GPIO_PORTA;
        // Set the pin ID for data pin i using GPIO_PIN3 - i.
        lcd1.dataPins[i].LCD_PinId = GPIO_PIN4 + i;
    }

    // Configure enable pin.
    // Set the port ID for the enable pin to GPIO_PORTA.
    lcd1.enablePin.LCD_PortId = GPIO_PORTA;
    // Set the pin ID for the enable pin to GPIO_PIN4.
    lcd1.enablePin.LCD_PinId = GPIO_PIN2;

    // Configure rs pin.
    // Set the port ID for the rs pin to GPIO_PORTA.
    lcd1.rsPin.LCD_PortId = GPIO_PORTA;
    // Set the pin ID for the rs pin to GPIO_PIN5.
    lcd1.rsPin.LCD_PinId = GPIO_PIN1;

    // Initialize the LCD module with the configured settings.
    LCD_Init(&lcd1);
    LCD_Clear(&lcd1);

    /**< Display a welcome message */
    LCD_SendString(&lcd1, (uint8_t *)"Welcome to our");
    LCD_GoToXYPos(&lcd1, 0, 1);
    LCD_SendString(&lcd1, (uint8_t *)"GPS Project");

    /*<--------------------< UART Configuration --------------------*/
    UART_Init(UART5, UART_BDR_9600, UART_DATA_8, UART_PARITY_NONE, UART_STOP_BIT_1); // Initialize UART

    /*<--------------------< LED Configuration --------------------*/
    LED_LedInit(); 

    /*<--------------------< GPS Configuration --------------------*/

    /*<--------------------< Welcome window Configuration --------------------*/
    LCD_SendString(&lcd1, (uint8_t *)"Total Dist:"); 
    LCD_GoToXYPos(&lcd1, 0, 14);
    LCD_SendString(&lcd1, (uint8_t *)" m");
    LCD_GoToXYPos(&lcd1, 1, 0);
    LCD_SendString(&lcd1, (uint8_t *)"SPEED:");
    LCD_GoToXYPos(&lcd1, 1, 12);
    LCD_SendString(&lcd1, (uint8_t *)"knot");

    /*<------------------------------< Super Loop ------------------------------*/
    while(1)
    {
        GPS_ReceiveSentence(&Local_Latitude, &Local_Longitude, &Local_Speed); // Receive updated GPS data
        
		Local_CurrentLatitude = Local_Latitude;   // Update current latitude
        
		Local_CurrentLongitude = Local_Longitude; // Update current longitude
        APP_GetDistance(Local_OldLatitude, Local_OldLongitude,Local_CurrentLatitude, Local_CurrentLongitude, &Local_DeltaDistance); // Calculate distance between two points
        APP_GetDistance(Local_EndLatitude, Local_EndLongitude,Local_CurrentLatitude, Local_CurrentLongitude, &Local_DistanceTilEnd); // Calculate distance to end location
        
		LCD_GoToXYPos(&lcd1, 1, 6);
        LCD_SendString(&lcd1, (uint8_t *)GPS_SpeedArr); // Display current speed on LCD
        
		if(Local_Speed > 0.5) // If speed is greater than 0.5 knots
        {
            Local_TotalDistance += Local_DeltaDistance;  // Update total distance
            Local_OldLongitude = Local_CurrentLongitude; // Update previous longitude
            Local_OldLatitude = Local_CurrentLatitude;   // Update previous latitude
            
			LCD_GoToXYPos(&lcd1, 0, 11); // New Line in LCD @ position:(1, 0) 
            LCD_SendNumber(&lcd1, Local_TotalDistance); // Display updated total distance
            
			if(Local_DistanceTilEnd < 5) // If distance to end location is less than 5 meters
            {
                LED_xLedOff();                  // Turn off all LEDs
                LED_LedOn(LED_GREEN); // Turn on green LED
                LCD_GoToXYPos(&lcd1, 1, 0);
                LCD_SendString(&lcd1, (uint8_t *)"Mission Success!"); // Display mission success message
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
    return 0; // Return 0 to indicate
