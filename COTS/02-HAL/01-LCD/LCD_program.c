/************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_3		*************/
/********** Date    : 25/04/2023              	*************/
/********** SWC     : HAL_LCD                   *************/
/********** Version : 1.0                    	*************/
/************************************************************/
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TM4C123GH6PM.h"
/**< MCAL */
#include "DIO_interface.h"
#include "STK_interface.h"
/**< HAL */
#include "LCD_private.h"
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
#if LCD_MODE == LCD_8_BIT_MODE
#if LCD_DATA_PORT == LCD_CONTROL_PORT
    DIO_voidInit(LCD_DATA_PORT);
#elif LCD_DATA_PORT != LCD_CONTROL_PORT
    DIO_voidInit(LCD_DATA_PORT);
    DIO_voidInit(LCD_CONTROL_PORT);
#else
    #error "Wrong Choice"
#endif
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D0_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D1_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D2_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D3_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D4_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D5_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D6_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D7_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_RS_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_EN_PIN, DIO_u8_OUTPUT);
    STK_voidDelay(1000);
    LCD_voidSendCommand(LCD_8_BIT_MODE_COMMAND);
    LCD_voidSendCommand(LCD_CLEAR_COMMAND);
    LCD_voidSendCommand(LCD_DISPLAY_ON_COMMAND);
#elif LCD_MODE == LCD_4_BIT_MODE
#if LCD_DATA_PORT == LCD_CONTROL_PORT
    DIO_voidInit(LCD_DATA_PORT);
#elif LCD_MODE != LCD_CONTROL_PORT
    DIO_voidInit(LCD_DATA_PORT);
    DIO_voidInit(LCD_CONTROL_PORT);
#else
    #error "Wrong Choice"
#endif
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D4_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D5_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D6_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_D7_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_RS_PIN, DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LCD_DATA_PORT, LCD_EN_PIN, DIO_u8_OUTPUT);
    STK_voidDelay(1000);
    LCD_voidSendCommand(LCD_4_BIT_MODE_COMMAND_1);
    LCD_voidSendCommand(LCD_4_BIT_MODE_COMMAND_2);
    LCD_voidSendCommand(LCD_4_BIT_MODE_COMMAND_3);
    LCD_voidSendCommand(LCD_CLEAR_COMMAND);
    LCD_voidSendCommand(LCD_DISPLAY_ON_COMMAND);
#else
    #error "Wrong Choice"
#endif // LCD_MODE


}

void LCD_voidSendCommand(u8 copy_u8Command)
{
    /**< Set RS pin to low for command --> RS = 0 */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8_LOW);
    /**< Set RW pin to low for write  --> RW = 0 */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8_LOW);
#if LCD_MODE == LCD_8_BIT_MODE
    /**< Set the command to data pins */
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D0_PIN, copy_u8Command >> 0 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D1_PIN, copy_u8Command >> 1 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D2_PIN, copy_u8Command >> 2 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D3_PIN, copy_u8Command >> 3 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, copy_u8Command >> 4 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, copy_u8Command >> 5 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, copy_u8Command >> 6 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, copy_u8Command >> 7 & 0x01);
    /**< Set the enable pin to high */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN,DIO_u8_HIGH);
    /**< The time of pulse delay */
    STK_voidDelay(5);
    /**< Set the enable pin to low */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN,DIO_u8_LOW);
#elif LCD_MODE == LCD_4_BIT_MODE
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, copy_u8Command >> 4 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, copy_u8Command >> 5 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, copy_u8Command >> 6 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, copy_u8Command >> 7 & 0x01);
    /**< Set the enable pin to high */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN,DIO_u8_HIGH);
    /**< The time of pulse delay */
    STK_voidDelay(5);
    /**< Set the enable pin to low */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN,DIO_u8_LOW);
    /**< Shift the 4-LSB command to the 4-MSB */
    copy_u8Command = copy_u8Command << 4;
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, copy_u8Command >> 4 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, copy_u8Command >> 5 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, copy_u8Command >> 6 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, copy_u8Command >> 7 & 0x01);
    /**< Set the enable pin to high */
   DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_u8_HIGH);
   /**< The time of pulse delay */
   STK_voidDelay(5);
   /**< Set the enable pin to low */
   DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_u8_LOW);
