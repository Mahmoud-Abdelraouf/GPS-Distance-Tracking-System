// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********
// ********** Date    : 14/04/2023              	***********
// ********** SWC     : STK                     	***********
// ********** Version : 1.0                    		***********
// ************************************************************

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TM4C123GH6PM.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


void STK_voidConfig(u32 copy_u32Ticks)
{
    /**< Disable SysTick timer */
    CLR_BIT(NVIC_ST_CTRL_R,STK_ENABLE_B);
    /**< Set the reload value */
    NVIC_ST_RELOAD_R = copy_u32Ticks-1;
    /**< Set the interrupt priority to the lowest level */

    /**< Clear the current value */
    NVIC_ST_CURRENT_R = 0;
    /**< Enable SysTick timer with system clock as clock source and interrupts */
    #if STK_CLK_SRC == STK_SYS_CLOCK_1
		SET_BIT(NVIC_ST_CTRL_R,STK_CLK_SRC_B); /**< Enable SysTick timer with system clock as clock source  */
		#elif  STK_CLK_SRC == STK_SYS_CLOCK_4
		CLR_BIT(NVIC_ST_CTRL_R,STK_CLK_SRC_B); /**< Enable SysTick timer with (system clock)/4 as clock source  */
		#endif
    #if STK_SET_INTERRUPT == STK_INTERRUPT_ENABLE
    SET_BIT(NVIC_ST_CTRL_R,STK_INTEN_B);   /**< Enable SysTick timer Interrupt */
    #elif STK_SET_INTERRUPT == STK_INTERRUPT_DISABLE
    CLR_BIT(NVIC_ST_CTRL_R,STK_INTEN_B);   /**< Disable SysTick timer Interrupt */
    #endif // STK_SET_INTERRUPT
    SET_BIT(NVIC_ST_CTRL_R,STK_ENABLE_B);  /**< Enable the SysTick timer */
}

void STK_voidHandler(void)
{
    /**< Handler SysTick interrupt */
    /**< This function can be implemented to perform periodic tasks or measure time intervals */
}

void STK_voidReset(void)
{
    /**< Disable SysTick timer */
    CLR_BIT(NVIC_ST_CTRL_R,STK_ENABLE_B);
    /**< Clear the current value */
    NVIC_ST_CURRENT_R = 0;
    /**< Set the reload value to 0 */
    NVIC_ST_RELOAD_R = 0;
    /**< Clear the count flag */
    CLR_BIT(NVIC_INT_CTRL_R,STK_PENDSTCLR_B);
}


void STK_voidGetCurrentValue(u32 *copy_pu32CurrVal)
{
  *copy_pu32CurrVal = NVIC_ST_CURRENT_R;
}

u8 STK_voidSetReloadValue(u32 copy_u32Ticks)
{
	u8 Local_ErrorState = STD_TYPES_OK;
	if(copy_u32Ticks<=STK_MAX_RELOAD_VAL)
	{
		NVIC_ST_RELOAD_R = copy_u32Ticks-1;
	}
  else
	{
		/**< Return Error State */
		Local_ErrorState = STD_TYPES_NOK;
	}
	return Local_ErrorState;
}

void STK_voidEnable(void)
{
    SET_BIT(NVIC_ST_CTRL_R,STK_ENABLE_B);
	#if 	STK_CLK_SRC == STK_SYS_CLOCK_1
	SET_BIT(NVIC_ST_CTRL_R,STK_CLK_SRC_B);
	#elif STK_CLK_SRC == STK_SYS_CLOCK_4
	CLR_BIT(NVIC_ST_CTRL_R,STK_CLK_SRC_B);
	#else 
	#error "Wrong Choice"
	#endif
}

void STK_voidDisable(void)
{
  CLR_BIT(NVIC_ST_CTRL_R,STK_ENABLE_B);
	NVIC_ST_RELOAD_R  = 0;
	NVIC_ST_CURRENT_R = 0;
}

void STK_voidEnableInterrupt(void)
{
  SET_BIT(NVIC_ST_CTRL_R,STK_INTEN_B);
	#if 	STK_CLK_SRC == STK_SYS_CLOCK_1
	SET_BIT(NVIC_ST_CTRL_R,STK_CLK_SRC_B);
	#elif STK_CLK_SRC == STK_SYS_CLOCK_4
	CLR_BIT(NVIC_ST_CTRL_R,STK_CLK_SRC_B);
	#endif
}

void STK_voidDisableInterrupt(void)
{
   CLR_BIT(NVIC_ST_CTRL_R,STK_INTEN_B);
	 NVIC_ST_RELOAD_R = 0;
	 NVIC_ST_CURRENT_R = 0;
}

void STK_voidDelay(u32 copy_u32DelayMs)
{
		#if STK_CLK_SRC == STK_SYS_CLOCK_1
    u32 Local_u32Ticks = copy_u32DelayMs * (STK_CLOCK_FREQUENCY_1/1000);
		#elif STK_CLK_SRC == STK_SYS_CLOCK_4
	  u32 Local_u32Ticks = copy_u32DelayMs * (STK_CLOCK_FREQUENCY_4/1000);
		#endif
    STK_voidSetReloadValue(Local_u32Ticks);
		NVIC_ST_CURRENT_R = 0; /**< Clear the current value */
    STK_voidEnable();
    while(!GET_BIT(NVIC_ST_CTRL_R,STK_COUNT_FLAG_B));
    STK_voidDisable();
}

void STK_voidDelayUs(u32 copy_u32DelayUs)
{
		#if STK_CLK_SRC == STK_SYS_CLOCK_1 
    u32 Local_u32Ticks = (copy_u32DelayUs * STK_CLOCK_FREQUENCY_1)/100000000;
		#elif STK_CLK_SRC == STK_SYS_CLOCK_4
	  u32 Local_u32Ticks = (copy_u32DelayUs * STK_CLOCK_FREQUENCY_4)/100000000;
		#endif
    STK_voidSetReloadValue(Local_u32Ticks);
		NVIC_ST_CURRENT_R = 0; /**< Clear the current value */
    STK_voidEnable();
    while(!GET_BIT(NVIC_ST_CTRL_R,STK_COUNT_FLAG_B));
    STK_voidDisable();
}

void STK_voidDelayTicks(u32 copy_u32Ticks)
{
    STK_voidSetReloadValue(copy_u32Ticks);
		NVIC_ST_CURRENT_R = 0; /**< Clear the current value */
    STK_voidEnable();
    while(!GET_BIT(NVIC_ST_CTRL_R,STK_COUNT_FLAG_B));	
    STK_voidDisable();
}
