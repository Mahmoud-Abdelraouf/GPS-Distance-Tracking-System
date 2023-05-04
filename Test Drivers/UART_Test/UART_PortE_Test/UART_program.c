// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********
// ********** Date    : 5/05/2023              	***********
// ********** SWC     : MCAL_UART                   ***********
// ********** Version : 2.0                    		***********
// ************************************************************
#include <string.h>
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
/**< MCAL_UART */
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


/**
 * Description :
 * Function to initials the UART5 driver for tiva c
 */

void UART_voidInit5(void){


    SYSCTL_RCGCUART_R |= 0x20; // Enable UART5 module clock
    SYSCTL_RCGCGPIO_R |= 0x10; //checked Enable GPIO port E clock

     while((SYSCTL_PRGPIO_R&0x10) == 0);
    // Disable UART5 set all needed pins and enable it after
     UART5_CTL_R &= ~0x01;

    // Set baud rate to 9600 (assuming system clock frequency is 16 MHz)
     UART5_IBRD_R = 104;
     UART5_FBRD_R = 11;

    // Set data length to 8 bits, no parity, and 1 stop bit
     UART5_LCRH_R = 0x70;

    // Enable transmit and receive, and any interrupt needed
     UART5_CTL_R = 0x301;


    //GPIO CONFIGURATION CHECKED
    // Configure GPIO port E pins 4 and 5 for alternate function (UART5)
    GPIO_PORTE_AFSEL_R |= 0x30; //checked
    GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & 0xFF00FFFF) | 0x00110000;//correct
    GPIO_PORTE_DEN_R |= 0x30; //00110000
    GPIO_PORTE_AMSEL_R &= ~0x30;
    GPIO_PORTE_DIR_R |= (1<<5); // Set PE5 as output
    GPIO_PORTE_DIR_R &= ~(1<<4); // Set PE4 as input
}


/**
 * Description :
 * Function to send byte using UART0
 */


void UART_voidSendByte(u8 copy_u8Data)
{
    while((UART5_FR_R & (1<<5)) != 0); // wait tx buffer
    UART5_DR_R = copy_u8Data;
}


/**
 * Description :
 * Function to receive byte using UART5
 */


u8 UART_u8RecieveByte(void)
{
	// Wait until the receiver FIFO is not empty
    while ((UART5_FR_R & (1 << 4)) != 0);

    // Read the received byte from the data register and return it as a character
    return (char)(UART5_DR_R & 0xFF);
}


/**
 * Description :
 * This function is designed to send a string of characters over UART (Universal Asynchronous Receiver/Transmitter)
 * communication protocol.
 */


void UART_voidSendString(const u8 *copy_pu8String)
{
    while(*copy_pu8String) {
        UART_voidSendByte(*copy_pu8String);
           copy_pu8String++;
       }
    UART_voidSendByte('\n'); // add newline character at the end of the string
}


/**
 * Description :
 * Receive the required string until the '\0' symbol through UART from the other UART device.
 */


void UART_voidReceiveString(u8 *copy_pu8String)
{
    u8 i = 0;

    /* Receive the first byte */
    copy_pu8String[i] = UART_u8RecieveByte();

    /* Receive the whole string until the '/0' */
    while(copy_pu8String[i] != '\0')
    {
        i++;
        copy_pu8String[i] = UART_u8RecieveByte();
    }

    /* After receiving the whole string plus the '', replace the '' with '\0' */
    copy_pu8String[i] = '\0';
}

/**
 * Description :
 * Receive the required string until the '*' symbol through UART from the other UART device.
 */

void GPS_voidReceiveString(u8 *copy_pu8String)
{
    u8 i = 0;

    /* Receive the first byte */
    copy_pu8String[i] = UART_u8RecieveByte();

    /* Receive the whole string until the '*' */
    while(copy_pu8String[i] != '*')
    {
        i++;
        copy_pu8String[i] = UART_u8RecieveByte();
    }

    /* After receiving the whole string plus the '', replace the '' with '\0' */
    copy_pu8String[i] = '\0';
}
