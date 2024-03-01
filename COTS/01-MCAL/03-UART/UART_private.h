/**************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********/
/********** Date    : 14/04/2023              	    ***********/
/********** SWC     : MCAL_UART                     ***********/
/********** Version : 1.0                    		***********/
/**************************************************************/
#ifndef __MCAL_UART_PRIVATE_H__
#define __MCAL_UART_PRIVATE_H__

/*************************************< UART TX, RX *************************************/				
/**< UART0 */
#define GPIO_PA0_U0RX			0x00000001
#define GPIO_PA1_U0TX			0x00000002
/**< UART1 */
#define GPIO_PB0_U1RX			0x00000001
#define GPIO_PB1_U1TX			0x00000002
/**< UART2 */
#define GPIO_PD6_U2RX			0x00000040			
#define GPIO_PD7_U2TX			0x00000080
/**< UART3 */
#define GPIO_PC6_U3RX			0x00000040			
#define GPIO_PC7_U3TX			0x00000080
/**< UART4 */
#define GPIO_PC4_U4RX			0x00000010
#define GPIO_PC5_U4TX			0x00000020
/**< UART5 */
#define GPIO_PE4_U5RX			0x00000010
#define GPIO_PE5_U5TX			0x00000020
/**< UART6 */
#define GPIO_PD4_U6RX			0x00000010
#define GPIO_PD5_U6TX			0x00000020
/**< UART7 */
#define GPIO_PE0_U7RX			0x00000001
#define GPIO_PE1_U7TX			0x00000002
/**<  */
#define UART_POARTA				0
#define UART_POARTB				1
#define UART_POARTC				2
#define UART_POARTD				3
#define UART_POARTE				4
/*************************************< UART_DATA_LENGTH_MSK ****************************/
#define UART_LCRH_WLEN_S		5

#define UART_CLOCK              16000000





#endif // __MCAL_UART_INTERFACE_H__
