

/**
 * main.c
 */
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "DIO_interface.h"
#include "STK_interface.h"
/**< HAL */
#include "LCD_interface.h"
int main(void)
{

    LCD_voidInit();
    LCD_voidSendString("Mahmoud A Raouf");
    LCD_voidGoToXYPos(1,0);
    LCD_voidSendNumber(2001436);
    while(1);
	return 0;
}


