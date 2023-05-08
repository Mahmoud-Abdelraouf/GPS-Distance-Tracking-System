/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: Mahmoud Abdelraouf
 */
/**< LIB */
#include "../LIB/STD_TYPES.h"
/**< MCAL */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/STK/STK_interface.h"
#include "../MCAL/UART/UART_interface.h"
/**< HAL */
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/GPS/GPS_interface.h"
int main()
{

    LCD_voidInit();
    LCD_voidSendString("Somay Ayman");
    LCD_voidGoToXYPos(1,0);
    LCD_voidSendString("Sara ashraf");
    while(1);

    return 0;
}




