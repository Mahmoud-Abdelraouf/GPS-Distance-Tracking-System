//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 26/04/2023              	*************
//********** SWC     : HAL_LED                  *************
//********** Version : 1.0                    	*************
//***********************************************************
#ifndef __HAL_LED_INTERFACE_H__
#define __HAL_LED_INTERFACE_H__


/********************************< MACROS for colours ********************************/
#define LED_RED  	 	1
#define LED_BLUE 		2
#define LED_GREEN	    3
/********************************< functions for LEDs *********************************/
/** \brief
 *
 * \param
 * \return
 *
 */ 
void LED_voidLedInit(u8 copy_u8LedColour);        //function to initialize a specific LED
/** \brief
 *
 * \param
 * \return
 *
 */
void LED_voidLedOn(u8 copy_u8LedColour);	      //function to turn on a specific LED	
/** \brief
 *
 * \param
 * \return
 *
 */
void LED_voidLedOff(u8 copy_u8LedColour);	      //function to turn off a specific LED
/** \brief
 *
 * \param
 * \return
 *
 */
void LED_voidLedTog(u8 copy_u8LedColour);         //function to toggle a specific LED
/** \brief
 *
 * \param
 * \return
 *
 */
void LED_voidLedBlinkOnce(u8 copy_u8LedColour);	  //function to make a specific LED	blink once
/** \brief
 *
 * \param
 * \return
 *
 */
void LED_voidLedBlinkTwice(u8 copy_u8LedColour);  //function to make a specific LED	blink twice

#endif //__HAL_LED_INTERFACE_H__
