
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL*/
#include "DIO_interface.h"
#include "STK_interface.h"
#include "LED_interface.h"
#include "UART_interface.h"


#include <stdio.h>

#define LED_RED  	 	1
#define LED_BLUE 		2

int main(void){
 UART_voidInit();
 LED_voidLedInit(LED_RED);        //function to initialize a specific LED
 LED_voidLedInit(LED_BLUE);        //function to initialize a specific LED
 u8 input[20];	
    while (1) {
		
		 UART_voidReceiveString(input);
		 
	    // use a function to receive input 
        // Turn on RED LED if input is "OK" and BLUE LED if else
			
        if (input[0] == 'O' && input[1] == 'K') 
					{
		 LED_voidLedOn(LED_RED);	      	
          } 
				else
					{
		 LED_voidLedOn(LED_BLUE);	      	
          }
    }
}