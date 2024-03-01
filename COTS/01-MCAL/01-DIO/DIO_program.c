/**************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********/
/********** Date    : 14/04/2023              	    ***********/
/********** SWC     : MCAL_DIO                  	***********/
/********** Version : 1.0                    		***********/
/**************************************************************/
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
/**< MCAL_DIO */
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"



u8 DIO_voidInit(u8 copy_u8PortId)
{	
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(copy_u8PortId>=DIO_u8_PORTA&&copy_u8PortId<=DIO_u8_PORTF)
	{
		SET_BIT(SYSCTL_RCGCGPIO_R,copy_u8PortId); 						// To enable a clock and active PORT A
		while(!GET_BIT(SYSCTL_PRGPIO_R,copy_u8PortId)); 			// Wait till the Clock be stable
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
				GPIO_PORTA_LOCK_R  = GPIO_LOCK_KEY; 							// Unlocks the GPIOCR register so we can allow the commit
				GPIO_PORTA_CR_R    = GPIO_ENABLE_7_BIT;						// Allow changes to PA7-0 
				GPIO_PORTA_AFSEL_R = 0x00;												// Disable analog functions
				GPIO_PORTA_PCTL_R  = GPIO_PCTL_VALUE; 						// GPIO_PCTL_VALUE-->To make all the pins in PORT A work as DIO 
				GPIO_PORTA_DEN_R   = 0xFF;												// to enable the pin PA0-PA7 as digital 
			break;
			case DIO_u8_PORTB:
				GPIO_PORTB_LOCK_R  = GPIO_LOCK_KEY; 							// Unlocks the GPIOCR register so we can allow the commit
				GPIO_PORTB_CR_R    = GPIO_ENABLE_7_BIT;						// Allow changes to PA7-0 
				GPIO_PORTB_AFSEL_R = 0x00;												// Disable the alternative functions
				GPIO_PORTB_PCTL_R  = GPIO_PCTL_VALUE; 						// GPIO_PCTL_VALUE-->To make all the pins in PORT B work as DIO 
				GPIO_PORTB_DEN_R   = 0xFF;												// to enable the pin PB0-PB7 as digital 
			break;
			case DIO_u8_PORTC:
				GPIO_PORTC_LOCK_R  = GPIO_LOCK_KEY; 							// Unlocks the GPIOCR register so we can allow the commit
				GPIO_PORTC_CR_R    = GPIO_ENABLE_7_BIT;						// Allow changes to PA7-0 
				GPIO_PORTC_AFSEL_R = 0x00;												// Disable the alternative functions
				GPIO_PORTC_PCTL_R  = GPIO_PCTL_VALUE; 						// GPIO_PCTL_VALUE-->To make all the pins in PORT C work as DIO  
				GPIO_PORTC_DEN_R   = 0xFF;												// to enable the pin PB0-PB7 as digital 
			break;
			case DIO_u8_PORTD:
				GPIO_PORTD_LOCK_R  = GPIO_LOCK_KEY; 							// Unlocks the GPIOCR register so we can allow the commit
				GPIO_PORTD_CR_R    = GPIO_ENABLE_7_BIT;						// Allow changes to PA7-0 
				GPIO_PORTD_AFSEL_R = 0x00;												// Disable the alternative functions
				GPIO_PORTD_PCTL_R  = GPIO_PCTL_VALUE; 						// GPIO_PCTL_VALUE-->To make all the pins in PORT D work as DIO
				GPIO_PORTD_DEN_R   = 0xFF;												// to enable the pin PD0-PD7 as digital 
			break;
			case DIO_u8_PORTE:
				GPIO_PORTE_LOCK_R  = GPIO_LOCK_KEY; 							// Unlocks the GPIOCR register so we can allow the commit
				GPIO_PORTE_CR_R    = GPIO_ENABLE_7_BIT;						// Allow changes to PA7-0 
				GPIO_PORTE_AFSEL_R = 0x00;												// Disable the alternative functions
				GPIO_PORTE_PCTL_R  = GPIO_PCTL_VALUE; 						// GPIO_PCTL_VALUE-->To make all the pins in PORT E work as DIO 
				GPIO_PORTE_DEN_R   = 0xFF;												// to enable the pin PE0-PE7 as digital 
			break;
			case DIO_u8_PORTF:
				GPIO_PORTF_LOCK_R  = GPIO_LOCK_KEY; 							// Unlocks the GPIOCR register so we can allow the commit
				GPIO_PORTF_CR_R    = GPIO_ENABLE_7_BIT;						// Allow changes to PA7-0 
				GPIO_PORTF_AFSEL_R = 0x00;												// Disable the alternative functions
				GPIO_PORTF_PCTL_R  = GPIO_PCTL_VALUE; 						// GPIO_PCTL_VALUE-->To make all the pins in PORT F work as DIO 
				GPIO_PORTF_DEN_R   = 0xFF;												// to enable the pin PB0-PB7 as digital 
			break;
			default 		  : Local_u8ErrorState = STD_TYPES_NOK; 
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}




u8 DIO_u8SetPinDirection (u8 copy_u8PortId, u8 copy_u8PinId,u8 copy_u8PinDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId<=DIO_u8_PORTF&&copy_u8PortId>=DIO_u8_PORTA)&&(copy_u8PinId<=DIO_u8_PIN7&&DIO_u8_PIN7>=DIO_u8_PIN0)&&(copy_u8PinDirection==DIO_u8_INPUT||copy_u8PinDirection==DIO_u8_OUTPUT))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
				switch(copy_u8PinDirection)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(GPIO_PORTA_DIR_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_INPUT:
						CLR_BIT(GPIO_PORTA_DIR_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			break;
			case DIO_u8_PORTB:
				switch(copy_u8PinDirection)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(GPIO_PORTB_DIR_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_INPUT:
						CLR_BIT(GPIO_PORTB_DIR_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			break;
			case DIO_u8_PORTC:
				switch(copy_u8PinDirection)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(GPIO_PORTC_DIR_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_INPUT:
						CLR_BIT(GPIO_PORTC_DIR_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			break;
			case DIO_u8_PORTD:	
				switch(copy_u8PinDirection)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(GPIO_PORTD_DIR_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_INPUT:
						CLR_BIT(GPIO_PORTD_DIR_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			break;
			case DIO_u8_PORTE:
			    if(copy_u8PinId<=DIO_u8_PIN4)
			    {
			        switch(copy_u8PinDirection)
                    {
                        case DIO_u8_OUTPUT:
                            SET_BIT(GPIO_PORTE_DIR_R,copy_u8PinId);     // Set the direction of pin to be output
                        break;
                        case DIO_u8_INPUT:
                            CLR_BIT(GPIO_PORTE_DIR_R,copy_u8PinId);     // Set the direction of pin to be input
                        break;
                    }
			    }
			    else
			    {
			        Local_u8ErrorState = STD_TYPES_NOK;
			    }
			break;
			case DIO_u8_PORTF:
			    if(copy_u8PinId<=DIO_u8_PIN4)
			    {
			        switch(copy_u8PinDirection)
                    {
                        case DIO_u8_OUTPUT:
                            SET_BIT(GPIO_PORTF_DIR_R,copy_u8PinId);     // Set the direction of pin to be output
                        break;
                        case DIO_u8_LOW:
                            CLR_BIT(GPIO_PORTF_DIR_R,copy_u8PinId);     // Set the direction of pin to be input
                        break;
                    }
			    }
			    else
			    {
			        Local_u8ErrorState = STD_TYPES_NOK;
			    }
			break;
			default:Local_u8ErrorState = STD_TYPES_NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
													  
u8 DIO_u8SetPinValue     (u8 copy_u8PortId, u8 copy_u8PinId,u8 copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId<=DIO_u8_PORTF&&copy_u8PortId>=DIO_u8_PORTA)&&(copy_u8PinId<=DIO_u8_PIN7&&DIO_u8_PIN7>=DIO_u8_PIN0)&&(copy_u8PinValue==DIO_u8_HIGH||copy_u8PinValue==DIO_u8_LOW))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
				switch(copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SET_BIT(GPIO_PORTA_DATA_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_LOW:
						CLR_BIT(GPIO_PORTA_DATA_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			break;
			case DIO_u8_PORTB:
				switch(copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SET_BIT(GPIO_PORTB_DATA_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_LOW:
						CLR_BIT(GPIO_PORTB_DATA_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			break;
			case DIO_u8_PORTC:
				switch(copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SET_BIT(GPIO_PORTC_DATA_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_LOW:
						CLR_BIT(GPIO_PORTC_DATA_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			break;
			case DIO_u8_PORTD:
				switch(copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SET_BIT(GPIO_PORTD_DATA_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_LOW:
						CLR_BIT(GPIO_PORTD_DATA_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			break;
			case DIO_u8_PORTE:
			if(copy_u8PinId<=DIO_u8_PIN4)
			{
				switch(copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SET_BIT(GPIO_PORTE_DATA_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_LOW:
						CLR_BIT(GPIO_PORTE_DATA_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			}
			else
			{
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
			case DIO_u8_PORTF:
			if(copy_u8PinId<=DIO_u8_PIN4)
			{
				switch(copy_u8PinValue)
				{
					case DIO_u8_HIGH:
						SET_BIT(GPIO_PORTF_DATA_R,copy_u8PinId);		// Set the direction of pin to be output
					break;
					case DIO_u8_LOW:
						CLR_BIT(GPIO_PORTF_DATA_R,copy_u8PinId);		// Set the direction of pin to be input
					break;
				}
			}
			else
			{
				Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
			default:Local_u8ErrorState = STD_TYPES_NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
													  
u8 DIO_u8GetPinValue     (u8 copy_u8PortId, u8 copy_u8PinId,u32 *copy_pu8ReturnedPinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((copy_pu8ReturnedPinValue != NULL)&&(copy_u8PortId<=DIO_u8_PORTF&&copy_u8PortId>=DIO_u8_PORTA)&&(copy_u8PinId>=DIO_u8_PIN0&&copy_u8PinId<=DIO_u8_PIN7))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:*copy_pu8ReturnedPinValue = GET_BIT(GPIO_PORTA_DATA_R,copy_u8PinId);
			switch(*copy_pu8ReturnedPinValue)
			{
				case DIO_u8_HIGH: *copy_pu8ReturnedPinValue = DIO_u8_HIGH;break;
				case DIO_u8_LOW : *copy_pu8ReturnedPinValue = DIO_u8_LOW;break;
				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
			case DIO_u8_PORTB:*copy_pu8ReturnedPinValue = GET_BIT(GPIO_PORTB_DATA_R,copy_u8PinId);
			switch(*copy_pu8ReturnedPinValue)
			{
				case DIO_u8_HIGH: *copy_pu8ReturnedPinValue = DIO_u8_HIGH;break;
				case DIO_u8_LOW : *copy_pu8ReturnedPinValue = DIO_u8_LOW;break;
				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
			case DIO_u8_PORTC:*copy_pu8ReturnedPinValue = GET_BIT(GPIO_PORTC_DATA_R,copy_u8PinId);
			switch(*copy_pu8ReturnedPinValue)
			{
				case DIO_u8_HIGH: *copy_pu8ReturnedPinValue = DIO_u8_HIGH;break;
				case DIO_u8_LOW : *copy_pu8ReturnedPinValue = DIO_u8_LOW;break;
				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
			case DIO_u8_PORTD:*copy_pu8ReturnedPinValue = GET_BIT(GPIO_PORTD_DATA_R,copy_u8PinId);
			switch(*copy_pu8ReturnedPinValue)
			{
				case DIO_u8_HIGH: *copy_pu8ReturnedPinValue = DIO_u8_HIGH;break;
				case DIO_u8_LOW : *copy_pu8ReturnedPinValue = DIO_u8_LOW;break;
				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
			case DIO_u8_PORTE:*copy_pu8ReturnedPinValue = GET_BIT(GPIO_PORTE_DATA_R,copy_u8PinId);
			switch(*copy_pu8ReturnedPinValue)
			{
				case DIO_u8_HIGH: *copy_pu8ReturnedPinValue = DIO_u8_HIGH;break;
				case DIO_u8_LOW : *copy_pu8ReturnedPinValue = DIO_u8_LOW;break;
				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
			case DIO_u8_PORTF:*copy_pu8ReturnedPinValue = GET_BIT(GPIO_PORTF_DATA_R,copy_u8PinId);
			switch(*copy_pu8ReturnedPinValue)
			{
				case DIO_u8_HIGH: *copy_pu8ReturnedPinValue = DIO_u8_HIGH;break;
				case DIO_u8_LOW : *copy_pu8ReturnedPinValue = DIO_u8_LOW;break;
				default:Local_u8ErrorState = STD_TYPES_NOK;
			}
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
													  
u8 DIO_u8SetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId>=DIO_u8_PORTA&&copy_u8PortId<=DIO_u8_PORTF)&&(copy_u8PortDirection==DIO_u8_OUTPUT||copy_u8PortDirection==DIO_u8_INPUT))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA:
				switch(copy_u8PortDirection)
				{
					case DIO_u8_OUTPUT: GPIO_PORTA_DIR_R = 0XFF;break;
					case DIO_u8_INPUT : GPIO_PORTA_DIR_R = 0X00;break;
					default			  : Local_u8ErrorState = STD_TYPES_NOK;
				}
			break;
			case DIO_u8_PORTB:
				switch(copy_u8PortDirection)
				{
					case DIO_u8_OUTPUT: GPIO_PORTB_DIR_R = 0XFF;break;
					case DIO_u8_INPUT : GPIO_PORTB_DIR_R = 0X00;break;
					default			  : Local_u8ErrorState = STD_TYPES_NOK;
				}
			break;	
			case DIO_u8_PORTC:
				switch(copy_u8PortDirection)
				{
					case DIO_u8_OUTPUT: GPIO_PORTC_DIR_R = 0XFF;break;
					case DIO_u8_INPUT : GPIO_PORTC_DIR_R = 0X00;break;
					default			  : Local_u8ErrorState = STD_TYPES_NOK;
				}
			break;	
			case DIO_u8_PORTD:
				switch(copy_u8PortDirection)
				{
					case DIO_u8_OUTPUT: GPIO_PORTD_DIR_R = 0XFF;break;
					case DIO_u8_INPUT : GPIO_PORTD_DIR_R = 0X00;break;
					default			  : Local_u8ErrorState = STD_TYPES_NOK;
				}
			break;	
			case DIO_u8_PORTE:
				switch(copy_u8PortDirection)
				{
					case DIO_u8_OUTPUT: GPIO_PORTE_DIR_R = 0XFF;break;
					case DIO_u8_INPUT : GPIO_PORTE_DIR_R = 0X00;break;
					default			  : Local_u8ErrorState = STD_TYPES_NOK;
				}
			break;	
			case DIO_u8_PORTF:
				switch(copy_u8PortDirection)
				{
					case DIO_u8_OUTPUT: GPIO_PORTF_DIR_R = 0XFF;break;
					case DIO_u8_INPUT : GPIO_PORTF_DIR_R = 0X00;break;
					default			  : Local_u8ErrorState = STD_TYPES_NOK;
				}
			break;				
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
													  
u8 DIO_u8SetPortValue    (u8 copy_u8PortId, u8 copy_u8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8PortId>=DIO_u8_PORTA&&copy_u8PortId<=DIO_u8_PORTF)&&(copy_u8PortValue==DIO_u8_LOW||copy_u8PortValue==DIO_u8_HIGH))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA: GPIO_PORTA_DATA_R  = copy_u8PortValue; break;
			case DIO_u8_PORTB: GPIO_PORTB_DATA_R  = copy_u8PortValue; break;
			case DIO_u8_PORTC: GPIO_PORTC_DATA_R  = copy_u8PortValue; break;
			case DIO_u8_PORTD: GPIO_PORTD_DATA_R  = copy_u8PortValue; break;
			case DIO_u8_PORTE: GPIO_PORTE_DATA_R  = copy_u8PortValue; break;
			case DIO_u8_PORTF: GPIO_PORTF_DATA_R  = copy_u8PortValue; break;
			default 		 : Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}

									
u8 DIO_u8GetPortValue    (u8 copy_u8PortId, u32 *copy_u8ReturnedPortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((copy_u8ReturnedPortValue != NULL)&&(copy_u8PortId>=DIO_u8_PORTA&&copy_u8PortId<=DIO_u8_PORTF))
	{
		switch(copy_u8PortId)
		{
			case DIO_u8_PORTA: *copy_u8ReturnedPortValue = GPIO_PORTA_DATA_R;break;
			case DIO_u8_PORTB: *copy_u8ReturnedPortValue = GPIO_PORTB_DATA_R;break;
			case DIO_u8_PORTC: *copy_u8ReturnedPortValue = GPIO_PORTC_DATA_R;break;
			case DIO_u8_PORTD: *copy_u8ReturnedPortValue = GPIO_PORTD_DATA_R;break;
			case DIO_u8_PORTE: *copy_u8ReturnedPortValue = GPIO_PORTE_DATA_R;break;
			case DIO_u8_PORTF: *copy_u8ReturnedPortValue = GPIO_PORTF_DATA_R;break;
			default 		 : Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8TogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    if((copy_u8PortId<=DIO_u8_PORTF && copy_u8PortId>=DIO_u8_PORTA) && (copy_u8PinId<=DIO_u8_PIN7 && copy_u8PinId>=DIO_u8_PIN0))
    {
        switch(copy_u8PortId)
        {
        case DIO_u8_PORTA:
            TOG_BIT(GPIO_PORTA_DATA_R,copy_u8PinId);
            break;
        case DIO_u8_PORTB:
            TOG_BIT(GPIO_PORTB_DATA_R,copy_u8PinId);
            break;
        case DIO_u8_PORTC:
            TOG_BIT(GPIO_PORTC_DATA_R,copy_u8PinId);
            break;
        case DIO_u8_PORTD:
            TOG_BIT(GPIO_PORTD_DATA_R,copy_u8PinId);
            break;
        case DIO_u8_PORTE:
            if(copy_u8PinId<=DIO_u8_PIN4)
            {
                TOG_BIT(GPIO_PORTE_DATA_R,copy_u8PinId);
            }
            else
            {
                Local_u8ErrorState = STD_TYPES_NOK;
            }
            break;
        case DIO_u8_PORTF:
            if(copy_u8PinId<=DIO_u8_PIN4)
            {
                TOG_BIT(GPIO_PORTF_DATA_R,copy_u8PinId);
            }
            else
            {
                Local_u8ErrorState = STD_TYPES_NOK;
            }
            break;
        default :Local_u8ErrorState = STD_TYPES_NOK;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    return Local_u8ErrorState;
}

