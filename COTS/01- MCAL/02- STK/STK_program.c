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
    CLR_BIT(NVIC_ST_CTRL_R,STK_u8_ENABLE_B);
    /**< Set the reload value */
    NVIC_ST_RELOAD_R = copy_u32Ticks-1;
    /**< Set the interrupt priority to the lowest level */

    /**< Clear the current value */
    NVIC_ST_CURRENT_R = 0;
    /**< Enable SysTick timer with system clock as clock source and interrupts */
    SET_BIT(NVIC_ST_CTRL_R,STK_CLK_SRC_B); /**< Enable SysTick timer with system clock as clock source  */
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


u32 STK_u32GetCurrentValue(void)
{
    return NVIC_ST_CURRENT_R;
}

void STK_voidSetReloadValue(u32 copy_u32Ticks)
{
    NVIC_ST_RELOAD_R = copy_u32Ticks-1;
}

void STK_voidEnable(void)
{
    SET_BIT(NVIC_ST_CTRL_R,STK_ENABLE_B);
}

void STK_voidDisable(void)
{
    CLR_BIT(NVIC_ST_CTRL_R,STK_ENABLE_B);
}

void STK_voidEnableInterrupt(void)
{
   SET_BIT(NVIC_ST_CTRL_R,STK_INTEN_B);
}

void STK_voidDisableInterrupt(void)
{
   CLR_BIT(NVIC_ST_CTRL_R,STK_INTEN_B);
}

void STK_voidDelay(u32 copy_u32DelayMs)
{
    u32 Local_u32Ticks = (copy_u32DelayMs * STK_CLOCK_FREQUENCY)/1000;
    STK_voidSetReloadValue(Local_u32Ticks);
    STK_voidEnable();
    while(!STK_u32GetCurrentValue());
    STK_voidDisable();
}

void STK_voidDelayUs(u32 copy_u32DelayUs)
{
    u32 Local_u32Ticks = (copy_u32DelayUs * STK_CLOCK_FREQUENCY)/100000000;
    STK_voidSetReloadValue(Local_u32Ticks);
    STK_voidEnable();
    while(!STK_u32GetCurrentValue());
    STK_voidDisable();
}

void STK_voidDelayTicks(u32 copy_u32Ticks)
{
    STK_voidSetReloadValue(copy_u32Ticks);
    STK_voidEnable();
    while(!STK_u32GetCurrentValue());
    STK_voidDelay();
}
