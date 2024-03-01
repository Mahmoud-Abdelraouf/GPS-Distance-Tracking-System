/**************************************************************/
/********** Name    : Mahmoud Abdelraouf    		***********/
/********** Date    : 23/05/2023              	    ***********/
/********** SWC     : MCAL_NVIC                     ***********/
/********** Version : 1.0                    		***********/
/**************************************************************/
#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__


u8 NVIC_u8EnableInterrupt(u8 Copy_u8IntNumber);
u8 NVIC_u8DisableInterrupt(u8 Copy_u8IntNumber);
u8 NVIC_u8SetPendingFlag(u8 Copy_u8IntNumber);
u8 NVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber);
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber, u8 *Copy_pu8Result);







#endif