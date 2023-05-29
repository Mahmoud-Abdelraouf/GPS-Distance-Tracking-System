// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!	    ***********
// ********** Date    : 14/04/2023                  ***********
// ********** SWC     : MCAL_UART                   ***********
// ********** Version : 1.0                    	    ***********
// ************************************************************
/**< LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/tm4c123gh6pm.h"
/**< MCAL_UART */
#include "../../MCAL/UART/UART_private.h"
#include "../../MCAL/UART/UART_interface.h"
#include "../../MCAL/UART/UART_config.h"
/****************************************< UART_FUNCTIONS_IMPLEMENTATION ****************************************/
void UART_voidInit(u8 copy_u8UARTNo,u32 copy_u32BaudRate, u8 copy_u8DataBits, u8 copy_u8Parity, u8 copy_u8StopBits)
{
	f32 Local_u32Divisor = UART_CLOCK / (copy_u32BaudRate * 16);
	f32 Local_u32FractionalDivider = Local_u32Divisor-(u32)(Local_u32Divisor);
	switch(copy_u8UARTNo)
	{
		case UART0:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R,copy_u8UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_POARTA);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_POARTA));
		/**< Configure UART pins */
		GPIO_PORTA_AFSEL_R |= GPIO_PA0_U0RX | GPIO_PA1_U0TX; /**< Set the PA0 and PA1 to operate in alternative mode */
		GPIO_PORTA_PCTL_R  |= GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX; /**< Select the alternative mode to be UART */
		GPIO_PORTA_DIR_R   |= GPIO_PA1_U0TX;						/**< TX OUTPUT */
		GPIO_PORTA_DIR_R   &=~ GPIO_PA0_U0RX;                       /**< RX INPUT */			
		GPIO_PORTA_DEN_R   |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;
		/**< Disable UART */ 
		UART0_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART0_IBRD_R = (u32)Local_u32Divisor;
		UART0_FBRD_R = (u32)((Local_u32FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART0_LCRH_R = (copy_u8DataBits - 5) << UART_LCRH_WLEN_S;
		if(copy_u8Parity == UART_PARITY_NONE)
		{
			UART0_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(copy_u8Parity == UART_PARITY_ODD)
		{
			UART0_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}
		else if(copy_u8Parity == UART_PARITY_EVEN)
		{
			UART0_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}
		/**< Configure stop bits */ 
		if(copy_u8StopBits == 1)
		{
			UART0_LCRH_R &=~UART_LCRH_STP2;
		}   
		else if(copy_u8StopBits == 2)
		{
			UART0_LCRH_R |= UART_LCRH_STP2;
		} 
		else
		{
			/**< ERROR_STATE */
		}	
		/**< Enable UART */ 
		UART0_CTL_R |= UART_CTL_UARTEN;
		break;
		/*************************************************< THE_END_OF_UART0 *************************************************/
		case UART1:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R,copy_u8UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_POARTB);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_POARTB));
		/**< Configure UART pins */
		GPIO_PORTB_AFSEL_R |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;
		GPIO_PORTB_PCTL_R  |= GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX;
		GPIO_PORTB_DIR_R   |= GPIO_PB1_U1TX;
		GPIO_PORTB_DIR_R   &=~ GPIO_PB0_U1RX;
		GPIO_PORTB_DEN_R   |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;
		/**< Disable UART */ 
		UART1_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART1_IBRD_R = (u32)Local_u32Divisor;
		UART1_FBRD_R = (u32)((Local_u32FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART1_LCRH_R = (copy_u8DataBits - 5) << UART_LCRH_WLEN_S;
		if(copy_u8Parity == UART_PARITY_NONE)
		{
			UART1_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
			
		else if(copy_u8Parity == UART_PARITY_ODD)
		{
			UART1_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}
		else if(copy_u8Parity == UART_PARITY_EVEN)
		{
			UART1_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}
			
		else 
		{
			/**< ERROR_STATE */
		}
		/**< Configure stop bits */ 
		if(copy_u8StopBits == 1)
		{
			UART1_LCRH_R &=~UART_LCRH_STP2;
		}
		else if(copy_u8StopBits == 2)
		{
			UART1_LCRH_R |= UART_LCRH_STP2;
		}
		else
		{
			/**< ERROR_STATE */
		}
		/**< Enable UART */ 
		UART1_CTL_R |= UART_CTL_UARTEN;
		break;
		/*************************************************< THE_END_OF_UART1 *************************************************/
		case UART2:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R,copy_u8UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_POARTD);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_POARTD));
		/**< Configure UART pins */
		GPIO_PORTD_AFSEL_R |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;
		GPIO_PORTD_PCTL_R  |= GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX;
		GPIO_PORTD_DIR_R   |= GPIO_PD7_U2TX;						/**< TX OUTPUT */
		GPIO_PORTD_DIR_R   &=~ GPIO_PD6_U2RX;   					/**< RX INPUT */              
		GPIO_PORTD_DEN_R   |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;
		/**< Disable UART */ 
		UART2_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART2_IBRD_R = (u32)Local_u32Divisor;
		UART2_FBRD_R = (u32)((Local_u32FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART2_LCRH_R = (copy_u8DataBits - 5) << UART_LCRH_WLEN_S;
		if(copy_u8Parity == UART_PARITY_NONE)
		{
			UART2_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}	
		else if(copy_u8Parity == UART_PARITY_ODD)
		{
			UART2_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(copy_u8Parity == UART_PARITY_EVEN)
		{
			UART2_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}
		else 
		{
			/**< ERROR_STATE */
		}	
		/**< Configure stop bits */ 
		if(copy_u8StopBits == 1)
		{
			UART2_LCRH_R &=~UART_LCRH_STP2;
		}    
		else if(copy_u8StopBits == 2)
		{
			 UART2_LCRH_R |= UART_LCRH_STP2;
		}
		else
		{
			/**< ERROR_STATE */
		}
		/**< Enable UART */ 
		UART2_CTL_R |= UART_CTL_UARTEN;
		break;
		/*************************************************< THE_END_OF_UART2 *************************************************/
		case UART3:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R,copy_u8UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_POARTC);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_POARTC));
		/**< Configure UART pins */
		GPIO_PORTC_AFSEL_R |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;
		GPIO_PORTC_PCTL_R  |= GPIO_PCTL_PC6_U3RX | GPIO_PCTL_PC7_U3TX;
		GPIO_PORTC_DIR_R   |= GPIO_PC7_U3TX;			/**< TX OUTPUT */
		GPIO_PORTC_DIR_R   &=~ GPIO_PC6_U3RX;   		/**< RX INPUT */			    
		GPIO_PORTC_DEN_R   |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;
		/**< Disable UART */ 
		UART3_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART3_IBRD_R = (u32)Local_u32Divisor;
		UART3_FBRD_R = (u32)((Local_u32FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART3_LCRH_R = (copy_u8DataBits - 5) << UART_LCRH_WLEN_S;
		if(copy_u8Parity == UART_PARITY_NONE)
		{
			UART3_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}	
		else if(copy_u8Parity == UART_PARITY_ODD)
		{
			UART3_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(copy_u8Parity == UART_PARITY_EVEN)
		{
			UART3_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}
		else 
		{
			/**< ERROR_STATE */
		}
		/**< Configure stop bits */ 
		if(copy_u8StopBits == 1)
		{
			UART3_LCRH_R &=~UART_LCRH_STP2;
		} 
		else if(copy_u8StopBits == 2)
		{
			 UART3_LCRH_R |= UART_LCRH_STP2;
		}   
		else
		{
			/**< ERROR_STATE */
		}	
		/**< Enable UART */ 
		UART3_CTL_R |= UART_CTL_UARTEN;
		break;
		/*************************************************< THE_END_OF_UART3 *************************************************/
		case UART4:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R,copy_u8UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_POARTC);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_POARTC));
		/**< Configure UART pins */
		GPIO_PORTC_AFSEL_R |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;
		GPIO_PORTC_PCTL_R  |= GPIO_PCTL_PC4_U4RX | GPIO_PCTL_PC5_U4TX;
		GPIO_PORTC_DIR_R   |= GPIO_PC5_U4TX;			/**< TX OUTPUT */
		GPIO_PORTC_DIR_R   &=~ GPIO_PC4_U4RX;           /**< RX INPUT */               
		GPIO_PORTC_DEN_R   |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;
		/**< Disable UART */ 
		UART4_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART4_IBRD_R = (u32)Local_u32Divisor;
		UART4_FBRD_R = (u32)((Local_u32FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART4_LCRH_R = (copy_u8DataBits - 5) << UART_LCRH_WLEN_S;
		if(copy_u8Parity == UART_PARITY_NONE)
		{
			UART4_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}	
		else if(copy_u8Parity == UART_PARITY_ODD)
		{
			UART4_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(copy_u8Parity == UART_PARITY_EVEN)
		{
			UART4_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}	
		/**< Configure stop bits */ 
		if(copy_u8StopBits == 1)
		{
			 UART4_LCRH_R &=~UART_LCRH_STP2;
		}  
		else if(copy_u8StopBits == 2)
		{
			UART4_LCRH_R |= UART_LCRH_STP2;
		}   
		else
		{
			/**< ERROR_STATE */
		}
		/**< Enable UART */ 
		UART4_CTL_R |= UART_CTL_UARTEN;
		break;
		/*************************************************< THE_END_OF_UART4 *************************************************/
		case UART5:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R,copy_u8UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_POARTE);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_POARTE));
		/**< Configure UART pins */
		GPIO_PORTE_AFSEL_R |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;
		GPIO_PORTE_PCTL_R  |= GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX;
		GPIO_PORTE_DIR_R   |= GPIO_PE5_U5TX;				/**< TX OUTPUT */
		GPIO_PORTE_DIR_R   &=~ GPIO_PE4_U5RX;               /**< RX INPUT */	            
		GPIO_PORTE_DEN_R   |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;
		/**< Disable UART */ 
		UART5_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART5_IBRD_R = (u32)Local_u32Divisor;
		UART5_FBRD_R = (u32)((Local_u32FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART5_LCRH_R = (copy_u8DataBits - 5) << UART_LCRH_WLEN_S;
		if(copy_u8Parity == UART_PARITY_NONE)
		{
			UART5_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(copy_u8Parity == UART_PARITY_ODD)
		{
			UART5_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(copy_u8Parity == UART_PARITY_EVEN)
		{
			UART5_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}	
		/**< Configure stop bits */ 
		if(copy_u8StopBits == 1)
		{
			 UART5_LCRH_R &=~UART_LCRH_STP2;
		}   
		else if(copy_u8StopBits == 2)
		{
			UART5_LCRH_R |= UART_LCRH_STP2;
		}    
		else
		{
			/**< ERROR_STATE */
		}
		/**< Enable UART */ 
		UART5_CTL_R |= UART_CTL_UARTEN;
		break;
		/*************************************************< THE_END_OF_UART5 *************************************************/
		case UART6:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R,copy_u8UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_POARTD);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_POARTD));
		/**< Configure UART pins */
		GPIO_PORTD_AFSEL_R |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;
		GPIO_PORTD_PCTL_R  |= GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX;
		GPIO_PORTD_DIR_R   |= GPIO_PD5_U6TX;				/**< TX OUTPUT */
		GPIO_PORTD_DIR_R   &=~ GPIO_PD4_U6RX;               /**< RX INPUT */              
		GPIO_PORTD_DEN_R   |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;
		/**< Disable UART */ 
		UART6_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART6_IBRD_R = (u32)Local_u32Divisor;
		UART6_FBRD_R = (u32)((Local_u32FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART6_LCRH_R = (copy_u8DataBits - 5) << UART_LCRH_WLEN_S;
		if(copy_u8Parity == UART_PARITY_NONE)
		{
			UART6_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(copy_u8Parity == UART_PARITY_ODD)
		{
			UART6_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(copy_u8Parity == UART_PARITY_EVEN)
		{
			UART6_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}
		/**< Configure stop bits */ 
		if(copy_u8StopBits == 1)
		{
			 UART6_LCRH_R &=~UART_LCRH_STP2;
		}  
		else if(copy_u8StopBits == 2)
		{
			 UART6_LCRH_R |= UART_LCRH_STP2;
		}
		else
		{
			/**< ERROR_STATE */
		}
		/**< Enable UART */ 
		UART6_CTL_R |= UART_CTL_UARTEN;
		break;
		/*************************************************< THE_END_OF_UART6 *************************************************/
		case UART7:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R,copy_u8UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_POARTE);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_POARTE));
		/**< Configure UART pins */
		GPIO_PORTE_AFSEL_R |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;
		GPIO_PORTE_PCTL_R  |= GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX;
		GPIO_PORTE_DIR_R   |= GPIO_PA1_U0TX;				/**< TX OUTPUT */
		GPIO_PORTE_DIR_R   &=~ GPIO_PA0_U0RX;               /**< RX INPUT */		        
		GPIO_PORTE_DEN_R   |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;
		/**< Disable UART */ 
		UART7_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART7_IBRD_R = (u32)Local_u32Divisor;
		UART7_FBRD_R = (u32)((Local_u32FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART7_LCRH_R = (copy_u8DataBits - 5) << UART_LCRH_WLEN_S;
		if(copy_u8Parity == UART_PARITY_NONE)
		{
			UART7_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(copy_u8Parity == UART_PARITY_ODD)
		{
			UART7_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(copy_u8Parity == UART_PARITY_EVEN)
		{
			UART7_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}	
		/**< Configure stop bits */ 
		if(copy_u8StopBits == 1)
		{
			UART7_LCRH_R &=~UART_LCRH_STP2;
		}
		else if(copy_u8StopBits == 2)
		{
			UART7_LCRH_R |= UART_LCRH_STP2;
		} 
		else
		{
			/**< ERROR_STATE */
		}
		/**< Enable UART */ 
		UART7_CTL_R |= UART_CTL_UARTEN;
		break;
		/*************************************************< THE_END_OF_UART7 *************************************************/
		default : /**<  ERROR_STATE */ break;
	}
}


void UART_voidSendByte(u8 copy_u8UARTNo,u8 copy_u8Data)
{
/** Wait until transmit buffer is not full that's mean:
 *	pause the transmission process until there is space available in the buffer 
 *  to send more data. This indicates that the buffer currently has data in it, 
 *  and the transmission cannot continue until some of that data has been sent and 
 *  space has been freed up in the buffer		
 */ 
	switch(copy_u8UARTNo)
	{
		case UART0:
		while(UART0_FR_R & UART_FR_TXFF);
		/**< Send byte */
		UART0_DR_R = copy_u8Data;
		break;
		case UART1:
		while(UART1_FR_R & UART_FR_TXFF);
		/**< Send byte */
		UART1_DR_R = copy_u8Data;
		break;
		case UART2:
		while(UART2_FR_R & UART_FR_TXFF);
		/**< Send byte */
		UART2_DR_R = copy_u8Data;
		break;
		case UART3:
		while(UART3_FR_R & UART_FR_TXFF);
		/**< Send byte */
		UART3_DR_R = copy_u8Data;
		break;
		case UART4:
		while(UART4_FR_R & UART_FR_TXFF);
		/**< Send byte */
		UART4_DR_R = copy_u8Data;
		break;
		case UART5:
		while(UART5_FR_R & UART_FR_TXFF);
		/**< Send byte */
		UART5_DR_R = copy_u8Data;
		break;
		case UART6:
		while(UART6_FR_R & UART_FR_TXFF);
		/**< Send byte */
		UART6_DR_R = copy_u8Data;
		break;
		case UART7:
		while(UART7_FR_R & UART_FR_TXFF);
		/**< Send byte */
		UART7_DR_R = copy_u8Data;
		break;
		default : /**< ERROR_STATE */ break;
	}
}

void UART_voidReceiveByte(u8 copy_u8UARTNo,u8 *copy_pu8ReceivedData)
{
/** Wait until receive buffer is not empty that's mean:
 *  means to pause the process of reading or receiving data until there is data 
 *  available in the buffer to be read. This indicates that the buffer is currently 
 *  empty and there is no new data to be read
 *
 */
	switch(copy_u8UARTNo)
	{
		case UART0:
		while(UART0_FR_R & UART_FR_RXFE);
		/**< Receive byte */
		*copy_pu8ReceivedData = UART0_DR_R;
		break;
		case UART1:
		while(UART1_FR_R & UART_FR_RXFE);
		/**< Receive byte */
		*copy_pu8ReceivedData = UART1_DR_R;
		break;
		case UART2:
		while(UART2_FR_R & UART_FR_RXFE);
		/**< Receive byte */
		*copy_pu8ReceivedData = UART2_DR_R;
		break;
		case UART3:
		while(UART3_FR_R & UART_FR_RXFE);
		/**< Receive byte */
		*copy_pu8ReceivedData = UART3_DR_R;
		break;
		case UART4:
		while(UART4_FR_R & UART_FR_RXFE);
		/**< Receive byte */
		*copy_pu8ReceivedData = UART4_DR_R;
		break;
		case UART5:
		while(UART5_FR_R & UART_FR_RXFE);
		/**< Receive byte */
		*copy_pu8ReceivedData = UART5_DR_R;
		break;
		case UART6:
		while(UART6_FR_R & UART_FR_RXFE);
		/**< Receive byte */
		*copy_pu8ReceivedData = UART6_DR_R;
		break;
		case UART7:
		while(UART7_FR_R & UART_FR_RXFE);
		/**< Receive byte */
		*copy_pu8ReceivedData = UART7_DR_R;
		break;
		default : /**< ERROR_STATE */ break;
	} 
}

void UART_voidSendString(u8 copy_u8UARTNo,u8 *copy_pu8SentString)
{
    while(*copy_pu8SentString != '\0')
    {
        UART_voidSendByte(copy_u8UARTNo,*copy_pu8SentString);
        copy_pu8SentString++;
    }
}

void UART_voidReceiveString(u8 copy_u8UARTNo,u8 *copy_pu8Buffer)
{
    u32 i = 0;
    UART_voidReceiveByte(copy_u8UARTNo,&copy_pu8Buffer[i]);
    if(copy_pu8Buffer[i] >= '0')
    {
        while(copy_pu8Buffer[i] != 0x0A)
            {
                i++;
                UART_voidReceiveByte(copy_u8UARTNo,&copy_pu8Buffer[i]);
            }
    }
    else
    {
        copy_pu8Buffer[i-1] = 0;
        copy_pu8Buffer[i] = 0;
        i--;
    }
    copy_pu8Buffer[i] = '\0';

}



