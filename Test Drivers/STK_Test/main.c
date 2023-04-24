/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL*/
#include "DIO_interface.h"
#include "STK_interface.h"
#include <stdio.h>

int main(void)
{
	u32 x = 0;
	DIO_voidInit(DIO_u8_PORTF);
	DIO_u8SetPinDirection(DIO_u8_PORTF,DIO_u8_PIN2,DIO_u8_OUTPUT);
	while(1)
	{
		DIO_u8SetPinValue(DIO_u8_PORTF,DIO_u8_PIN2,DIO_u8_HIGH);
		STK_voidDelay(2000);
		DIO_u8SetPinValue(DIO_u8_PORTF,DIO_u8_PIN2,DIO_u8_LOW);
		STK_voidDelay(2000);	
	}
	
	
	
	return 0;
}
