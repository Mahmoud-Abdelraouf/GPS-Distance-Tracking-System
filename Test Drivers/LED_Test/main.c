/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "DIO_interface.h"
#include "STK_interface.h"
/**< HAL */
#include "LED_interface.h"
/**
 * main.c
 */
int main(void)
{
    LED_voidLedInit(LED_GREEN);
    LED_voidLedInit(LED_RED);
    LED_voidLedInit(LED_BLUE);
    LED_voidLedOn(LED_GREEN);
    STK_voidDelay(1000);
    LED_voidLedTog(LED_GREEN);
    STK_voidDelay(1000);
    LED_voidLedBlinkOnce(LED_GREEN);
    LED_voidLedOn(LED_BLUE);
    STK_voidDelay(1000);
    LED_voidLedOff(LED_BLUE);
    while(1);
	return 0;
}
