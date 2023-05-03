// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_3			***********
// ********** Date    : 14/04/2023              	***********
// ********** SWC     : MCAL_DIO                    ***********
// ********** Version : 1.0                    		***********
// ************************************************************
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
// Macros for PINS value
//
//*****************************************************************************
#define DIO_u8_OUTPUT			1
#define DIO_u8_INPUT			0
#define DIO_u8_HIGH				1
#define DIO_u8_LOW				0
//*****************************************************************************
//
// Macros for PINS of PORT A
//
//*****************************************************************************
#define PA0_PIN         17
#define PA1_PIN         18
#define PA2_PIN         19
#define PA3_PIN         20
#define PA4_PIN         21
#define PA5_PIN         22
#define PA6_PIN         23
#define PA7_PIN         24
//*****************************************************************************
//
// Macros for PINS of PORT B
//
//*****************************************************************************
#define PB0_PIN         45
#define PB1_PIN         46
#define PB2_PIN         47
#define PB3_PIN         48
#define PB4_PIN         58
#define PB5_PIN         57
#define PB6_PIN         1
#define PB7_PIN         4
//*****************************************************************************
//
// Macros for PINS of PORT C
//
//*****************************************************************************
#define PC0_PIN         52
#define PC1_PIN         51
#define PC2_PIN         50
#define PC3_PIN         49
#define PC4_PIN         16
#define PC5_PIN         15
#define PC6_PIN         14
#define PC7_PIN         13
//*****************************************************************************
//
// Macros for PINS of PORT D
//
//*****************************************************************************
#define PD0_PIN         61
#define PD1_PIN         62
#define PD2_PIN         63
#define PD3_PIN         64
#define PD4_PIN         43
#define PD5_PIN         44
#define PD6_PIN         53
#define PD7_PIN         10
//*****************************************************************************
//
// Macros for PINS of PORT E
//
//*****************************************************************************
#define PE0_PIN         9
#define PE1_PIN         8
#define PE2_PIN         7
#define PE3_PIN         6
#define PE4_PIN         59
#define PE5_PIN         60
//*****************************************************************************
//
// Macros for PINS of PORT F
//
//*****************************************************************************
#define PF0_PIN         28
#define PF1_PIN         29
#define PF2_PIN         30
#define PF3_PIN         31
#define PF4_PIN         5
//*****************************************************************************
//*****************************************************************************
//
// the functions of the DIO driver
//
//*****************************************************************************
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 
u8 DIO_voidInit(u8 copy_u8PortId);
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 
u8 DIO_u8SetPinDirection (u8 copy_u8PortId, u8 copy_u8PinId,u8 copy_u8PinDirection);
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 												  
u8 DIO_u8SetPinValue     (u8 copy_u8PortId, u8 copy_u8PinId,u8 copy_u8PinValue);
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 											  
u8 DIO_u8GetPinValue     (u8 copy_u8PortId, u8 copy_u8PinId,u32 *copy_pu8ReturnedPinValue);
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 												  
u8 DIO_u8SetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection);
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 											  
u8 DIO_u8SetPortValue    (u8 copy_u8PortId, u8 copy_u8PortValue);
/** \brief 	
 *			
 * \param 	
 * \return 	
 *
 */ 								
u8 DIO_u8GetPortValue    (u8 copy_u8PortId, u32 *copy_u8ReturnedPortValue);
/** \brief
 *
 * \param
 * \return
 *
 */
u8 DIO_u8TogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId);
//*****************************************************************************




#endif/* __MCAL_DIO_INTERFACE_C_H__ */

