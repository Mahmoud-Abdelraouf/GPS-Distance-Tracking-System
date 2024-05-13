/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 5 Feb 2023                 *****************/
/******* Version   : 1.0.0                      *****************/
/******* File Name : CLCD_interface.h           *****************/
/****************************************************************/
#ifndef CLCD_INTERFACE_H__
#define CLCD_INTERFACE_H__

/**
 * @brief macros defining LCD rows.
 */
#define LCD_ROW_1 0       /**< Row 1 */
#define LCD_ROW_2 1       /**< Row 2 */

/**
 * @brief macros defining LCD columns.
 */
#define LCD_COLUMN_1  0   /**< Column 1 */
#define LCD_COLUMN_2  1   /**< Column 2 */
#define LCD_COLUMN_3  2   /**< Column 3 */
#define LCD_COLUMN_4  3   /**< Column 4 */
#define LCD_COLUMN_5  4   /**< Column 5 */
#define LCD_COLUMN_6  5   /**< Column 6 */
#define LCD_COLUMN_7  6   /**< Column 7 */
#define LCD_COLUMN_8  7   /**< Column 8 */
#define LCD_COLUMN_9  8   /**< Column 9 */
#define LCD_COLUMN_10 9   /**< Column 10 */
#define LCD_COLUMN_11 10  /**< Column 11 */
#define LCD_COLUMN_12 11  /**< Column 12 */
#define LCD_COLUMN_13 12  /**< Column 13 */
#define LCD_COLUMN_14 13  /**< Column 14 */
#define LCD_COLUMN_15 14  /**< Column 15 */
#define LCD_COLUMN_16 15  /**< Column 16 */

/**
 * @brief Structure representing a custom character for LCD.
 */
typedef struct {
    uint8_t pattern[8]; /**< Pattern data for the custom character */
    uint8_t charIndex;  /**< Index of the custom character (0-7) */
} CustomChar_t;

/**
 * @brief Enum defining LCD operation modes.
 */
typedef enum {
    LCD_4BitMode = 4, /**< 4-bit mode */
    LCD_8BitMode = 8  /**< 8-bit mode */
} LCD_Mode_t;

/**
 * @brief Structure representing LCD pin configuration.
 */
typedef struct {
    uint8_t LCD_PortId: 2;  /**< Port ID for the LCD pin */
    uint8_t LCD_PinId: 4;   /**< Pin ID for the LCD pin */
    uint8_t :2;             /**< Padding */
} LCD_PinConfig_t;

/**
 * @brief Structure representing LCD configuration.
 */
typedef struct {
    uint8_t mode;                /**< 8-bit or 4-bit mode indicator */
    LCD_PinConfig_t dataPins[8]; /**< Maximum pins for 8-bit mode */
    LCD_PinConfig_t rsPin;       /**< RS pin */
    LCD_PinConfig_t rwPin;       /**< R/W pin */
    LCD_PinConfig_t enablePin;   /**< Enable pin */
} LCD_Config_t;

/**
 * @brief Initializes the LCD module with the specified configuration.
 *
 * This function initializes the LCD module based on the provided configuration.
 * It sets the direction of the control pins (enable, rs, rw) and data pins
 * according to the specified mode (4-bit or 8-bit). Additionally, it sends
 * initialization commands to configure the LCD module, such as clearing the
 * display, setting the entry mode, and turning on the display.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @note This function assumes that the required DIO functions have been initialized separately.
 */
void LCD_Init(const LCD_Config_t *config);

/**
 * @brief Sends a command to the LCD module.
 *
 * This function sends a command to the LCD module based on the provided configuration.
 * It sets the RS pin to low for command mode and the RW pin to low for write operation.
 * Depending on the configured mode (4-bit or 8-bit), it calls the corresponding function
 * to send the command.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] command The command to be sent to the LCD.
 * @note This function assumes that the required GPIO module has been initialized separately.
 * @warning If the mode in the configuration is neither 4-bit nor 8-bit, the function returns without action.
 */
void LCD_SendCommand(const LCD_Config_t *config, uint8_t command);

/**
 * @brief Sends a character to the LCD module for display.
 *
 * This function sends a character to the LCD module based on the provided configuration.
 * It sets the RS pin to high for data mode and the RW pin to low for write operation.
 * Depending on the configured mode (4-bit or 8-bit), it calls the corresponding function
 * to send the character.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] character The character to be sent to the LCD for display.
 * @note This function assumes that the required GPIO module has been initialized separately.
 * @warning If the mode in the configuration is neither 4-bit nor 8-bit, the function returns without action.
 */
void LCD_SendChar(const LCD_Config_t *config, uint8_t character);

