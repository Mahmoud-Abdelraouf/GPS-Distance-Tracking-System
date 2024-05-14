/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 5 Feb 2023                 *****************/
/******* Version   : 1.0.0                      *****************/
/******* File Name : CLCD_program.c             *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "GPIO_interface.h"
#include "STK_interface.h"
/*****************************< HAL *****************************/
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

/*****************************< Function Implementations *****************************/
void LCD_Init(const LCD_Config_t *config) 
{
    if(config == NULL)
    {
        return;
    }

    /**< Init the Mode of the en, rs, rw */
    GPIO_SetPinDirection(config->enablePin.LCD_PortId, config->enablePin.LCD_PinId, GPIO_OUTPUT);
    GPIO_SetPinDirection(config->rsPin.LCD_PortId, config->rsPin.LCD_PinId, GPIO_OUTPUT);
    GPIO_SetPinDirection(config->rwPin.LCD_PortId, config->rwPin.LCD_PinId, GPIO_OUTPUT);

    if(config->mode == LCD_4BitMode)
    {
        /**< Init the Mode of Data Pins */
        for(uint8_t i = 0; i < 4; i++)
        {
            GPIO_SetPinDirection(config->dataPins[i].LCD_PortId, config->dataPins[i].LCD_PinId, GPIO_OUTPUT);
        }
    }
    else if(LCD_8BitMode)
    {
        for(uint8_t i = 0; i < 8; i++)
        {
            GPIO_SetPinDirection(config->dataPins[i].LCD_PortId, config->dataPins[i].LCD_PinId, GPIO_OUTPUT);
        }
    }
    else
    {
        return;
    }
    
    STK_SetDelay_ms(20);
    LCD_SendCommand(config, _LCD_8BIT_MODE_2_LINE);
    STK_SetDelay_ms(5);
    LCD_SendCommand(config, _LCD_8BIT_MODE_2_LINE);
    STK_SetDelay_us(150);
    LCD_SendCommand(config, _LCD_8BIT_MODE_2_LINE);

    LCD_SendCommand(config, _LCD_CLEAR);
    LCD_SendCommand(config, _LCD_RETURN_HOME);
    LCD_SendCommand(config, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
    LCD_SendCommand(config, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
    if(config->mode == LCD_4BitMode)
    {
        LCD_SendCommand(config, _LCD_4BIT_MODE_2_LINE);
    }
    LCD_SendCommand(config, 0x80);
}

void LCD_SendCommand(const LCD_Config_t *config, uint8_t command) 
{
    /**< Set RS pin to low for command --> RS = 0 */
    GPIO_SetPinValue(config->rsPin.LCD_PortId, config->rsPin.LCD_PinId, GPIO_LOW);
    /**< Set RW pin to low for write  --> RW = 0 */
    GPIO_SetPinValue(config->rwPin.LCD_PortId, config->rwPin.LCD_PinId, GPIO_LOW);

    if(config->mode == LCD_4BitMode)
    {
        HAL_LCD_Send4Bits(config, command);
    }
    else if(config->mode == LCD_8BitMode)
    {
        HAL_LCD_Send8Bits(config, command);
    }
    else
    {
        return;
    }
}

void LCD_SendChar(const LCD_Config_t *config, uint8_t character) 
{
    /**< Set RS pin to low for command --> RS = 0 */
    GPIO_SetPinValue(config->rsPin.LCD_PortId, config->rsPin.LCD_PinId, GPIO_HIGH);
    /**< Set RW pin to low for write  --> RW = 0 */
    GPIO_SetPinValue(config->rwPin.LCD_PortId, config->rwPin.LCD_PinId, GPIO_LOW);

    if(config->mode == LCD_4BitMode)
    {
        HAL_LCD_Send4Bits(config, character);
    }
    else if(config->mode == LCD_8BitMode)
    {
        HAL_LCD_Send8Bits(config, character);
    }
    else
    {
        return;
    }
}

void LCD_SendString(const LCD_Config_t *config, const uint8_t *string) 
{
    uint8_t Local_Counter = 0;
    
    while(string[Local_Counter] != '\0')
    {
        LCD_SendChar(config, string[Local_Counter]);
        Local_Counter++;
    }
}

void LCD_SendIntegerNumber(const LCD_Config_t *config, s32 number) {
    u8 Local_Integer[11] = {0};
    s8 Local_Counter = 0;

    /**< Handle negative numbers */ 
    if (number < 0) {
        LCD_SendChar(config, '-');
        number *= -1;
    }

    /**< Extract digits of the integer part */ 
    do {
        Local_Integer[Local_Counter] = number % 10;
        number /= 10;
        Local_Counter++;
    } while (number != 0);

    Local_Counter--;

    /**< Display each digit */ 
    for (; Local_Counter >= 0; Local_Counter--) {
        LCD_SendChar(config, Local_Integer[Local_Counter] + '0');
    }
}

void LCD_SendNumber(const LCD_Config_t *config, double number) {
    /**< Display integer part */ 
    u32 integerPart = (u32)number;

    LCD_SendIntegerNumber(config, (s32)integerPart); // Function to handle integer part

    /**< Display decimal point */ 
    LCD_SendChar(config, '.');

    /**< Display fractional part with 3 decimal points */ 
    double fractionalPart = number - integerPart;
    u8 decimalPlaces = 3;

    for (u8 i = 0; i < decimalPlaces; ++i) {
        fractionalPart *= 10;
        u8 digit = (u8)fractionalPart;
        LCD_SendChar(config, digit + '0');
        fractionalPart -= digit;
    }
}

Std_ReturnType LCD_DefineCustomChar(const LCD_Config_t *lcdConfig, const CustomChar_t *customChar) {
	/**<  Check if lcdConfig is NULL */
	if (lcdConfig == NULL) {
		return E_NOT_OK; /**< Return E_NOT_OK to indicate failure */
	}

    /**< Check if customChar is NULL */
    if (customChar == NULL) {
        return E_NOT_OK; /**< Return E_NOT_OK to indicate failure */
    }

    /**< Check if charIndex is within the range (0-7) */
    if (customChar->charIndex > 7) {
        return E_NOT_OK; /**< Return E_NOT_OK to indicate failure */
    }

    /**< Check if pattern is NULL */
    if (customChar->pattern == NULL) {
        return E_NOT_OK; /**< Return E_NOT_OK to indicate failure */
    }

    /**< Calculate the CGRAM address for the custom character */
    uint8_t address = _LCD_CGRAM_START + customChar->charIndex * 8;

    /**< Send the command to set CGRAM address */
    LCD_SendCommand(lcdConfig, address);

    /**< Write the pattern data for the custom character to CGRAM */
    for (int i = 0; i < 8; ++i) {
        LCD_SendChar(lcdConfig, customChar->pattern[i]);
    }

    return E_OK; /**< Return E_OK to indicate success */
}

Std_ReturnType LCD_DisplayCustomChar(const LCD_Config_t *lcdConfig, uint8_t charIndex, uint8_t row, uint8_t column) {
    /**< Check if lcdConfig is NULL */
    if (lcdConfig == NULL) {
        return E_NOT_OK; /**< Return E_NOT_OK to indicate failure */
    }

    /**< Check if charIndex is within the range (0-7) */
    if (charIndex > 7) {
        return E_NOT_OK; /**< Return E_NOT_OK to indicate failure */
    }

    /**< Check if row is within the valid range (0 or 1) */
    if (row > 1) {
        return E_NOT_OK; /**< Return E_NOT_OK to indicate failure */
    }

    /**< Check if column is within the valid range (0 to 15) */
    if (column > 15) {
        return E_NOT_OK; /**< Return E_NOT_OK to indicate failure */
    }

    /**< Calculate the DDRAM address based on row and column */
    uint8_t ddramAddress = (row == 0) ? (0x80 + column) : (0xC0 + column);

    /**< Set the DDRAM address */
    LCD_SendCommand(lcdConfig, ddramAddress);

    /**< Send the character index to display the custom character */
    LCD_SendChar(lcdConfig, charIndex);

    return E_OK; /**< Return E_OK to indicate success */
}

void LCD_Clear(const LCD_Config_t *config) 
{
    LCD_SendCommand(config, _LCD_CLEAR);
}

void LCD_GoToXYPos(const LCD_Config_t *config, uint8_t row, uint8_t column) {
    /**< Check if the coordinates are within bounds */ 
    if ((row < 2) && (column >= 0 && column <= 15)) {
        u8 localAddress = 0;

        switch (row) {
            case 0:
                localAddress = column;
                break;
            case 1:
                localAddress = column + _LCD_CGRAM_START;
                break;
            default:
                break;
        }

        // Calculate the final address to move the cursor
        u8 command = localAddress | (1 << 7); // Or simply: localAddress + 0x80;
        LCD_SendCommand(config, command);
    }
    else
    {
        return;
    }
}

/*****************************< Private helper function to send 4 bits *****************************/ 
static void HAL_LCD_Send4Bits(const LCD_Config_t *config, uint8_t value) 
{
    /**< Send the 4-MSB */
    for(uint8_t i = 0; i < 4; i++)
    {
        GPIO_SetPinValue(config->dataPins[i].LCD_PortId, config->dataPins[i].LCD_PinId, value >> (4 + i) & 0x01);
    }

    /**< Set the enable pin to high */
    GPIO_SetPinValue(config->enablePin.LCD_PortId, config->enablePin.LCD_PinId, GPIO_HIGH);
    /**< Set the Pulse time to be 5msec */
    STK_SetDelay_ms(5);
    /**< Set the enable pin to low */
    GPIO_SetPinValue(config->enablePin.LCD_PortId, config->enablePin.LCD_PinId, GPIO_LOW);

    /**< Shift the 4-LSB command to the 4-MSB */
    value <<= 4;

    /**< Send the 4-LSB */
    for(uint8_t i = 0; i < 4; i++)
    {
    	GPIO_SetPinValue(config->dataPins[i].LCD_PortId, config->dataPins[i].LCD_PinId, value >> (4 + i) & 0x01);
    }

    /**< Set the enable pin to high */
    GPIO_SetPinValue(config->enablePin.LCD_PortId, config->enablePin.LCD_PinId, GPIO_HIGH);
    /**< Set the Pulse time to be 5msec */
    STK_SetDelay_ms(5);
    /**< Set the enable pin to low */
    GPIO_SetPinValue(config->enablePin.LCD_PortId, config->enablePin.LCD_PinId, GPIO_LOW);
}

/*****************************< Private helper function to send 8 bits *****************************/ 
static void HAL_LCD_Send8Bits(const LCD_Config_t *config, uint8_t value) 
{
     /**< Send the 8-Bit */
    for(uint8_t i = 0; i < 8; i++)
    {
        GPIO_SetPinValue(config->dataPins[i].LCD_PortId, config->dataPins[i].LCD_PinId, value >> i & 0x01);
    }

    /**< Set the enable pin to high */
    GPIO_SetPinValue(config->enablePin.LCD_PortId, config->enablePin.LCD_PinId, GPIO_HIGH);
    /**< Set the Pulse time to be 5msec */
    STK_SetDelay_ms(5);
    /**< Set the enable pin to low */
    GPIO_SetPinValue(config->enablePin.LCD_PortId, config->enablePin.LCD_PinId, GPIO_LOW);
}
