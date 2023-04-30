//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 26/04/2023              	*************
//********** SWC     : HAL_LED                  *************
//********** Version : 1.0                    	*************
//***********************************************************
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TM4C123GH6PM.h"
/**< MCAL_DIO */
#include "DIO_interface.h"
/**< MCAL_STK */
#include "STK_interface.h"
/**< LED_HAL */
#include "LED_private.h"
#include "LED_interface.h"
#include "LED_config.h"


void LED_voidLedInit(u8 copy_u8LedColour)
{
    DIO_voidInit(DIO_u8_PORTF);  											//first initialize PORTF itself
	DIO_u8SetPinDirection(DIO_u8_PORTF, copy_u8LedColour ,DIO_u8_OUTPUT);  	//then initialize the LED direction	
}

void LED_voidLedOn(u8 copy_u8LedColour)
{
	DIO_u8SetPinValue(DIO_u8_PORTF, copy_u8LedColour ,DIO_u8_HIGH);
}

void LED_voidLedOff(u8 copy_u8LedColour)
{
	DIO_u8SetPinValue(DIO_u8_PORTF, copy_u8LedColour ,DIO_u8_LOW);
}

void LED_voidLedTog(u8 copy_u8LedColour)
{
	u32 Local_u32LedState;
	DIO_u8GetPinValue (DIO_u8_PORTF, copy_u8LedColour ,&Local_u32LedState); //this will put the pin value in LedState variable
	if (Local_u32LedState == DIO_u8_HIGH)
	{
		LED_voidLedOff(copy_u8LedColour);  // turns LED off if it was on
	}
	else
	{
		LED_voidLedOn(copy_u8LedColour); // turns LED on if it was off
	}
}

void LED_voidLedBlinkOnce(u8 copy_u8LedColour)
{
	LED_voidLedTog(copy_u8LedColour);
	STK_voidDelay(1000);              //delay of 1 sec
	LED_voidLedTog(copy_u8LedColour);
	
}

void LED_voidLedBlinkTwice(u8 copy_u8LedColour)
{
	LED_voidLedBlinkOnce(copy_u8LedColour);
	STK_voidDelay(1000);              //delay of 1 sec
	LED_voidLedBlinkOnce(copy_u8LedColour);
}