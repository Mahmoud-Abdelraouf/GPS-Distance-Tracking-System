// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********
// ********** Date    : 5/05/2023              	***********
// ********** SWC     : MCAL_UART                   ***********
// ********** Version : 1.0                    		***********
// ************************************************************
#ifndef __MCAL_UART_INTERFACE_H__
#define __MCAL_UART_INTERFACE_H__

/** \brief
 *
 * \param
 * \return
 *
 */
void UART5_Init(void);
/** \brief
 *
 * \param
 * \return
 *
 */
void UART_voidSendByte(u8 copy_cu8Data);
/** \brief
 *
 * \param
 * \return
 *
 */
u8 UART_u8RecieveByte(void);
/** \brief
 *
 * \param
 * \return
 *
 */
void UART_voidSendString(const u8 *copy_pu8String);
/** \brief
 *
 * \param
 * \return
 *
 */
void UART_voidReceiveString(u8 *copy_pu8String);


#endif // __MCAL_UART_INTERFACE_H__
