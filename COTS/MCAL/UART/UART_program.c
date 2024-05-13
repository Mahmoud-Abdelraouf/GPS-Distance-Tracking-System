/**************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********/
/********** Date    : 14/04/2023              	    ***********/
/********** SWC     : MCAL_UART                     ***********/
/********** Version : 1.0                    		***********/
/**************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
/**< MCAL_UART */
#include "UART_private.h"
#include "UART_interface.h"
#include "UART_config.h"

void UART_Init(u8 UARTNo, u32 BaudRate, u8 DataBits, u8 Parity, u8 StopBits)
{
	f32 Local_Divisor = UART_CLOCK / (BaudRate * 16.0);
	f32 Local_FractionalDivider = Local_Divisor-(u32)(Local_Divisor);

	switch(UARTNo)
	{
		case UART0:
		/**< Enable UART clock */ 
		SET_BIT(SYSCTL_RCGCUART_R, UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R, UART_PORTA);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R, UART_PORTA));
		/**< Configure UART pins */
		GPIO_PORTA_AFSEL_R |= GPIO_PA0_U0RX | GPIO_PA1_U0TX; 			/**< Set the PA0 and PA1 to operate in alternative mode */
		GPIO_PORTA_PCTL_R  |= GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX;  /**< Select the alternative mode to be UART */
		GPIO_PORTA_DIR_R   |= GPIO_PA1_U0TX;							/**< TX OUTPUT */
		GPIO_PORTA_DIR_R   &=~ GPIO_PA0_U0RX;                       	/**< RX INPUT */			
		GPIO_PORTA_DEN_R   |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;
		/**< Disable UART */ 
		UART0_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART0_IBRD_R = (u32)Local_Divisor;
		UART0_FBRD_R = (u32)((Local_FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART0_LCRH_R = (DataBits - 5) << UART_LCRH_WLEN_S;
		if(Parity == UART_PARITY_NONE)
		{
			UART0_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(Parity == UART_PARITY_ODD)
		{
			UART0_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}
		else if(Parity == UART_PARITY_EVEN)
		{
			UART0_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}
		/**< Configure stop bits */ 
		if(StopBits == 1)
		{
			UART0_LCRH_R &=~UART_LCRH_STP2;
		}   
		else if(StopBits == 2)
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
		SET_BIT(SYSCTL_RCGCUART_R, UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R, UART_PORTB);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R, UART_PORTB));
		/**< Configure UART pins */
		GPIO_PORTB_AFSEL_R |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;
		GPIO_PORTB_PCTL_R  |= GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX;
		GPIO_PORTB_DIR_R   |= GPIO_PB1_U1TX;
		GPIO_PORTB_DIR_R   &=~ GPIO_PB0_U1RX;
		GPIO_PORTB_DEN_R   |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;
		/**< Disable UART */ 
		UART1_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART1_IBRD_R = (u32)Local_Divisor;
		UART1_FBRD_R = (u32)((Local_FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART1_LCRH_R = (DataBits - 5) << UART_LCRH_WLEN_S;
		if(Parity == UART_PARITY_NONE)
		{
			UART1_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(Parity == UART_PARITY_ODD)
		{
			UART1_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}
		else if(Parity == UART_PARITY_EVEN)
		{
			UART1_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}
		/**< Configure stop bits */ 
		if(StopBits == 1)
		{
			UART1_LCRH_R &=~UART_LCRH_STP2;
		}
		else if(StopBits == 2)
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
		SET_BIT(SYSCTL_RCGCUART_R, UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R, UART_PORTD);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R, UART_PORTD));
		/**< Configure UART pins */
		GPIO_PORTD_AFSEL_R |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;
		GPIO_PORTD_PCTL_R  |= GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX;
		GPIO_PORTD_DIR_R   |= GPIO_PD7_U2TX;						/**< TX OUTPUT */
		GPIO_PORTD_DIR_R   &=~ GPIO_PD6_U2RX;   					/**< RX INPUT */              
		GPIO_PORTD_DEN_R   |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;
		/**< Disable UART */ 
		UART2_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART2_IBRD_R = (u32)Local_Divisor;
		UART2_FBRD_R = (u32)((Local_FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART2_LCRH_R = (DataBits - 5) << UART_LCRH_WLEN_S;
		if(Parity == UART_PARITY_NONE)
		{
			UART2_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}	
		else if(Parity == UART_PARITY_ODD)
		{
			UART2_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(Parity == UART_PARITY_EVEN)
		{
			UART2_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}
		else 
		{
			/**< ERROR_STATE */
		}	
		/**< Configure stop bits */ 
		if(StopBits == 1)
		{
			UART2_LCRH_R &=~UART_LCRH_STP2;
		}    
		else if(StopBits == 2)
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
		SET_BIT(SYSCTL_RCGCUART_R, UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R, UART_PORTC);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R, UART_PORTC));
		/**< Configure UART pins */
		GPIO_PORTC_AFSEL_R |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;
		GPIO_PORTC_PCTL_R  |= GPIO_PCTL_PC6_U3RX | GPIO_PCTL_PC7_U3TX;
		GPIO_PORTC_DIR_R   |= GPIO_PC7_U3TX;			/**< TX OUTPUT */
		GPIO_PORTC_DIR_R   &=~ GPIO_PC6_U3RX;   		/**< RX INPUT */			    
		GPIO_PORTC_DEN_R   |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;
		/**< Disable UART */ 
		UART3_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART3_IBRD_R = (u32)Local_Divisor;
		UART3_FBRD_R = (u32)((Local_FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART3_LCRH_R = (DataBits - 5) << UART_LCRH_WLEN_S;
		if(Parity == UART_PARITY_NONE)
		{
			UART3_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}	
		else if(Parity == UART_PARITY_ODD)
		{
			UART3_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(Parity == UART_PARITY_EVEN)
		{
			UART3_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}
		else 
		{
			/**< ERROR_STATE */
		}
		/**< Configure stop bits */ 
		if(StopBits == 1)
		{
			UART3_LCRH_R &=~UART_LCRH_STP2;
		} 
		else if(StopBits == 2)
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
		SET_BIT(SYSCTL_RCGCUART_R,UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R,UART_PORTC);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R,UART_PORTC));
		/**< Configure UART pins */
		GPIO_PORTC_AFSEL_R |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;
		GPIO_PORTC_PCTL_R  |= GPIO_PCTL_PC4_U4RX | GPIO_PCTL_PC5_U4TX;
		GPIO_PORTC_DIR_R   |= GPIO_PC5_U4TX;			/**< TX OUTPUT */
		GPIO_PORTC_DIR_R   &=~ GPIO_PC4_U4RX;           /**< RX INPUT */               
		GPIO_PORTC_DEN_R   |= GPIO_PC4_U4RX | GPIO_PC5_U4TX;
		/**< Disable UART */ 
		UART4_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART4_IBRD_R = (u32)Local_Divisor;
		UART4_FBRD_R = (u32)((Local_FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART4_LCRH_R = (DataBits - 5) << UART_LCRH_WLEN_S;
		if(Parity == UART_PARITY_NONE)
		{
			UART4_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}	
		else if(Parity == UART_PARITY_ODD)
		{
			UART4_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(Parity == UART_PARITY_EVEN)
		{
			UART4_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}	
		/**< Configure stop bits */ 
		if(StopBits == 1)
		{
			 UART4_LCRH_R &=~UART_LCRH_STP2;
		}  
		else if(StopBits == 2)
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
		SET_BIT(SYSCTL_RCGCUART_R, UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R, UART_PORTE);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R, UART_PORTE));
		/**< Configure UART pins */
		GPIO_PORTE_AFSEL_R |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;
		GPIO_PORTE_PCTL_R  |= GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX;
		GPIO_PORTE_DIR_R   |= GPIO_PE5_U5TX;				/**< TX OUTPUT */
		GPIO_PORTE_DIR_R   &=~ GPIO_PE4_U5RX;               /**< RX INPUT */	            
		GPIO_PORTE_DEN_R   |= GPIO_PE4_U5RX | GPIO_PE5_U5TX;
		/**< Disable UART */ 
		UART5_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART5_IBRD_R = (u32)Local_Divisor;
		UART5_FBRD_R = (u32)((Local_FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART5_LCRH_R = (DataBits - 5) << UART_LCRH_WLEN_S;
		if(Parity == UART_PARITY_NONE)
		{
			UART5_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(Parity == UART_PARITY_ODD)
		{
			UART5_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(Parity == UART_PARITY_EVEN)
		{
			UART5_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}	
		/**< Configure stop bits */ 
		if(StopBits == 1)
		{
			 UART5_LCRH_R &=~UART_LCRH_STP2;
		}   
		else if(StopBits == 2)
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
		SET_BIT(SYSCTL_RCGCUART_R, UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R, UART_PORTD);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R, UART_PORTD));
		/**< Configure UART pins */
		GPIO_PORTD_AFSEL_R |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;
		GPIO_PORTD_PCTL_R  |= GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX;
		GPIO_PORTD_DIR_R   |= GPIO_PD5_U6TX;				/**< TX OUTPUT */
		GPIO_PORTD_DIR_R   &=~ GPIO_PD4_U6RX;               /**< RX INPUT */              
		GPIO_PORTD_DEN_R   |= GPIO_PD4_U6RX | GPIO_PD5_U6TX;
		/**< Disable UART */ 
		UART6_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART6_IBRD_R = (u32)Local_Divisor;
		UART6_FBRD_R = (u32)((Local_FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART6_LCRH_R = (DataBits - 5) << UART_LCRH_WLEN_S;
		if(Parity == UART_PARITY_NONE)
		{
			UART6_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(Parity == UART_PARITY_ODD)
		{
			UART6_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(Parity == UART_PARITY_EVEN)
		{
			UART6_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}
		/**< Configure stop bits */ 
		if(StopBits == 1)
		{
			 UART6_LCRH_R &=~UART_LCRH_STP2;
		}  
		else if(StopBits == 2)
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
		SET_BIT(SYSCTL_RCGCUART_R, UARTNo);
		/**< Enable GPIO clock for UART pins */
		SET_BIT(SYSCTL_RCGCGPIO_R, UART_PORTE);
		/** Wait for clock stabilization */ 
		while(!GET_BIT(SYSCTL_PRGPIO_R, UART_PORTE));
		/**< Configure UART pins */
		GPIO_PORTE_AFSEL_R |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;
		GPIO_PORTE_PCTL_R  |= GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX;
		GPIO_PORTE_DIR_R   |= GPIO_PA1_U0TX;				/**< TX OUTPUT */
		GPIO_PORTE_DIR_R   &=~ GPIO_PA0_U0RX;               /**< RX INPUT */		        
		GPIO_PORTE_DEN_R   |= GPIO_PE0_U7RX | GPIO_PE1_U7TX;
		/**< Disable UART */ 
		UART7_CTL_R &= ~UART_CTL_UARTEN;
		/**< Configure baud rate */
		UART7_IBRD_R = (u32)Local_Divisor;
		UART7_FBRD_R = (u32)((Local_FractionalDivider*64)+0.5);
		/**< Configure data format */
		UART7_LCRH_R = (DataBits - 5) << UART_LCRH_WLEN_S;
		if(Parity == UART_PARITY_NONE)
		{
			UART7_LCRH_R &= ~(UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS);
		}
		else if(Parity == UART_PARITY_ODD)
		{
			UART7_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS;
		}	
		else if(Parity == UART_PARITY_EVEN)
		{
			UART7_LCRH_R |= UART_LCRH_PEN | UART_LCRH_EPS | UART_LCRH_SPS;
		}	
		else 
		{
			/**< ERROR_STATE */
		}	
		/**< Configure stop bits */ 
		if(StopBits == 1)
		{
			UART7_LCRH_R &=~UART_LCRH_STP2;
		}
		else if(StopBits == 2)
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

void UART_SendByte(u8 UARTNo, u8 Data)
{
	switch(UARTNo)
	{
		case UART0:
			while(UART0_FR_R & UART_FR_TXFF);
			UART0_DR_R = Data;
			break;
		case UART1:
			while(UART1_FR_R & UART_FR_TXFF);
			UART1_DR_R = Data;
			break;
		case UART2:
		while(UART2_FR_R & UART_FR_TXFF);
			UART2_DR_R = Data;
			break;
		case UART3:
		while(UART3_FR_R & UART_FR_TXFF);
			UART3_DR_R = Data;
			break;
		case UART4:
		while(UART4_FR_R & UART_FR_TXFF);
			UART4_DR_R = Data;
			break;
		case UART5:
		while(UART5_FR_R & UART_FR_TXFF);
			UART5_DR_R = Data;
			break;
		case UART6:
		while(UART6_FR_R & UART_FR_TXFF);
			UART6_DR_R = Data;
			break;
		case UART7:
		while(UART7_FR_R & UART_FR_TXFF);
			UART7_DR_R = Data;
			break;
		default : /**< ERROR_STATE */ break;
	}
}

void UART_ReceiveByte(u8 UARTNo,u8 *ReceivedData)
{
	switch(UARTNo)
	{
		case UART0:
			while(UART0_FR_R & UART_FR_RXFE);
			*ReceivedData = UART0_DR_R;
			break;
		case UART1:
			while(UART1_FR_R & UART_FR_RXFE);
			*ReceivedData = UART1_DR_R;
			break;
		case UART2:
			while(UART2_FR_R & UART_FR_RXFE);
			*ReceivedData = UART2_DR_R;
			break;
		case UART3:
			while(UART3_FR_R & UART_FR_RXFE);
			*ReceivedData = UART3_DR_R;
			break;
		case UART4:
			while(UART4_FR_R & UART_FR_RXFE);
			*ReceivedData = UART4_DR_R;
			break;
		case UART5:
			while(UART5_FR_R & UART_FR_RXFE);
			*ReceivedData = UART5_DR_R;
			break;
		case UART6:
			while(UART6_FR_R & UART_FR_RXFE);
			*ReceivedData = UART6_DR_R;
			break;
		case UART7:
			while(UART7_FR_R & UART_FR_RXFE);
			*ReceivedData = UART7_DR_R;
			break;
		default : /**< ERROR_STATE */ break;
	} 
}
 
void UART_SendString(u8 UARTNo,u8 *SentString)
{
    while(*SentString != '\0')
    {
        UART_SendByte(UARTNo,*SentString);
        SentString++;
    }
}

void UART_ReceiveString(u8 UARTNo, u8 *Buffer)
{
    u32 i = 0;

    UART_ReceiveByte(UARTNo, &Buffer[i]);
    if(Buffer[i] >= '0')
    {
        while(Buffer[i] != 0x0A)
		{
			i++;
			UART_ReceiveByte(UARTNo, &Buffer[i]);
		}
    }
    else
    {
        Buffer[i-1] = 0;
        Buffer[i] = 0;
        i--;
    }

    Buffer[i] = '\0';
}



