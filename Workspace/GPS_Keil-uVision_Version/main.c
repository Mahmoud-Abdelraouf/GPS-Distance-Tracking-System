/**************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_NO?!		    ***********/
/********** Date    : 14/04/2023              	    ***********/
/********** SWC     : MCAL_GPIO                  	  ***********/
/********** Version : 1.0                    		    ***********/
/**************************************************************/
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
/*<------------------------------< HAL ------------------------------*/
#include "APP.h"

/*<------------------------------< Global Variables Section ------------------------------*/
char GPS_SpeedArr[5];

int main() {
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
	
	/*<--------------------< LED Configuration --------------------*/
	
	
	/*<--------------------< GPS Configuration --------------------*/
	
	
	/*<------------------------------< Super Loop ------------------------------*/
	while(1) {



	}

}


