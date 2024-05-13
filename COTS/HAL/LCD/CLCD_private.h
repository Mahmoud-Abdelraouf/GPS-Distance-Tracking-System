/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 5 Feb 2023                 *****************/
/******* Version   : 1.0.0                      *****************/
/******* File Name : CLCD_private.h             *****************/
/****************************************************************/
#ifndef CLCD_PRIVATE_H
#define CLCD_PRIVATE_H

/*****************************< Commands for initializing LCD. *****************************/
#define _LCD_CLEAR                      0X01  // Clears the display.
#define _LCD_RETURN_HOME                0x02  // Returns cursor to home position.
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04  // Sets entry mode to decrement cursor position without display shift.
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05  // Sets entry mode to decrement cursor position with display shift.
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06  // Sets entry mode to increment cursor position without display shift.

#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07  // Sets entry mode to increment cursor position with display shift.
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10  // Moves cursor/display left without changing DDRAM address.
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14  // Moves cursor/display right without changing DDRAM address.
#define _LCD_DISPLAY_SHIFT_LEFT         0x18  // Shifts the display to the left.
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C  // Shifts the display to the right.
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C  // Display on, cursor off, and underline off.
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D  // Display on, cursor on, and underline off.
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E  // Display on, cursor off, and underline on.
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F  // Display on, cursor on, and underline on.
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08  // Display off and cursor off.
#define _LCD_8BIT_MODE_2_LINE           0x38  // Sets 8-bit data mode with 2 display lines.
#define _LCD_4BIT_MODE_2_LINE           0x28  // Sets 4-bit data mode with 2 display lines.

#define _LCD_CGRAM_START                0x40  // Start address for Character Generator RAM (CGRAM) in the LCD.
#define _LCD_DDRAM_START                0x80  // Start address for Display Data RAM (DDRAM) in the LCD.

/*****************************< Private function prototypes *****************************/ 
/**
 * @brief Sends 4-bit data to the LCD.
 *
 * This function sends a 4-bit command or data to the LCD module using the 4-bit mode
 * based on the provided configuration and value. It sequentially sets the 4 data pins
 * (4 most significant bits first) to transmit the specified value to the LCD.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] value The 4-bit value to be sent to the LCD.
 * @note This function assumes that the required GPIO and timing functions have been initialized separately.
 */
static void HAL_LCD_Send4Bits(const LCD_Config_t *config, uint8_t value);

/**
 * @brief Sends 8-bit data to the LCD.
 *
 * This function sends an 8-bit command or data to the LCD module based on the provided
 * configuration and value. It sequentially sets the 8 data pins to transmit the specified
 * value to the LCD.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] value The 8-bit value to be sent to the LCD.
 * @note This function assumes that the required GPIO and timing functions have been initialized separately.
 */
static void HAL_LCD_Send8Bits(const LCD_Config_t *config, uint8_t value);


#endif /**< CLCD_PRIVATE_H */
