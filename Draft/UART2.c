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
    // Enable UART2 clock and GPIO Port D clock
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;

    // Wait for clock stabilization
    while((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R3) == 0);

    // Disable UART2 and set baud rate
    UART2_CTL_R &= ~UART_CTL_UARTEN;
    UART2_IBRD_R = 104;  // 16MHz / (16 * 9600) = 104.1667
    UART2_FBRD_R = 11;   // Round(0.1667 * 64) = 11

    // Set data format (8 data bits, 1 stop bit, no parity)
    UART2_LCRH_R = UART_LCRH_WLEN_8;

    // Enable UART2, RX, and TX
    UART2_CTL_R |= UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN;

    // Configure GPIO pins for UART2
    GPIO_PORTD_AFSEL_R |= (1 << 6) | (1 << 7);
    GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & ~(0xFF000000)) | (GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX);
    GPIO_PORTD_DEN_R |= (1 << 6) | (1 << 7);
    GPIO_PORTD_AMSEL_R &= ~((1 << 6) | (1 << 7));
}


/**
 * Description :
 * Function to send byte using UART2
 */

void UART_voidSendByte(const u8 data)
{
	while ((UART2_FR_R & UART_FR_TXFF) !=0); //check if the buffer is full
	UART2_DR_R =data;  // wait until Tx buffer not full, before giving it another byte
}

/**
 * Description :
 * Function to receive byte using UART2
 */
u8 UART_u8RecieveByte(void)
{
	while (UART2_FR_R & UART_FR_RXFE != 0); //check if the buffor is empty
	return (u8)(UART2_DR_R);
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
