//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 25/04/2023              	*************
//********** SWC     : HAL_LCD                  *************
//********** Version : 1.0                    	*************
//***********************************************************
#ifndef __HAL_LCD_INTERFACE_H__
#define __HAL_LCD_INTERFACE_H__

/** \brief 	This function is responsible for initializing an LCD display module. The function takes no parameters and returns nothing (void).
 *			The function first checks if the LCD mode is set to 8-bit or 4-bit mode using preprocessor directives. Depending on the mode, it initializes the necessary pins for the LCD display module using the DIO_voidInit() function. If the data pins and control pins are on separate ports, it initializes both ports.
 * 			The function then sets the direction of the necessary pins to output using the DIO_u8SetPinDirection() function. The necessary pins include data pins D0-D7, RS (Register Select) pin, and EN (Enable) pin.
 *			The function then waits for 1 millisecond using the STK_voidDelay() function to give the LCD display module time to power up.
 *			Next, the function sends commands to the LCD display module using the LCD_voidSendCommand() function. The commands include setting the LCD mode to 8-bit or 4-bit mode, clearing the display, and turning on the display.
 *			If the LCD mode is not set to 8-bit or 4-bit mode, the function throws an error using a preprocessor directive.
 *
 * \param 	void
 * \return 	void
 *
 */

void LCD_voidInit(void);
/** \brief	This function is responsible for sending a command to the LCD display module. The function takes a single parameter, which is the command to be sent (copy_u8Command), and returns nothing (void).
 *			The function first sets the RS (Register Select) pin to low to indicate that a command is being sent. It also sets the RW (Read/Write) pin to low to indicate that the operation is a write operation.
 *			Depending on the LCD mode (8-bit or 4-bit), the function sets the necessary data pins to the corresponding bits of the command using the DIO_u8SetPinValue() function.
 *			The function then sets the EN (Enable) pin to high to enable the LCD display module to read the command. After a short delay using the STK_voidDelay() function, the function sets the EN pin to low to complete the command.
 *			If the LCD mode is set to 4-bit mode, the function shifts the 4 least significant bits of the command to the 4 most significant bits and repeats the same process for these bits.
 *			If the LCD mode is not set to 8-bit or 4-bit mode, the function throws an error using a preprocessor directive.
 *
 * \param 	The command you will send to the LCD
 * \return	void
 *
 */

void LCD_voidSendCommand(u8 copy_u8Command);

/** \brief	This function is responsible for sending a character to the LCD display module. The function takes a single parameter, which is the character to be sent (copy_u8Char), and returns nothing (void).
 *			The function first sets the RS (Register Select) pin to high to indicate that a data character is being sent. It also sets the RW (Read/Write) pin to low to indicate that the operation is a write operation.
 *			Depending on the LCD mode (8-bit or 4-bit), the function sets the necessary data pins to the corresponding bits of the character using the DIO_u8SetPinValue() function.
 *			The function then sets the EN (Enable) pin to high to enable the LCD display module to read the character. After a short delay using the STK_voidDelay() function, the function sets the EN pin to low to complete the character transmission.
 *			If the LCD mode is set to 4-bit mode, the function shifts the 4 least significant bits of the character to the 4 most significant bits and repeats the same process for these bits.
 *			If the LCD mode is not set to 8-bit or 4-bit mode, the function throws an error using a preprocessor directive.
 *
 * \param 	The char you want to Send to the LCD
 * \return	void
 *
 */

void LCD_voidSendChar(u8 copy_u8Char);

/** \brief	This function is responsible for sending a string of characters to the LCD display module. The function takes a single parameter, which is a pointer to the beginning of the string (copy_pu8String), and returns nothing (void).
 * 			The function uses a while loop to iterate through each character of the string. The loop continues until it reaches the null character ('\0') at the end of the string.
 * 			For each character in the string, the function calls the LCD_voidSendChar() function to send the character to the LCD display module.
 * 			The function uses a local variable called Local_u8Counter to keep track of the current character in the string. This variable is incremented by 1 after each character is sent to the LCD display module.
 *			Overall, this function is useful for displaying strings of text on the LCD display module.
 *
 * \param	The string you want to display on the LCD
 * \return	void
 *
 */

