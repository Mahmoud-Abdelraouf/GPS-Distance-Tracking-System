// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		*************
// ********** Date    : 14/04/2023              	*************
// ********** SWC     : STK                     	*************
// ********** Version : 1.0                    		*************
// ************************************************************

#ifndef __STK_PRIVATE_H__
#define __STK_PRIVATE_H__

/**<  SysTick Control and Status Register (STCTRL)--> NVIC_ST_CTRL_R: Page 138 */
#define STK_ENABLE_B            0
#define STK_INTEN_B             1
#define STK_CLK_SRC_B           2
#define STK_COUNT_FLAG_B				16
/**<  Interrupt Control and State (INTCTRL)--> NVIC_INT_CTRL_R: Page 160 */
#define STK_PENDSTCLR_B         25
/**< This section for SysTick interrupt */
#define STK_INTERRUPT_ENABLE    1
#define STK_INTERRUPT_DISABLE   0

#define STK_SYS_CLOCK_1					0
#define STK_SYS_CLOCK_4					1

#define STK_MAX_RELOAD_VAL			0x00FFFFFF
#endif // __STK_PRIVATE_H__
