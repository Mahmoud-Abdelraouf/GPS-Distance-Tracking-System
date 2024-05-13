/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 14 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : STK_program.c              *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdint.h>
/*****************************< MCAL *****************************/
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
/*****************************< Global Variable Section *****************************/
static STK_CallbackFunc_t STK_Callback = NULL;
static u8 STK_ModeOfInterval;
/*****************************< Function Implementations *****************************/
/**
 * @defgroup Public_Functions STK Driver
 * @{
 */

void STK_xInit(u32 Ticks)
{
  /**< Disable SysTick timer */
  STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

  /**< Configure SysTick timer to use the processor clock */
  #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_DIV_1
      STK -> CTRL |= STK_CTRL_CLKSOURCE_MASK;             /**< Set bit 2 to use the processor clock */
  #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_DIV_4
      STK->CTRL &= ~STK_CTRL_CLKSOURCE_MASK;              /**< Clear bit 2 to use the processor clock/4 */
  #else 
      #error "Invalid STK_CTRL_CLKSOURCE value. Please choose STK_CTRL_CLKSOURCE_1 or STK_CTRL_CLKSOURCE_4."
  #endif

  /**< Generate interrupt when it reaches zero */
  #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE
      STK->CTRL |= STK_CTRL_TICKINT_MASK;      /**< Set bit 1 to enable interrupt when the counter reaches zero */
  #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE
      STK->CTRL &= ~STK_CTRL_TICKINT_MASK;     /**< Clear bit 1 to disable interrupt when the counter reaches zero */
  #else
      #error "Invalid STK_CTRL_TICKINT value. Please choose STK_CTRL_TICKINT_ENABLE or STK_CTRL_TICKINT_DISABLE."
  #endif

  /**< Load the initial value into the SysTick timer */
  STK->LOAD = Ticks;  
}

void MCAL_STK_vInit(void)
{
  /**< Disable SysTick timer */
  STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

  /**< Configure SysTick timer to use the processor clock */
  #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_DIV_1
      STK -> CTRL |= STK_CTRL_CLKSOURCE_MASK;             /**< Set bit 2 to use the processor clock */
  #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_DIV_8
      STK->CTRL &= ~STK_CTRL_CLKSOURCE_MASK;              /**< Clear bit 2 to use the processor clock/8 */
  #else 
      #error "Invalid STK_CTRL_CLKSOURCE value. Please choose STK_CTRL_CLKSOURCE_1 or STK_CTRL_CLKSOURCE_8."
  #endif

  /**< Generate interrupt when it reaches zero */
  #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE
      STK->CTRL |= STK_CTRL_TICKINT_MASK;      /**< Set bit 1 to enable interrupt when the counter reaches zero */
  #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE
      STK->CTRL &= ~STK_CTRL_TICKINT_MASK;     /**< Clear bit 1 to enable interrupt when the counter reaches zero */
  #else
      #error "Invalid STK_CTRL_TICKINT value. Please choose STK_CTRL_TICKINT_ENABLE or STK_CTRL_TICKINT_DISABLE."
  #endif  
}

Std_ReturnType STK_SetReloadValue(u32 ReloadValue)
{
  /**< Check if the reload value is within the valid range */ 
  if (ReloadValue <= STK_RELOAD_MAX) 
  {
      /**< Assign the reload value to the STK_LOAD register */ 
      STK->LOAD = ReloadValue;

      /**< Return E_OK to indicate success */ 
      return E_OK;
  } 
  else 
  {
      /**< Return E_NOT_OK to indicate failure */ 
      return E_NOT_OK;
  }
}

void STK_Start(void)
{
  /**< Enable SysTick timer */
  STK->CTRL |= STK_CTRL_ENABLE_MASK;
}

void STK_Stop(void)
{
  /**< Disable SysTick timer */
  STK->CTRL &= ~STK_CTRL_ENABLE_MASK;
}

void STK_Reset(void)
{
  /**< Disable SysTick timer */
  STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

  /**< Clear the current value */
  STK->VAL = 0;

  /**< Set the reload value to 0 */
  STK->LOAD = 0;

  /**< Clear the count flag */
  STK->CTRL &= ~STK_CTRL_COUNTFLAG_MASK;
}

u32 MCAL_STK_GetRemainingCounts(void)
{
  /* Get the current value of the SysTick timer */
  return STK->VAL;
}

u32 MCAL_STK_GetElapsedCounts(void)
{
  static u32 Local_PreviousValue = 0;  /**< Store the previous SysTick timer value */ 
  u32 Local_CurrentValue = STK->VAL;   /**< Get the current SysTick timer value */ 
  u32 Local_ElapsedTicks;

  /**< Check if the timer has wrapped around (current value is less than the previous value) */ 
  if (Local_CurrentValue < Local_PreviousValue) 
  {
    /**< Calculate elapsed ticks considering timer overflow */ 
    Local_ElapsedTicks = Local_PreviousValue - Local_CurrentValue;
  } 
  else 
  {
    /**< Calculate elapsed ticks without timer overflow */ 
    Local_ElapsedTicks = STK->LOAD - (Local_CurrentValue - Local_PreviousValue);
  }

  /**< Update the previous value for the next call */ 
  Local_PreviousValue = Local_CurrentValue;

  return Local_ElapsedTicks;
}

