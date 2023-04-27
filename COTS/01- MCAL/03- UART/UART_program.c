// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********
// ********** Date    : 14/04/2023              	***********
// ********** SWC     : MCAL_UART                   ***********
// ********** Version : 1.0                    		***********
// ************************************************************
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
/**< HAL_UART */
#include "UAR_interface.h"
#include "UAR_private.h"
#include "UAR_config.h"



/**
 * Description :
 * Function to initials the UART0 driver for tiva c
 */
void UART_voidInit(void)
{
  SYSCTL_RCGCUART_R |= 0x01;            // activate UART0
  SYSCTL_RCGCGPIO_R |= 0x01;            // activate port A //gpio team might provide a function for that
  while((SYSCTL_PRGPIO_R&0x01) == 0);   //gpio team might make a function for both
  
  UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART 3obal ma azbt tazbetate //uartctl responsible for uart control //lazem a3mlo clear abl ma azbt ay haga
  UART0_IBRD_R = 104;                    // IBRD = int(16,000,000 / (16 * 9600)) = int(104.166)
  UART0_FBRD_R = 11;                     // FBRD = int(0.16667 * 64 + 0.5) = 8
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN); //8 bit, no parity not equal //msh fahmah awee
  UART0_CTL_R |= UART_CTL_UARTEN;       // enable UART
  GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1-0
                                        // configure PA1-0 as UART
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011; //aseeb el qayam el 3ala ba2e port a + amsah el qayam bta3t a0 w a1 w ba3d kda a5lehom bwhayed
  GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA A1 A0
}


/**
 * Description :
 * Function to send byte using UART0 
 */

void UART_voidSendByte(const uint8 data)
{
	while ((UART0_FR_R & 0X0020) !=0); //check if the buffer is full
	UART0_DR_R =data;  // wait until Tx buffer not full, before giving it another byte 
}

/**
 * Description :
 * Function to receive byte using UART0 
 */
u8 UART_u8RecieveByte(void)
{
	while (UARTO_FR_R & 0x0010 != 0); //check if the buffor is empty 
	return (UARTO_DR_R & OxFF);
}
/**
 * Description :
 * This function is designed to send a string of characters over UART (Universal Asynchronous Receiver/Transmitter)
 * communication protocol.
 */
void UART_voidSendString(const u8 *Str)
{
	u32 string_length = strlen(str);
	for(u32 i = 0; i<string_length; i++)
	{
		UART_sendByte(Str[i]);
	}
}
/**
 * Description :
 * Receive the required string until the '*' symbol through UART from the other UART device.
 */
void UART_voidReceiveString(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte();

	/* Receive the whole string until the '#' */
	while(Str[i] != '*')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

	/* After receiving the whole string plus the '', replace the '' with '\0' */
	Str[i] = '\0';
}