/**
 * @brief Sends a null-terminated string to the LCD for display.
 *
 * This function sends a null-terminated string to the LCD module for display
 * based on the provided configuration. It iterates through the characters of
 * the string and sends each character to the LCD using the LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] string Pointer to the null-terminated string to be displayed on the LCD.
 * @note This function assumes that the required GPIO module and LCD character functions have been initialized separately.
 */
void LCD_SendString(const LCD_Config_t *config, const uint8_t *string);

/**
 * @brief Displays a double-precision floating-point number on the LCD.
 *
 * This function displays a double-precision floating-point number on the LCD based on
 * the provided configuration. It separates the integer and fractional parts of the number,
 * displays the integer part directly, and then displays the fractional part with three decimal
 * places using LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] number The double-precision floating-point number to be displayed on the LCD.
 * @note This function assumes that the required LCD character functions have been initialized separately.
 */
void LCD_SendNumber(const LCD_Config_t *config, double number);

/**
 * @brief Displays the integer part of a signed integer on the LCD.
 *
 * This function displays the integer part of a signed integer value on the LCD based on
 * the provided configuration. It separates the digits of the integer part and displays
 * them sequentially using the LCD_SendChar function.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] number The signed integer value whose integer part is to be displayed on the LCD.
 * @note This function assumes that the required LCD character functions have been initialized separately.
 */
void LCD_SendIntegerNumber(const LCD_Config_t *config, s32 number);

/**
 * @brief Defines a custom character on the LCD.
 *
 * This function defines a custom character on the LCD by storing its pattern data
 * in the CGRAM at the specified index.
 *
 * @param[in] lcdConfig Pointer to the LCD configuration structure.
 * @param[in] customChar Custom character to be defined.
 * @return E_OK if the custom character was successfully defined, E_NOT_OK otherwise.
 *
 * @example LCD_define_custom_char_example.c
 *
 * This example demonstrates how to define a custom character on the LCD using the
 * LCD_DefineCustomChar function.
 *
 * @code
 * /// Define a custom character pattern (5x8 dots)
 * const uint8_t myCustomCharPattern[8] = {
 *     0bxxx00000,
 *     0bxxx00100,
 *     0bxxx00110,
 *     0bxxx01110,
 *     0bxxx11110,
 *     0bxxx01110,
 *     0bxxx00110,
 *     0bxxx00000
 * };
 *
 * /// Create a CustomChar_t object
 * CustomChar_t myCustomChar = {
 *     .pattern = myCustomCharPattern, /// Set the pattern data
 *     .charIndex = 0                  /// Set the index where the character will be stored in CGRAM
 * };
 *
 * /// Define the custom character on the LCD
 * Std_ReturnType result = LCD_DefineCustomChar(&lcdConfig, &myCustomChar);
 *
 * /// Check the result
 * if (result == E_OK) {
 *     /// Custom character successfully defined
 *     /// Now you can display this character at any position using LCD_DisplayCustomChar function
 * } else {
 *     /// Failed to define custom character
 *     /// Handle the error accordingly
 * }
 * @endcode
 */
Std_ReturnType LCD_DefineCustomChar(const LCD_Config_t *lcdConfig, const CustomChar_t *customChar);

/**
 * @brief Displays a custom character on the LCD at a specified position.
 *
 * This function displays a custom character previously defined at the specified index
 * on the LCD at the specified row and column.
 *
 * @param[in] lcdConfig Pointer to the LCD configuration structure.
 * @param[in] charIndex Index of the custom character to be displayed (0-7).
 * @param[in] row The row (0 or 1) where the custom character should be displayed.
 * @param[in] column The column (0 to 15) where the custom character should be displayed.
 * @return E_OK if the custom character was successfully displayed, E_NOT_OK otherwise.
 */
Std_ReturnType LCD_DisplayCustomChar(const LCD_Config_t *lcdConfig, uint8_t charIndex, uint8_t row, uint8_t column);

/**
 * @brief Clears the display of the LCD.
 *
 * This function sends a command to the LCD module based on the provided configuration
 * to clear the display content and reset the cursor to the home position (the first row
 * and the first column).
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @note This function assumes that the required LCD command functions have been initialized separately.
 */
void LCD_Clear(const LCD_Config_t *config);

/**
 * @brief Moves the cursor of the LCD to a specific position.
 *
 * This function moves the cursor of the LCD module based on the provided coordinates
 * (row and column) within the screen bounds specified by the LCD configuration.
 *
 * @param[in] config Pointer to the LCD configuration structure.
 * @param[in] row The row (LCD_ROW_1 or LCD_ROW_2) on the LCD.
 * @param[in] column The column (LCD_COLUMN_1 to LCD_COLUMN_16) on the LCD.
 * @note This function assumes that the required LCD command functions have been initialized separately.
 */
void LCD_GoToXYPos(const LCD_Config_t *config, uint8_t row, uint8_t column);

#endif /**< CLCD_INTERFACE_H__ */

