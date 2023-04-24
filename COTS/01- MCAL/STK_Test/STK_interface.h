// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********
// ********** Date    : 21/04/2023              	***********
// ********** SWC     : STK                     	***********
// ********** Version : 1.0                    		***********
// ************************************************************
#ifndef __STK_INTERFACE_H__
#define __STK_INTERFACE_H__



/** \brief 	This function configures the SysTick timer with the specified number of ticks 
 *			and enables it with the system clock as its clock source
 * \param 	copy_u32Tick
 * \return 	void
 *
 */ 
void STK_voidConfig(u32 copy_u32Ticks);
/** \brief 	This function is the SysTick interrupt handler. 
 *			It is called when the SysTick timer reaches 0 and reloads with the value in the load register. 
 *			It can be used to implement periodic tasks or to measure time intervals
 * \param 	void
 * \return 	void
 *
 */
void STK_voidHandler(void);
/** \brief 	This function resets the SysTick timer to its initial state, 
 *			with a reload value of 0 and the count flag cleared
 * \param 	void
 * \return 	void
 *
 */
void STK_voidReset(void);
/** \brief 	This function returns the current value of the SysTick timer, 
 *			which is the number of ticks remaining before it reaches 0 and generates an interrupt
 * \param 	void
 * \return 	The current value of SysTick Timer as u32
 *
 */
u32 STK_u32GetCurrentValue(void);
/** \brief 	This function sets the reload value for the SysTick timer, 
 *			which determines the initial value of the timer when it is enabled or reloaded
 *
 * \param 	copy_u32Ticks: value you want the SysTick start count down from it
 * \return 	void
 *
 */
void STK_voidSetReloadValue(u32 copy_u32Ticks);
/** \brief 	This function enables the SysTick timer with the system clock as its clock source
 *
 * \param 	void
 * \return 	void
 *
 */
void STK_voidEnable(void);
/** \brief 	This function disables the SysTick timer
 *
 * \param 	void
 * \return 	void
 *
 */
void STK_voidDisable(void);
/** \brief 	This function enables the SysTick interrupt
 *
 * \param 	void
 * \return 	void
 *
 */
void STK_voidEnableInterrupt(void);
/** \brief 	This function disables the SysTick interrupt
 *
 * \param 	void
 * \return 	void
 *
 */
void STK_voidDisableInterrupt(void);
/** \brief 	TThis function generates a software delay of the specified duration 
 *			using the SysTick timer
 *
 * \param 	The time in millisecond you want to make the delay by it as u32 value
 * \return 	void
 *
 */
void STK_voidDelay(u32 copy_u32DelayMs);
/** \brief 	This function generates a software delay of the specified duration in 
 *			microseconds using the SysTick timer
 *
 * \param 	The time in microseconds you want to make the delay by it as u32 value
 * \return 	void
 *
 */
void STK_voidDelayUs(u32 copy_u32DelayUs);
/** \brief 	This function generates a software delay of the specified number of SysTick timer ticks
 *
 * \param 	The time in microseconds you want to make the delay by it as u32 value
 * \return 	void
 *
 */
void STK_voidDelayTicks(u32 copy_u32Ticks);










#endif
