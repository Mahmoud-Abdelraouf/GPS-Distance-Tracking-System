//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 26/04/2023              	*************
//********** SWC     : HAL_LED                  *************
//********** Version : 1.0                    	*************
//***********************************************************
/**< LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/tm4c123gh6pm.h"
/**< MCAL_DIO */
#include "../../MCAL/DIO/DIO_interface.h"
/**< MCAL_STK */
#include "../../MCAL/STK/STK_interface.h"
/**< LED_HAL */
#include "../../HAL/LED/LED_private.h"
#include "../../HAL/LED/LED_interface.h"
#include "../../HAL/LED/LED_config.h"


void LED_voidLedInit(void)
{
    DIO_voidInit(DIO_u8_PORTF);
	DIO_u8SetPinDirection(DIO_u8_PORTF, LED_BLUE_PIN ,DIO_u8_OUTPUT);   /**< then initialize the LED direction */
	DIO_u8SetPinDirection(DIO_u8_PORTF, LED_GREEN_PIN ,DIO_u8_OUTPUT);  /**< then initialize the LED direction */  
	DIO_u8SetPinDirection(DIO_u8_PORTF, LED_RED_PIN ,DIO_u8_OUTPUT);    /**< then initialize the LED direction */
}

void LED_voidLedOn(u8 copy_u8LedColour)
{
    switch(copy_u8LedColour)
    {
    case LED_BLUE:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_BLUE_PIN ,DIO_u8_HIGH);
        break;
    case LED_GREEN:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_GREEN_PIN ,DIO_u8_HIGH);
        break;
    case LED_RED:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_RED_PIN ,DIO_u8_HIGH);
        break;
    default :/**< Error State */ break;
    }
}

void LED_voidLedOff(u8 copy_u8LedColour)
{
    switch(copy_u8LedColour)
    {
    case LED_BLUE:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_BLUE_PIN ,DIO_u8_LOW);
        break;
    case LED_GREEN:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_GREEN_PIN ,DIO_u8_LOW);
        break;
    case LED_RED:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_RED_PIN ,DIO_u8_LOW);
        break;
    default :/**< Error State */ break;
    }
}

void LED_voidLedTog(u8 copy_u8LedColour)
{
	switch(copy_u8LedColour)
	{
	case LED_BLUE:
	    DIO_u8TogglePinValue(DIO_u8_PORTF, LED_BLUE_PIN);
	    break;
	case LED_GREEN:
	    DIO_u8TogglePinValue(DIO_u8_PORTF, LED_GREEN_PIN);
	    break;
	case LED_RED:
	    DIO_u8TogglePinValue(DIO_u8_PORTF, LED_RED_PIN);
	    break;
	default : /**< Error State */ break;
	}
}

void LED_voidLedBlinkOnce(u8 copy_u8LedColour)
{
    switch(copy_u8LedColour)
    {
    case LED_BLUE:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_BLUE_PIN, DIO_u8_HIGH);
        STK_voidDelay(LED_TIME_ON);
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_BLUE_PIN, DIO_u8_LOW);
        break;
    case LED_GREEN:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_GREEN_PIN, DIO_u8_HIGH);
        STK_voidDelay(LED_TIME_ON);
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_GREEN_PIN, DIO_u8_LOW);
        break;
    case LED_RED:
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_RED_PIN, DIO_u8_HIGH);
        STK_voidDelay(LED_TIME_ON);
        DIO_u8SetPinValue(DIO_u8_PORTF, LED_RED_PIN, DIO_u8_LOW);
        break;
    default :/**< Error State */ break;
    }
}

void LED_voidLedBlinkTwice(u8 copy_u8LedColour)
{
    LED_voidLedBlinkOnce(copy_u8LedColour);
	STK_voidDelay(LED_TIME_ON);
	LED_voidLedBlinkOnce(copy_u8LedColour);
}

void LED_voidLedOffAll(void)
{
	DIO_u8SetPinValue(DIO_u8_PORTF, LED_BLUE_PIN, DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTF, LED_RED_PIN, DIO_u8_LOW);
	DIO_u8SetPinValue(DIO_u8_PORTF, LED_GREEN_PIN, DIO_u8_LOW);
}
