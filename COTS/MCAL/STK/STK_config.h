/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 14 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STK_config.h               *****************/
/****************************************************************/
#ifndef STK_CONFIG_H_
#define STK_CONFIG_H_

/**
 * @brief Specifies the clock source for the SysTick timer.
 *
 * This option determines whether the SysTick timer uses the processor clock or
 * an external clock source.
 *
 * @note
 * The external clock source must be connected to the STKCLK pin on the microcontroller.
 *
 * @note
 * This option is only applicable if the SysTick timer is configured to use an
 * external clock source (STK_CLKSOURCE = STK_CLKSOURCE_EXT).
 *
 * @param STK_CTRL_CLKSOURCE_DIV_1 Clock source is the clock of STK.
 * @param STK_CTRL_CLKSOURCE_DIV_4 Clock source/8 is the clock of STK.
 *
 * @retval None
 */
#define STK_CTRL_CLKSOURCE     STK_CTRL_CLKSOURCE_DIV_4

/**
 * @brief Specifies whether the SysTick timer exception request is enabled.
 *
 * This option determines whether the SysTick timer asserts an exception request
 * when the counter reaches zero.
 *
 * @param STK_CTRL_TICKINT_ENABLE Counting down to zero asserts the SysTick exception request.
 * @param STK_CTRL_TICKINT_DISABLE Counting down to zero does not assert the SysTick exception request.
 *
 * @retval None
 */
#define STK_CTRL_TICKINT       STK_CTRL_TICKINT_DISABLE

#endif /**< STK_CONFIG_H_ */
