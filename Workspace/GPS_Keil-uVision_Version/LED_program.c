/************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_3		*************/
/********** Date    : 26/04/2023              	*************/
/********** SWC     : HAL_LED                   *************/
/********** Version : 1.0                    	*************/
/************************************************************/
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
/**< MCAL_GPIO */
#include "GPIO_interface.h"
/**< MCAL_STK */
#include "STK_interface.h"
/**< LED_HAL */
#include "LED_private.h"
#include "LED_interface.h"
#include "LED_config.h"

void LED_LedInit(void)
{
    GPIO_Init(GPIO_PORTF);
	GPIO_SetPinDirection(GPIO_PORTF, LED_BLUE_PIN, GPIO_OUTPUT);   /**< then initialize the LED direction */
	GPIO_SetPinDirection(GPIO_PORTF, LED_GREEN_PIN, GPIO_OUTPUT);  /**< then initialize the LED direction */  
	GPIO_SetPinDirection(GPIO_PORTF, LED_RED_PIN, GPIO_OUTPUT);    /**< then initialize the LED direction */
}

void LED_LedOn(u8 LEDColour)
{
    switch(LEDColour)
    {
        case LED_BLUE:
            GPIO_SetPinValue(GPIO_PORTF, LED_BLUE_PIN, GPIO_HIGH);
            break;
        case LED_GREEN:
            GPIO_SetPinValue(GPIO_PORTF, LED_GREEN_PIN, GPIO_HIGH);
            break;
        case LED_RED:
            GPIO_SetPinValue(GPIO_PORTF, LED_RED_PIN, GPIO_HIGH);
            break;
        default :/**< Error State */ break;
    }
}

void LED_vLedOff(u8 LedColour)
{
    switch(LedColour)
    {
        case LED_BLUE:
            GPIO_SetPinValue(GPIO_PORTF, LED_BLUE_PIN, GPIO_LOW);
            break;
        case LED_GREEN:
            GPIO_SetPinValue(GPIO_PORTF, LED_GREEN_PIN, GPIO_LOW);
            break;
        case LED_RED:
            GPIO_SetPinValue(GPIO_PORTF, LED_RED_PIN, GPIO_LOW);
            break;
        default :/**< Error State */ break;
    }
}

void LED_LedTog(u8 LedColour)
{
	switch(LedColour)
	{
        case LED_BLUE:
            GPIO_TogglePinValue(GPIO_PORTF, LED_BLUE_PIN);
            break;
        case LED_GREEN:
            GPIO_TogglePinValue(GPIO_PORTF, LED_GREEN_PIN);
            break;
        case LED_RED:
            GPIO_TogglePinValue(GPIO_PORTF, LED_RED_PIN);
            break;
        default : /**< Error State */ break;
	}
}

void LED_LedBlinkOnce(u8 LedColour)
{
    switch(LedColour)
    {
        case LED_BLUE:
            GPIO_SetPinValue(GPIO_PORTF, LED_BLUE_PIN, GPIO_HIGH);
            STK_SetDelay_ms(LED_TIME_ON);
            GPIO_SetPinValue(GPIO_PORTF, LED_BLUE_PIN, GPIO_LOW);
            break;
        case LED_GREEN:
            GPIO_SetPinValue(GPIO_PORTF, LED_GREEN_PIN, GPIO_HIGH);
            STK_SetDelay_ms(LED_TIME_ON);
            GPIO_SetPinValue(GPIO_PORTF, LED_GREEN_PIN, GPIO_LOW);
            break;
        case LED_RED:
            GPIO_SetPinValue(GPIO_PORTF, LED_RED_PIN, GPIO_HIGH);
            STK_SetDelay_ms(LED_TIME_ON);
            GPIO_SetPinValue(GPIO_PORTF, LED_RED_PIN, GPIO_LOW);
            break;
        default :/**< Error State */ break;
    }
}

void LED_LedBlinkTwice(u8 LedColour)
{
  LED_LedBlinkOnce(LedColour);
	STK_SetDelay_ms(LED_TIME_ON);
	LED_LedBlinkOnce(LedColour);
}

void LED_xLedOff(void)
{
	GPIO_SetPinValue(GPIO_PORTF, LED_BLUE_PIN, GPIO_LOW);
	GPIO_SetPinValue(GPIO_PORTF, LED_RED_PIN, GPIO_LOW);
	GPIO_SetPinValue(GPIO_PORTF, LED_GREEN_PIN, GPIO_LOW);
}
