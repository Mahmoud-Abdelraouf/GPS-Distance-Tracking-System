/**************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********/
/********** Date    : 14/04/2023              	    ***********/
/********** SWC     : MCAL_UART                     ***********/
/********** Version : 1.0                    		***********/
/**************************************************************/
#ifndef MCAL_UART_INTERFACE_H__
#define MCAL_UART_INTERFACE_H__

/**
 * @defgroup UART_Configuration UART Configuration
 * Configuration parameters for UART modules.
 * @{
 */

/** @name UART Module IDs */
/** @{ */
#define UART0               0 /**< UART Module 0 */
#define UART1               1 /**< UART Module 1 */
#define UART2               2 /**< UART Module 2 */
#define UART3               3 /**< UART Module 3 */
#define UART4               4 /**< UART Module 4 */
#define UART5               5 /**< UART Module 5 */
#define UART6               6 /**< UART Module 6 */
#define UART7               7 /**< UART Module 7 */
/** @} */

/** @name UART Parity Types */
/** @{ */
#define UART_PARITY_NONE    0 /**< No parity */
#define UART_PARITY_ODD     1 /**< Odd parity */
#define UART_PARITY_EVEN    2 /**< Even parity */
/** @} */

/** @name UART Data Lengths */
/** @{ */
#define UART_DATA_5         5 /**< 5 data bits */
#define UART_DATA_6         6 /**< 6 data bits */
#define UART_DATA_7         7 /**< 7 data bits */
#define UART_DATA_8         8 /**< 8 data bits */
/** @} */

/** @name UART Stop Bits */
/** @{ */
#define UART_STOP_BIT_1     1 /**< 1 stop bit */
#define UART_STOP_BIT_2     2 /**< 2 stop bits */
/** @} */

/** @name UART Baud Rates */
/** @{ */
#define UART_BDR_2400       2400    /**< Baud rate 2400 */
#define UART_BDR_4800       4800    /**< Baud rate 4800 */
#define UART_BDR_9600       9600    /**< Baud rate 9600 */
#define UART_BDR_14400      14400   /**< Baud rate 14400 */
#define UART_BDR_19200      19200   /**< Baud rate 19200 */
#define UART_BDR_28800      28800   /**< Baud rate 28800 */
#define UART_BDR_38400      38400   /**< Baud rate 38400 */
#define UART_BDR_57600      57600   /**< Baud rate 57600 */
#define UART_BDR_76800      76800   /**< Baud rate 76800 */
#define UART_BDR_115200     115200  /**< Baud rate 115200 */
#define UART_BDR_230400     230400  /**< Baud rate 230400 */
#define UART_BDR_250000     250000  /**< Baud rate 250000 */
/** @} */

/** @} */

/**
 * @brief Initializes a UART module with specified parameters.
 *
 * This function initializes a UART (Universal Asynchronous Receiver/Transmitter) module 
 * for a specified UART number, baud rate, data bits, parity, and stop bits. 
 * It calculates the divisor value for the specified baud rate and sets the clock for 
 * the UART and GPIO pins. Then, it configures the UART pins and sets the data format, 
 * including the number of data bits, parity type, and number of stop bits. 
 * Finally, it enables the UART.
 *
 * @param UARTNo The UART number to be initialized. Options include:
 *               - UART0
 *               - UART1
 *               - UART2
 *               - UART3
 *               - UART4
 *               - UART5
 *               - UART6
 *               - UART7
 * @param BaudRate The baud rate for the UART. Available options:
 *               - UART_BDR_2400
 *               - UART_BDR_4800
 *               - UART_BDR_9600
 *               - UART_BDR_14400
 *               - UART_BDR_19200
 *               - UART_BDR_28800
 *               - UART_BDR_38400
 *               - UART_BDR_57600
 *               - UART_BDR_76800
 *               - UART_BDR_115200
 *               - UART_BDR_230400
 *               - UART_BDR_250000
 * @param DataBits The number of data bits. Options include:
 *               - UART_DATA_5
 *               - UART_DATA_6
 *               - UART_DATA_7
 *               - UART_DATA_8
 * @param Parity The parity type. Options include:
 *               - UART_PARITY_NONE
 *               - UART_PARITY_ODD
 *               - UART_PARITY_EVEN
 * @param StopBits The number of stop bits. Options include:
 *               - UART_STOP_BIT_1
 *               - UART_STOP_BIT_2
 *
 * @return void
 */
void UART_Init(u8 UARTNo, u32 BaudRate, u8 DataBits, u8 Parity, u8 StopBits);

