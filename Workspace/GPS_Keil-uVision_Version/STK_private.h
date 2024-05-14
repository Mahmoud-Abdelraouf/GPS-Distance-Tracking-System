/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 14 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STK_private.h              *****************/
/****************************************************************/
#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

/**
 * @brief Maximum Reload Value for SysTick Timer
 *
 * This macro defines the maximum valid reload value that can be used for configuring
 * the SysTick timer's period. The SysTick timer is a down-counter that generates interrupts
 * or overflows at regular intervals based on its reload value.
 *
 * @note The actual time duration between interrupts or overflows depends on the system clock
 *       frequency and the value set using this macro.
 *
 * @warning Setting a reload value greater than this maximum may result in undefined behavior.
 *
 * @see MCAL_STK_SetReloadValue
 */
#define STK_RELOAD_MAX  0x00FFFFFF

/*****************************< Register Definitions *****************************/
#define STK_BASE_ADDRESS                 0xE000E010U    

typedef struct STK_RegDef_t { 
  volatile u32 CTRL;
  volatile u32 LOAD;
  volatile u32 VAL;
  volatile u32 CALIB;
} STK_RegDef_t;

#define STK           ((STK_RegDef_t *)STK_BASE_ADDRESS)

/*****************************< The following are defines for the bit fields in the STK_CTRL register. *****************************/
#define STK_CTRL_ENABLE_MASK             0x00000001      /**< Bit 0 : Counter Enable */
#define STK_CTRL_TICKINT_MASK            0x00000002      /**< Bit 1 : Interrupt Enable */
#define STK_CTRL_CLKSOURCE_MASK          0x00000004      /**< Bit 2 : Clock Source */
#define STK_CTRL_COUNTFLAG_MASK          0x00010000      /**< Bit 16: Count Flag */

/**
 * @brief Specifies the clock source for the SysTick timer.
 *
 * This option determines whether the SysTick timer uses the processor clock or
 * an external clock source.
 *
 * @param STK_CTRL_CLKSOURCE_DIV_1 Clock source is the processor clock.
 * @param STK_CTRL_CLKSOURCE_DIV_8 Clock source is the processor clock divided by 8.
 *
 * @retval None
 */
#define STK_CTRL_CLKSOURCE_DIV_1             1
#define STK_CTRL_CLKSOURCE_DIV_4             0

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
#define STK_CTRL_TICKINT_ENABLE             1
#define STK_CTRL_TICKINT_DISABLE            0

/**
 * @brief Specifies the operation mode of the SysTick timer interval.
 *
 * The SysTick timer can operate in two modes: single-shot interval and periodic interval.
 * - "STK_SINGLE_INTERVAL": Indicates that the SysTick timer operates in single-shot mode.
 *   In this mode, the timer generates an interrupt only once after the specified interval
 *   and then stops until reconfigured.
 *
 * - "STK_PERIOD_INTERVAL": Indicates that the SysTick timer operates in periodic mode.
 *   In this mode, the timer generates interrupts at regular intervals specified by the
 *   reload value, and it continues operating until explicitly disabled.
 *
 * These macros are used to configure the behavior of the SysTick timer interval, providing
 * control over whether the timer generates interrupts once (single-shot) or repeatedly
 * (periodic) at the specified interval.
 *
 * @note Choose the appropriate mode based on your application's timing requirements.
 *
 * @see MCAL_STK_SetIntervalSingle
 * @see MCAL_STK_SetIntervalPeriodic
 */
#define STK_SINGLE_INTERVAL              0
#define STK_PERIOD_INTERVAL              1

/**
 * @brief Sets the system clock frequency for the SysTick peripheral.
 *
 * This function sets the system clock frequency for the SysTick peripheral. It does not allow changes to the values defined by the STK_CTRL_CLKSOURCE constant.
 *
 * @note
 * The available options for STK_CTRL_CLKSOURCE are:
 * - STK_CTRL_CLKSOURCE_1: Processor clock (AHB clock) divided by 1
 * - STK_CTRL_CLKSOURCE_8: Processor clock (AHB clock) divided by 8
 *
 * @retval None
 */
#if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_DIV_1
    #define STK_AHB_CLK       8000000   /**< Processor clock (AHB clock) divided by 1 */
#elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_DIV_4
    #define STK_AHB_CLK       4000000   /**< Processor clock (AHB clock) divided by 8 */
#else
    #error "You chose a wrong clock source for the SysTick"
#endif




#endif /**< STK_PRIVATE_H_ */