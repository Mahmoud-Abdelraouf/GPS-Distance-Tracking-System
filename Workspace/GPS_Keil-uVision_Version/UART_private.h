/**************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********/
/********** Date    : 14/04/2023              	    ***********/
/********** SWC     : MCAL_UART                     ***********/
/********** Version : 1.0                    		***********/
/**************************************************************/
#ifndef MCAL_UART_PRIVATE_H__
#define MCAL_UART_PRIVATE_H__

/**
 * @defgroup UART_GPIO_Mapping UART GPIO Mapping
 * GPIO pin mappings for UART modules.
 * @{
 */

/** @name UART Module 0 */
/** @{ */
#define GPIO_PA0_U0RX    0x00000001 /**< UART0 RX pin on Port A Pin 0 */
#define GPIO_PA1_U0TX    0x00000002 /**< UART0 TX pin on Port A Pin 1 */
/** @} */

/** @name UART Module 1 */
/** @{ */
#define GPIO_PB0_U1RX    0x00000001 /**< UART1 RX pin on Port B Pin 0 */
#define GPIO_PB1_U1TX    0x00000002 /**< UART1 TX pin on Port B Pin 1 */
/** @} */

/** @name UART Module 2 */
/** @{ */
#define GPIO_PD6_U2RX    0x00000040 /**< UART2 RX pin on Port D Pin 6 */
#define GPIO_PD7_U2TX    0x00000080 /**< UART2 TX pin on Port D Pin 7 */
/** @} */

/** @name UART Module 3 */
/** @{ */
#define GPIO_PC6_U3RX    0x00000040 /**< UART3 RX pin on Port C Pin 6 */
#define GPIO_PC7_U3TX    0x00000080 /**< UART3 TX pin on Port C Pin 7 */
/** @} */

/** @name UART Module 4 */
/** @{ */
#define GPIO_PC4_U4RX    0x00000010 /**< UART4 RX pin on Port C Pin 4 */
#define GPIO_PC5_U4TX    0x00000020 /**< UART4 TX pin on Port C Pin 5 */
/** @} */

/** @name UART Module 5 */
/** @{ */
#define GPIO_PE4_U5RX    0x00000010 /**< UART5 RX pin on Port E Pin 4 */
#define GPIO_PE5_U5TX    0x00000020 /**< UART5 TX pin on Port E Pin 5 */
/** @} */

/** @name UART Module 6 */
/** @{ */
#define GPIO_PD4_U6RX    0x00000010 /**< UART6 RX pin on Port D Pin 4 */
#define GPIO_PD5_U6TX    0x00000020 /**< UART6 TX pin on Port D Pin 5 */
/** @} */

/** @name UART Module 7 */
/** @{ */
#define GPIO_PE0_U7RX    0x00000001 /**< UART7 RX pin on Port E Pin 0 */
#define GPIO_PE1_U7TX    0x00000002 /**< UART7 TX pin on Port E Pin 1 */
/** @} */

/** @name UART Port IDs */
/** @{ */
#define UART_PORTA       0 /**< UART Port A */
#define UART_PORTB       1 /**< UART Port B */
#define UART_PORTC       2 /**< UART Port C */
#define UART_PORTD       3 /**< UART Port D */
#define UART_PORTE       4 /**< UART Port E */
/** @} */

/** @} */

/**
 * @defgroup UART_Configuration UART Configuration
 * Configuration parameters for UART modules.
 * @{
 */

/** @name UART Line Control Register High Width Length Shift */
/** @{ */
#define UART_LCRH_WLEN_S    5 /**< Shift value for setting word length in UART Line Control Register High */
/** @} */

/** @name UART Clock Frequency */
/** @{ */
#define UART_CLOCK          16000000 /**< UART Clock Frequency (Hz) */
/** @} */

/** @} */

#endif /**< MCAL_UART_INTERFACE_H__ */ 
