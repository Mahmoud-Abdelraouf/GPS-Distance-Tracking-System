// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!		***********
// ********** Date    : 14/04/2023              	***********
// ********** SWC     : MCAL_UART                   ***********
// ********** Version : 1.0                    		***********
// ************************************************************
/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
/**< HAL_UART */
#include "UAR_interface.h"
#include "UAR_private.h"
#include "UAR_config.h"

// ************************************************************************************************
void UART_voidSendByte(const u8 data)
{
	while ((UART0_FR_R & 0x0020) !=0); //check if the buffer is full
	UART0_DR_R =data;  // wait until Tx buffer not full, before giving it another byte 
}
// ************************************************************************************************
u8 UART_u8RecieveByte(void)
{
	while (UARTO_FR_R & 0x0010 != 0); //check if the buffor is empty 
	return (UARTO_DR_R & OxFF);
}
// ************************************************************************************************
void UART_voidSendString(const u8 *Str)
{
	u32 string_length = strlen(str);
	for(u32 i = 0; i<string_length; i++)
	{
		UART_sendByte(Str[i]);
	}
}
