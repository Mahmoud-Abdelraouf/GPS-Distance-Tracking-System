

/**
 * main.c
 */
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "DIO_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"
/**< HAL */
#include "LED_interface.h"
int main(void)
{
    u8 Local_u8Test = 0;
    UART_voidInit(UART7, 9600, UART_DATA_8, UART_PARITY_NONE, UART_STOP_BIT_1);
    LED_voidLedInit(LED_BLUE);
    LED_voidLedInit(LED_GREEN);
    LED_voidLedInit(LED_RED);
    while(1)
    {
        UART_voidReceiveByte(UART7, &Local_u8Test);
        if(Local_u8Test=='r')
        {
            LED_voidLedOn(LED_RED);
        }
        else if (Local_u8Test == 'b')
        {
            LED_voidLedOn(LED_BLUE);
        }
        else if (Local_u8Test == 'g')
        {
            LED_voidLedOn(LED_GREEN);
        }
        else
        {
            LED_voidLedOff(LED_RED);
            LED_voidLedOff(LED_BLUE);
            LED_voidLedOff(LED_GREEN);
        }
    }

	return 0;
}