Std_ReturnType STK_SetDelay_us(u32 Microseconds)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  /**< Calculate the number of ticks required for the given microseconds */ 
  u32 TicksRequired = (Microseconds * (STK_AHB_CLK / 1000000));

  /**< Check if the ticks required is within the valid range */ 
  if (TicksRequired <= STK_RELOAD_MAX) 
  {
    /**< Set the reload value of the SysTick timer */ 
    STK->LOAD = TicksRequired;

    /**< Enable the SysTick timer */ 
    STK->CTRL |= STK_CTRL_ENABLE_MASK;

    /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
    while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

    /**< Disable the SysTick timer */ 
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

    /**< Reset the timer value */ 
    STK_Reset();

    Local_FunctionStatus = E_OK;
  }

  return Local_FunctionStatus;
}

Std_ReturnType STK_SetDelay_ms(f32 Milliseconds)
{
    /**< Calculate the number of ticks required to wait for the specified number of milliseconds */
    u32 Local_u32Ticks = (u32)((Milliseconds * STK_AHB_CLK) / 1000.0);

    /**< Check if TicksRequired is within the valid range */
    if (Local_u32Ticks <= STK_RELOAD_MAX)
    {
        /**< Configure SysTick timer with the calculated number of ticks */
        STK->LOAD = Local_u32Ticks;

        /**< Enable SysTick timer */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the SysTick timer reaches zero */
        while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

        /**< Disable SysTick timer */
        STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

        /**< Reset the timer value */ 
        STK_Reset();

        /**< Return success status */
        return E_OK;
    }
    else
    { 
        /**< Return error status */
        return E_NOT_OK;
    }
}

Std_ReturnType STK_SetIntervalSingle(u32 Microseconds, STK_CallbackFunc_t CallbackFunc)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
    if(CallbackFunc != NULL)
    {
    	/**< Reset the Timer */
    	STK_Reset();
    
        /* Calculate the number of ticks required to wait for the specified number of microseconds */
    	u32 TicksRequired = (Microseconds * (STK_AHB_CLK / 1000000));

        /**< Check if the ticks required is within the valid range */
        if (TicksRequired <= STK_RELOAD_MAX)
        {
        	/**< Save the callback function pointer */
			STK_Callback = CallbackFunc;

			/**< Set the Mode of interval to be single */
			STK_ModeOfInterval = STK_SINGLE_INTERVAL;

            /* Set the reload value for the SysTick timer */
            STK->LOAD = TicksRequired;

            /**< Start the SysTick timer and enable the interrupt */
            STK->CTRL |= STK_CTRL_ENABLE_MASK;
            STK->CTRL |= STK_CTRL_TICKINT_MASK;

            /**< Configured successfully */
            Local_FunctionStatus = E_OK;
        }
    }
    else
    {
        /**< Invalid callback function pointer */
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_STK_SetIntervalPeriodic(u32 Microseconds, STK_CallbackFunc_t CallbackFunc)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
    if(CallbackFunc != NULL)
    {
        /**< Reset the Timer */
    	STK_Reset();
        
        /* Calculate the number of ticks required to wait for the specified number of microseconds */
        u32 Local_Ticks = (Microseconds * STK_AHB_CLK) / 1000000;
    
        /**< Check if TicksRequired is within the valid range */
        if (Local_Ticks <= STK_RELOAD_MAX)
        {
            /**< Save the callback function pointer */
            STK_Callback = CallbackFunc;

            /**< Set the Mode of interval to be periodic */
            STK_ModeOfInterval = STK_PERIOD_INTERVAL;

            /* Set the reload value for the SysTick timer */
            STK->LOAD = Local_Ticks-1;

            /**< Start the SysTick timer and enable the interrupt */
            STK->CTRL |= STK_CTRL_ENABLE_MASK;
            STK->CTRL |= STK_CTRL_TICKINT_MASK; 

            /**< Configured successfully */
            Local_FunctionStatus = E_OK;
        }  
    }
    else
    {
        /**< Invalid callback function pointer */
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;
}

/**
 * @} // End of Public_Functions
 */

/**
 * @defgroup IRQ_Handlers IRQ Handlers
 * @{
 */

void SysTick_Handler(void)
{
    if(STK_Callback != NULL)
    {
        if(STK_ModeOfInterval == STK_SINGLE_INTERVAL)
        {
            /**< Disable interrupt when the counter reaches zero */
            STK->CTRL &= ~STK_CTRL_TICKINT_MASK;

            /**< Disable SysTick timer */
            STK->CTRL &= ~STK_CTRL_ENABLE_MASK;

            /**< Clear the current value */
            STK->VAL = 0;

            /**< Set the reload value to 0 */
            STK->LOAD = 0;
        }

        /**< Callback notification */
        STK_Callback();

        /**< Clear the count/interrupt flag */
        STK->CTRL &= ~STK_CTRL_COUNTFLAG_MASK;

    }
}

/**
 * @} // End of IRQ_Handlers
 */
