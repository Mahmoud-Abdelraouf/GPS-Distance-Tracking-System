// ********************
// **** Name    : ASU_EMBEDDED_TEAM_NO?!		*****
// **** Date    : 14/04/2023              	*****
// **** SWC     : MCAL_UART                   *****
// **** Version : 1.0                    		*****
// ********************
#include <string.h>
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
/**< HAL_UART */
#include "UART_interface.h"




void UART_voidInit() {
SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
UART0_CTL_R &= ~ UART_CTL_UARTEN;
UART0_IBRD_R = 104;
UART0_FBRD_R = 11;
UART0_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN) ;
UART0_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
GPIO_PORTA_AFSEL_R |= 0x03;
GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R &= ~0xFF)|(GPIO_PCTL_PA1_U0TX|GPIO_PCTL_PA0_U0RX);
GPIO_PORTA_DEN_R |= 0x03;
GPIO_PORTA_AMSEL_R &= ~0x03;
}


/**
 * Description :
 * Function to send byte using UART2
 */

void UART_voidSendByte(const u8 data)
{
	while ((UART0_FR_R & 0X0020) !=0); //check if the buffer is full
    UART0_DR_R =data;  // wait until Tx buffer not full, before giving it another byte
}

/**
 * Description :
 * Function to receive byte using UART2
 */
u8 UART_u8RecieveByte(void)
{
	while (UART0_FR_R & UART_FR_RXFE != 0); //check if the buffor is empty
	return (u8)(UART0_DR_R);
}

void UART_voidSendString(const u8 *copy_pu8String)
{
    u32 i = 0;
	while(copy_pu8String[i] != '\0')
	{
	    UART_voidSendByte(copy_pu8String[i]);
	    i++;
	}
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

	/* Receive the whole string until the '#' */
	while(copy_pu8String[i] != '\0')//'*'
	{
		i++;
		copy_pu8String[i] = UART_u8RecieveByte();
	}

	/* After receiving the whole string plus the '', replace the '' with '\0' */
	copy_pu8String[i] = '\0';
}