#else
    #error "Wrong Choice"
#endif // LCD_MODE
}

void LCD_voidSendChar(u8 copy_u8Char)
{
    /**< Set RS pin to high for data --> RS = 1 */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8_HIGH);
    /**< Set RW pin to low for write  --> RW = 0 */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8_LOW);
#if LCD_MODE == LCD_8_BIT_MODE
    /**< Set the data to data pins */
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D0_PIN, copy_u8Char >> 0 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D1_PIN, copy_u8Char >> 1 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D2_PIN, copy_u8Char >> 2 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D3_PIN, copy_u8Char >> 3 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, copy_u8Char >> 4 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, copy_u8Char >> 5 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, copy_u8Char >> 6 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, copy_u8Char >> 7 & 0x01);
    /**< Set the enable pin to high */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_u8_HIGH);
    /**< The time of pulse delay */
    STK_voidDelay(5);
    /**< Set the enable pin to low */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_u8_LOW);
#elif LCD_MODE == LCD_4_BIT_MODE
    /**< Set the 4-MSB to data pins */
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, copy_u8Char >> 4 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, copy_u8Char >> 5 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, copy_u8Char >> 6 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, copy_u8Char >> 7 & 0x01);
    /**< Set the enable pin to high */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_u8_HIGH);
    /**< The time of pulse delay */
    STK_voidDelay(5);
    /**< Set the enable pin to low */
    DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_u8_LOW);
    /**< Shift the 4-LSB data to the 4-MSB */
    copy_u8Char = copy_u8Char << 4;
    /**< Set the 4-LSB to data pins */
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D4_PIN, copy_u8Char >> 4 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D5_PIN, copy_u8Char >> 5 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D6_PIN, copy_u8Char >> 6 & 0x01);
    DIO_u8SetPinValue(LCD_DATA_PORT, LCD_D7_PIN, copy_u8Char >> 7 & 0x01);
    /**< Set the enable pin to high */
   DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_u8_HIGH);
   /**< The time of pulse delay */
   STK_voidDelay(5);
   /**< Set the enable pin to low */
   DIO_u8SetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_u8_LOW);
#else
    #error "Wrong Choice"
#endif // LCD_MODE
}

void LCD_voidClear(void)
{
    LCD_voidSendCommand(LCD_CLEAR_COMMAND);
}

void LCD_voidSendString(u8 *copy_pu8String)
{
    u8 Local_u8Counter = 0;
    while(copy_pu8String[Local_u8Counter]!='\0')
    {
        LCD_voidSendChar(copy_pu8String[Local_u8Counter]);
        Local_u8Counter++;
    }

}

void LCD_voidSendNumber(f64 copy_f64Number)
{

    u8 Local_u8Integer[11]={0};
    s8 Local_u8Counter = 0;
    if(((s32)copy_f64Number)<0)
    {
        LCD_voidSendChar('-');
        copy_f64Number*=-1;
    }
    do
    {
        Local_u8Integer[Local_u8Counter] = (u32)copy_f64Number%10;
        copy_f64Number/=10;
        Local_u8Counter++;
    }while((u32)copy_f64Number !=0);
    Local_u8Counter--;
    for(;Local_u8Counter>=0;Local_u8Counter--)
    {
        LCD_voidSendChar(Local_u8Integer[Local_u8Counter]+48);
    }
}

void LCD_voidGoToXYPos(u8 copy_u8XPos,u8 copy_u8YPos)
{
    u8 Local_u8Address = 0;
    if((copy_u8XPos== 0 || copy_u8XPos== 1) && (copy_u8YPos >= 0 && copy_u8YPos<=15))
    {
        switch(copy_u8XPos)
        {
        case 0:
            Local_u8Address = copy_u8YPos;
            break;
        case 1:
            Local_u8Address = copy_u8YPos+0x40;
            break;
        default: /**< Return Error state */break;
        }
        /**
         *  To move the LCD to the calculated address you should SET_BIT(DDRAM,DB7)
         *  There are many way to do this :
         *      1)Local_u8Address + 128
         *      2)Local_u8Address|(1<<8)
         *      3)SET_BIT(Local_u8Address,8)
         *  */
        LCD_voidSendCommand(Local_u8Address+128);
    }
    else
    {
        /**< Return Error state */
    }

}
