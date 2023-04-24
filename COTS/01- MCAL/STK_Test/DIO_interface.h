// **********************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_3				***********
// ********** Date    : 14/04/2023              	***********
// ********** SWC     : DIO                     	***********
// ********** Version : 1.0                    		***********
// **********************************************************
#ifndef __MCAL_DIO_INTERFACE_C_H__
#define __MCAL_DIO_INTERFACE_C_H__


//*****************************************************************************
//
// Macros for PORTS
//
//*****************************************************************************
#define DIO_u8_PORTA			0
#define DIO_u8_PORTB			1
#define DIO_u8_PORTC			2
#define DIO_u8_PORTD			3
#define DIO_u8_PORTE			4
#define DIO_u8_PORTF			5

//*****************************************************************************
//
// Macros for PINS
//
//*****************************************************************************
#define DIO_u8_PIN0 			0
#define DIO_u8_PIN1				1
#define DIO_u8_PIN2				2
#define DIO_u8_PIN3				3
#define DIO_u8_PIN4				4
#define DIO_u8_PIN5				5
#define DIO_u8_PIN6				6
#define DIO_u8_PIN7				7
//*****************************************************************************
//
// Macros for pin value
//
//*****************************************************************************
#define DIO_u8_OUTPUT			1
#define DIO_u8_INPUT			0
#define DIO_u8_HIGH				1
#define DIO_u8_LOW				0

//*****************************************************************************
//
// the functions of the DIO driver
//
//*****************************************************************************
u8 DIO_voidInit(u8 copy_u8PortId);

u8 DIO_u8SetPinDirection (u8 copy_u8PortId, u8 copy_u8PinId,u8 copy_u8PinDirection);
													  
u8 DIO_u8SetPinValue     (u8 copy_u8PortId, u8 copy_u8PinId,u8 copy_u8PinValue);
												  
u8 DIO_u8GetPinValue     (u8 copy_u8PortId, u8 copy_u8PinId,u32 *copy_pu8ReturnedPinValue);
												  
u8 DIO_u8SetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection);
												  
u8 DIO_u8SetPortValue    (u8 copy_u8PortId, u8 copy_u8PortValue);
									
u8 DIO_u8GetPortValue    (u8 copy_u8PortId, u32 *copy_u8ReturnedPortValue);




#endif/* __MCAL_DIO_INTERFACE_C_H__ */

