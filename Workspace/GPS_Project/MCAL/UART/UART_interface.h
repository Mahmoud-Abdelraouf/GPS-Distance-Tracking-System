// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********
// ********** Date    : 14/04/2023              	***********
// ********** SWC     : MCAL_UART                   ***********
// ********** Version : 1.0                    		***********
// ************************************************************
#ifndef __MCAL_UART_INTERFACE_H__
#define __MCAL_UART_INTERFACE_H__

/*************************************< UART ***************************************************/
#define UART0                   0
#define UART1                   1
#define UART2                   2
#define UART3                   3
#define UART4                   4
#define UART5                   5
#define UART6                   6
#define UART7                   7
/*************************************< UART PARITY ********************************************/
#define UART_PARITY_NONE        0
#define UART_PARITY_ODD         1
#define UART_PARITY_EVEN        2
/*************************************< UART DATA **********************************************/
#define UART_DATA_5				5
#define UART_DATA_6				6
#define UART_DATA_7				7
#define UART_DATA_8				8
/*************************************< UART STOPBIT *******************************************/
#define UART_STOP_BIT_1			1
#define UART_STOP_BIT_2			2
/*************************************< UART BAUDRATE ******************************************/
#define UART_BDR_2400			2400
#define UART_BDR_4800			4800	
#define UART_BDR_9600			9600
#define UART_BDR_14400			14400
#define UART_BDR_19200			19200
#define UART_BDR_28800			28800
#define UART_BDR_38400			38400
#define UART_BDR_57600			57600
#define UART_BDR_76800			76800
#define UART_BDR_115200			115200
#define UART_BDR_230400			230400
#define UART_BDR_250000			250000
/************************************< FUNCTIONS ***********************************************/
/** \brief 	This function UART_voidInit initializes a UART (Universal Asynchronous Receiver/Transmitter) 
 *			module for a specified UART number, with the specified baud rate, data bits, 
 *			parity, and stop bits. The function first calculates the divisor value for the 
 *			specified baud rate and sets the clock for the UART and GPIO pins. 
 *			It then configures the UART pins for the specified UART number and sets the data 
 *			format, including the data bits, parity, and stop bits. Finally, it enables the UART.
 *
 *			The function takes five arguments:
 *
 *			copy_u8UartNo: specifies the UART number to be initialized (e.g., UART0, UART1, etc.).
 *			copy_u32BaudRate: specifies the baud rate for the UART.
 *			copy_u8DataBits: specifies the number of data bits (5-8 bits).
 *			copy_u8Parity: specifies the parity type (None, Even, or Odd).
 *			copy_u8StopBits: specifies the number of stop bits (1 or 2 bits).
 *			
 * \param 	copy_u8UARTNo: YOUR_OPTIONS:
 *										1) UART0
 *										2) UART1
 *										3) UART2
 *										4) UART3
 *										5) UART4
 *										6) UART5
 *										7) UART6
 *										8) UART7
 *			copy_u32BaudRate: YOUR_OPTIONS:
 *										1) UART_BDR_2400
 *										2) UART_BDR_4800
 *										3) UART_BDR_9600
 *										4) UART_BDR_14400
 *										5) UART_BDR_19200
 *										6) UART_BDR_28800
 *										7) UART_BDR_38400
 *										8) UART_BDR_57600
 *										9) UART_BDR_76800
 *										10)UART_BDR_115200
 *										11)UART_BDR_230400
 *										12)UART_BDR_250000
 *			copy_u8DataBits: YOUR_OPTIONS:
 *										1) UART_DATA_5
 *										2) UART_DATA_6
 *										3) UART_DATA_7
 *										4) UART_DATA_8
 *			copy_u8Parity: YOUR_OPTIONS:
 *										1) UART_PARITY_NONE
 *										2) UART_PARITY_ODD
 *										3) UART_PARITY_EVEN
 *			copy_u8StopBits: YOUR_OPTIONS:
 *										1) UART_STOP_BIT_1
 *										2) UART_STOP_BIT_2
 * \return 	void
 *
 */ 
void UART_voidInit(u8 copy_u8UARTNo,u32 copy_u32BaudRate, u8 copy_u8DataBits, u8 copy_u8Parity, u8 copy_u8StopBits);
/** \brief 	This is a function in C programming language that is used to send a byte of data via UART 
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
 * \param 	copy_u8UARTNo: This is an unsigned 8-bit integer that represents the UART 
 *			(Universal Asynchronous Receiver/Transmitter) interface number to be used for transmitting 
 *			the data. This parameter can have a value from 0 to 7, where 0 corresponds to UART0 and 7 
 *			corresponds to UART7.
 *
 *			copy_u8Data: This is an unsigned 8-bit integer that represents the data byte to 
 *			be transmitted over the selected UART interface. This parameter can have a value 
 *			from 0x00 to 0xFF, where 0x00 is the lowest possible value and 0xFF is the highest 
 *			possible value for an 8-bit unsigned integer.
 * \return 	void
 *
 */ 
void UART_voidSendByte(u8 copy_u8UARTNo,u8 copy_u8Data);
/** \brief	This is a function in C programming language that is used to receive a byte of 
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
 * \param 	copy_u8UARTNo: This is an unsigned 8-bit integer that represents the UART 
 *			(Universal Asynchronous Receiver/Transmitter) interface number to be used 
 *			for receiving the data. This parameter can have a value from 0 to 7, where 0 
 *			corresponds to UART0 and 7 corresponds to UART7.
 *
 *			copy_pu8ReceivedData: This is a pointer to an unsigned 8-bit integer that 
 *			represents the memory location where the received data byte will be stored. 
 *			This parameter should be a valid memory address that points to a location where 
 *			the received data byte can be stored.
 *
 *
 * \return 	void
 *
 */ 
void UART_voidReceiveByte(u8 copy_u8UARTNo,u8 *copy_pu8ReceivedData);
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 
void UART_voidSendString(u8 copy_u8UARTNo,u8 *copy_pu8SentString);
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 
void UART_voidReceiveString(u8 copy_u8UARTNo,u8 *copy_pu8Buffer);


#endif // __MCAL_UART_INTERFACE_H__