/** @brief 	This is a function in C programming language that is used to send a byte of data via UART 
 *			(Universal Asynchronous Receiver/Transmitter) communication protocol. 
 *			The function takes two arguments: the first argument is the UART number to be used, 
 *			and the second argument is the data byte to be sent.
 *
 *			The function first waits for the transmit buffer to be available (not full) before 
 *			sending the byte of data. This is done using a while loop that checks the value of the 
 *			UART_FR_TXFF flag in the UART status register (UARTx_FR_R). 
 *			The flag is set if the transmit buffer is full, which means that the UART is currently 
 *			busy sending data and cannot accept any more data until some of the buffer space has 
 *			been freed up.
 *
 *			Once the transmit buffer is available, the function sends the data byte by writing 
 *			it to the UART data register (UARTx_DR_R), where it will be transmitted over 
 *			the communication channel.
 *
 *			The function supports up to 8 UART interfaces (UART0 to UART7) by using a switch-case statement 
 *			to select the appropriate UART based on the value of the first argument passed to the function. 
 *			If the argument is not a valid UART number, the function does nothing (ERROR_STATE).
 *
 *			Overall, this function is a simple implementation of the UART transmit functionality 
 *			that ensures data is not lost due to buffer overflow and helps in efficient data 
 *			transmission over the
 *			
 * @param 	copy_u8UARTNo: This is an unsigned 8-bit integer that represents the UART 
 *			(Universal Asynchronous Receiver/Transmitter) interface number to be used for transmitting 
 *			the data. This parameter can have a value from 0 to 7, where 0 corresponds to UART0 and 7 
 *			corresponds to UART7.
 *
 *			copy_u8Data: This is an unsigned 8-bit integer that represents the data byte to 
 *			be transmitted over the selected UART interface. This parameter can have a value 
 *			from 0x00 to 0xFF, where 0x00 is the lowest possible value and 0xFF is the highest 
 *			possible value for an 8-bit unsigned integer.
 * @return 	void
 *
 */ 
void UART_SendByte(u8 UARTNo,u8 copy_u8Data);

/** @brief	This is a function in C programming language that is used to receive a byte of 
 *			data via UART (Universal Asynchronous Receiver/Transmitter) communication protocol. 
 *			The function takes two arguments: the first argument is the UART number to be used, and the 
 *			second argument is a pointer to a variable where the received data byte will be stored.
 *
 *			The function first waits for the receive buffer to have data available before receiving 
 *			the byte of data. This is done using a while loop that checks the value of the 
 *			UART_FR_RXFE flag in the UART status register (UARTx_FR_R). The flag is set if 
 *			the receive buffer is empty, which means that the UART is currently not receiving 
 *			any data and cannot provide any data until some data is received.
 *
 *			Once the receive buffer has data available, the function receives the data byte 
 *			by reading it from the UART data register (UARTx_DR_R) and storing it at the 
 *			memory location pointed to by the second argument passed to the function.
 *
 *			The function supports up to 8 UART interfaces (UART0 to UART7) by using a switch-case 
 *			statement to select the appropriate UART based on the value of the first argument 
 *			passed to the function. If the argument is not a valid UART number, the function does 
 *			nothing (ERROR_STATE).
 *
 *			The function returns an unsigned 8-bit integer that represents the status of the 
 *			receive operation. The return value can be used to check whether the receive operation 
 *			was successful or not. A return value of 1 indicates success, while a return value of 0 
 *			indicates failure.	
 *			
 * @param 	copy_u8UARTNo: This is an unsigned 8-bit integer that represents the UART 
 *			(Universal Asynchronous Receiver/Transmitter) interface number to be used 
 *			for receiving the data. This parameter can have a value from 0 to 7, where 0 
 *			corresponds to UART0 and 7 corresponds to UART7.
 *
 * @param	copy_pu8ReceivedData: This is a pointer to an unsigned 8-bit integer that 
 *			represents the memory location where the received data byte will be stored. 
 *			This parameter should be a valid memory address that points to a location where 
 *			the received data byte can be stored.
 *
 *
 * @return 	void
 *
 */ 
void UART_ReceiveByte(u8 UARTNo,u8 *ReceivedData);

/**
 * @brief Sends a string through the specified UART module.
 *
 * This function sends a null-terminated string through the specified UART module.
 *
 * @param UARTNo The UART module number.
 * @param SentString Pointer to the string to be sent.
 */
void UART_SendString(u8 UARTNo, u8 *SentString);


/**
 * @brief Receives a string through the specified UART module.
 *
 * This function receives a string through the specified UART module and stores it in the provided buffer.
 *
 * @param UARTNo The UART module number.
 * @param Buffer Pointer to the buffer where the received string will be stored.
 */
void UART_ReceiveString(u8 UARTNo, u8 *Buffer);


#endif /**< MCAL_UART_INTERFACE_H__ */ 
