//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 25/04/2023              	*************
//********** SWC     : HAL_LCD                  *************
//********** Version : 1.0                    	*************
//***********************************************************
#ifndef __HAL_LCD_INTERFACE_H__
#define __HAL_LCD_INTERFACE_H__

/** \brief
 *
 * \param
 * \return
 *
 */

void LCD_voidInit(void);
/** \brief
 *
 * \param
 * \return
 *
 */

void LCD_voidSendCommand(u8 copy_u8Command);

/** \brief
 *
 * \param
 * \return
 *
 */

void LCD_voidSendChar(u8 copy_u8Char);

/** \brief
 *
 * \param
 * \return
 *
 */

void LCD_voidSendString(u8 *copy_pu8String);

/** \brief
 *
 * \param
 * \return
 *
 */

void LCD_voidSendNumber(f64 copy_f64Number);

/** \brief
 *
 * \param
 * \return
 *
 */
void LCD_voidClear(void);

/** \brief
 *
 * \param
 * \return
 *
 */
void LCD_voidGoToXYPos(u8 copy_u8XPos,u8 copy_u8YPos);



#endif // __HAL_LCD_INTERFACE_H__
