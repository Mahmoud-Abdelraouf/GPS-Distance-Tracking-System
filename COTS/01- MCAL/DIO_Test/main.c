/************LIB************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/************MCAL************/
#include "DIO_interface.h"


int main(void)
{
	DIO_voidInit(DIO_u8_PORTF);
	DIO_u8SetPinDirection(DIO_u8_PORTF,DIO_u8_PIN3,DIO_u8_OUTPUT);
	DIO_u8SetPinValue(DIO_u8_PORTF,DIO_u8_PIN3,DIO_u8_HIGH);
	while(1);
	
	
	
	return 0;
}
