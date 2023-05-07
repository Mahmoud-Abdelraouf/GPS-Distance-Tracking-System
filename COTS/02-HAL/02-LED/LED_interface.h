//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 26/04/2023              	*************
//********** SWC     : HAL_LED                  *************
//********** Version : 1.0                    	*************
//***********************************************************
#ifndef __HAL_LED_INTERFACE_H__
#define __HAL_LED_INTERFACE_H__


/********************************< MACROS for colours ********************************/
#define LED_RED  	 	1
#define LED_BLUE 		2
#define LED_GREEN	  3
/********************************< functions for LEDs *********************************/
/** \brief	The function LED_voidLedInit initializes the direction of three LEDs, namely a blue LED, a green LED, 
 *			and a red LED by configuring the corresponding pins of the microcontroller as output pins.
 *
 *			The function first calls DIO_voidInit function which initializes the microcontroller's general-purpose input/output (GPIO) pins, 
 *			specifically the ones associated with port F.
 *
 *			Then, the function configures the direction of each LED by calling DIO_u8SetPinDirection function three times, passing the port number (DIO_u8_PORTF) and the pin numbers (LED_BLUE_PIN, LED_GREEN_PIN, and LED_RED_PIN) as 
 *			arguments with the third argument being DIO_u8_OUTPUT to set the pins as output.
 *			This function is likely part of a larger program that controls the behavior of the LEDs.
 *
 * \param	void
 * \return	void
 *
 */ 
void LED_voidLedInit(void);
/** \brief	The function LED_voidLedOn turns on one of three LEDs based on the value of the argument copy_u8LedColour, 
 *			which can be LED_BLUE, LED_GREEN, or LED_RED.
 *
 *			The function uses a switch statement to determine which LED to turn on. 
 *			When the value of copy_u8LedColour matches one of the defined LED colors, the corresponding pin is set to 
 *			DIO_u8_HIGH using the DIO_u8SetPinValue function, which turns on the LED. 
 *			If the value of copy_u8LedColour does not match any of the defined colors, the function does nothing (default : break).
 *
 *			In summary, this function is part of a larger program that controls the behavior
 *			of the LEDs and is used to turn on one of the three LEDs.
 *
 * \param	The Color of the led you want to on it
 * \return	void
 *
 */
void LED_voidLedOn(u8 copy_u8LedColour);	    
/** \brief	The function LED_voidLedOff turns off one of three LEDs based on the value of the argument copy_u8LedColour, 
 *			which can be LED_BLUE, LED_GREEN, or LED_RED.
 *
 *			The function uses a switch statement to determine which LED to turn off. When the value of copy_u8LedColour matches 
 * 			one of the defined LED colors, the corresponding pin is set to DIO_u8_LOW using the DIO_u8SetPinValue function, which turns off the LED. 
 *			If the value of copy_u8LedColour does not match any of the defined colors, the function does nothing (default : break).
 *
 *			In summary, this function is also part of a larger program that controls the behavior of the LEDs and is used to turn off one of the three LEDs.
 *
 * \param	The Color of the led you want to off it
 * \return  void
 *
 */
void LED_voidLedOff(u8 copy_u8LedColour);	   
/** \brief	The function LED_voidLedTog toggles the state of one of three LEDs based on the value of the argument copy_u8LedColour, which can be LED_BLUE, LED_GREEN, or LED_RED.
 *
 *			The function uses a switch statement to determine which LED to toggle. When the value of copy_u8LedColour 
 *			matches one of the defined LED colors, the corresponding pin is toggled using the DIO_u8TogglePinValue function, which changes the state of the LED. 
 *			If the value of copy_u8LedColour does not match any of the defined colors, the function does nothing (default : break).
 *
 *			In summary, this function is also part of a larger program that controls the 
 *			behavior of the LEDs and is used to toggle the state of one of the three LEDs.
 *
 * \param	The Color of the led you want to toggle it
 * \return  void
 *
 */
void LED_voidLedTog(u8 copy_u8LedColour);       
/** \brief	The function LED_voidLedBlinkOnce blinks one of three LEDs once based on the value of the argument copy_u8LedColour, 
 *			which can be LED_BLUE, LED_GREEN, or LED_RED.
 *
 *			The function uses a switch statement to determine which LED to blink. When the value of copy_u8LedColour matches one 
 *			of the defined LED colors, the corresponding pin is set to DIO_u8_HIGH using the DIO_u8SetPinValue function, which turns on the LED. Then, 
 *			the function waits for a certain time period using the STK_voidDelay function (whose argument is LED_TIME_ON), and then turns off the 
 *			LED by setting the corresponding pin to DIO_u8_LOW. If the value of copy_u8LedColour 
 *			does not match any of the defined colors, the function does nothing (default : break).
 *
 *			In summary, this function is part of a larger program that controls the behavior of the LEDs and is used to 
 *			blink one of the three LEDs once.
 *
 * \param	The Color of the led you want to blink once 
 * \return  void
 *
 */
void LED_voidLedBlinkOnce(u8 copy_u8LedColour);	  
/** \brief	This is a function called LED_voidLedBlinkTwice that blinks an LED twice. The function takes an input 
 *			argument copy_u8LedColour which specifies the color of the LED to blink.
 *
 *			The function first calls another function LED_voidLedBlinkOnce with the same input argument 
 *			to blink the LED once. Then it calls a delay function STK_voidDelay with an argument LED_TIME_ON, 
 *			which is a constant representing the time the LED should be turned on during each blink. 
 *			After the delay, the function calls LED_voidLedBlinkOnce again to blink the LED for the second time.
 *
 *			Overall, the function produces two consecutive blinks of an LED with the specified color, 
 *			with a short delay between them.
 *
 * \param	The Color of the led you want to blink twice
 * \return  void
 *
 */
void LED_voidLedBlinkTwice(u8 copy_u8LedColour); 
/** \brief	This is a function called LED_voidLedOff that turns off all three LEDs (blue, red, and green) 
 *			connected to a microcontroller. The function achieves this by calling a function called 
 *			DIO_u8SetPinValue three times, each time passing it the port and pin number of the LED to turn off, 
 *			as well as the value DIO_u8_LOW, which represents a logic low voltage level.
 *
 *			The DIO_u8SetPinValue function is likely a low-level function that interacts with the microcontroller's 
 *			hardware to set the voltage level of a specific pin. The port and pin numbers specified in the function 
 *			calls correspond to the specific pins of the microcontroller that are connected to the LEDs. By setting the voltage 
 *			level of these pins to logic low, the function effectively turns off all three LEDs.	
 *			
 * \param	void
 * \return  void
 *
 */
void LED_voidLedOff(void);


#endif //__HAL_LED_INTERFACE_H__