void LCD_voidSendString(u8 *copy_pu8String);

/** \brief	This function is responsible for sending a floating-point number to the LCD display module. The function takes a single parameter, which is the floating-point number to be sent (copy_f64Number), and returns nothing (void).
 *			The function first creates an array of 11 elements to store the integer part of the floating-point number. It also creates a local counter variable to keep track of the number of digits in the integer part.
 *			If the floating-point number is negative, the function first sends a minus sign '-' to the LCD display module and then converts the number to its absolute value.
 *			The function then uses a do-while loop to extract each digit of the integer part of the floating-point number and store it in the Local_u8Integer array. The loop continues until the integer part of the number is equal to 0. The digits are extracted by taking the modulo 10 of the number and then dividing the number by 10.
 *			After extracting the digits, the counter is decremented to point to the last digit in the Local_u8Integer array. The function then uses a for loop to send each digit to the LCD display module as a character. Each digit is converted to its ASCII character by adding 48 to its value.
 *			Overall, this function is useful for displaying floating-point numbers on the LCD display module. However, it only displays the integer part of the number and ignores the decimal part.
 *
 * \param 	The number you want to display on the LCD
 * \return	void
 *
 */

void LCD_voidSendNumber(f64 copy_f64Number);

/** \brief	This function is responsible for clearing the display of the LCD display module. The function sends a clear command to the LCD display module using the LCD_voidSendCommand() function.
 *          The LCD_voidSendCommand() function takes a single parameter, which is the clear command (LCD_CLEAR_COMMAND). This command is predefined in the code and corresponds to the value 0x01.
 *    		When the clear command is sent to the LCD display module, it clears the entire display and sets the cursor to the home position (the first row and the first column).
 *   		Overall, this function is useful for clearing the display of the LCD display module and preparing it for displaying new content.
 *
 * \param 	void
 * \return	void
 *
 */
void LCD_voidClear(void);

/** \brief	This function is responsible for moving the cursor of the LCD display module to a specific position on the screen. The function takes two parameters, which are the X and Y coordinates of the new cursor position (copy_u8XPos and copy_u8YPos, respectively), and returns nothing (void).
 *			The function first checks if the new cursor position is within the boundaries of the LCD display module. If the X position is either 0 or 1 and the Y position is between 0 and 15, then the function proceeds to calculate the LCD DDRAM (Display Data RAM) address corresponding to the new cursor position.
 *			If the X position is 0, then the new DDRAM address is simply the Y position. If the X position is 1, then the new DDRAM address is the Y position plus 0x40 (64 in decimal). This is because the LCD display module has a 2-row display, and the DDRAM addresses of the second row start at 0x40.
 *			The function then sends a command to the LCD display module to move the cursor to the new DDRAM address. This is done by adding 128 to the DDRAM address and sending it as a command using the LCD_voidSendCommand() function.
 * 			If the new cursor position is outside the boundaries of the LCD display module, the function returns an error state.
 *			Overall, this function is useful for positioning the cursor of the LCD display module to specific coordinates on the screen, which can be useful for displaying text or other information in a specific format.
 *
 * \param	copy_u8XPos: This parameter specifies the X coordinate of the new cursor position on the LCD display module. It is an 8-bit unsigned integer (u8) that can take the values 0 or 1. The value 0 corresponds to the first row of the LCD display module, while the value 1 corresponds to the second row. If any other value is passed, the function returns an error state.
 *			copy_u8YPos: This parameter specifies the Y coordinate of the new cursor position on the LCD display module. It is an 8-bit unsigned integer (u8) that can take values between 0 and 15. The value 0 corresponds to the first column of the LCD display module, while the value 15 corresponds to the last column. If any other value is passed, the function returns an error state.
 *			Overall, these parameters are used to calculate the new DDRAM address corresponding to the new cursor position and move the cursor to that address using a command sent to the LCD display module.
 * \return 	void
 *
 */
void LCD_voidGoToXYPos(u8 copy_u8XPos,u8 copy_u8YPos);



#endif // __HAL_LCD_INTERFACE_H__
