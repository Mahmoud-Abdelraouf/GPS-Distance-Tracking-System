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
   UART_voidInit(UART0, UART_BDR_9600, UART_DATA_8, UART_PARITY_NONE, UART_STOP_BIT_1);
   for(int i = 0;i< 5;i++)
   {
       UART_voidSendString(UART0, "Mahmoud abdelraouf");
   }
    while(1);

    return 0;
}




