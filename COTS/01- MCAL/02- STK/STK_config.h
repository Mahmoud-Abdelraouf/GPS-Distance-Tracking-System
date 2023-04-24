// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********
// ********** Date    : 14/04/2023              	***********
// ********** SWC     : STK                     	***********
// ********** Version : 1.0                    		***********
// ************************************************************

#ifndef __STK_CONFIG_H__
#define __STK_CONFIG_H__


/**
 *
 *  Choose if we want to use SysTick timer to generate interrupt or not
 *  YOUR OPTIONS: 1) STK_INTERRUPT_ENABLE
 *                2) STK_INTERRUPT_DISABLE
 *
 */
#define STK_SET_INTERRUPT   STK_INTERRUPT_DISABLE

/**
 *
 *  Choose The Clock Sourse of the SysTick timer
 *  YOUR OPTIONS: 1) STK_SYS_CLOCK_1
 *                2) STK_SYS_CLOCK_4
 *
 */
#define STK_CLK_SRC   STK_SYS_CLOCK_4



#define STK_CLOCK_FREQUENCY_1         16000000
#define STK_CLOCK_FREQUENCY_4         4000000


#endif // __STK_CONFIG_H__
