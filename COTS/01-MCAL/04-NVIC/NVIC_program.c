//*************************************************************
//********** Name    : Mahmoud Abdelraouf    		***********
//********** Date    : 23/05/2023              	    ***********
//********** SWC     : MCAL_NVIC                    ***********
//********** Version : 1.0                    		***********
//*************************************************************
/**< _LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
/**< _MCAL_NVIC */
#include "NVIC_private.h"
#include "NVIC_interface.h"
#include "NVIC_config.h"


u8 NVIC_u8EnableInterrupt(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorStatus;				/**< _Define_ERROR_STATUS */
	if(Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
	{
		NVIC_EN0_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 32 && Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC_EN1_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 64 && Copy_u8IntNumber <= 95)
	{
		Copy_u8IntNumber -= 64;
		NVIC_EN2_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 96 && Copy_u8IntNumber <= 127)
	{
		Copy_u8IntNumber -= 96;
		NVIC_EN3_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 128 && Copy_u8IntNumber <= 138)
	{
		Copy_u8IntNumber -= 128;
		NVIC_EN4_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else
	{
		Local_u8ErrorStatus = 1;		/**< _SET_ERROR_STATUS */
	}
	return Local_u8ErrorStatus;
}

u8 NVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorStatus;				/**< _Define_ERROR_STATUS */
	if(Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
	{
		NVIC_DIS0_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 32 && Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC_DIS1_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 64 && Copy_u8IntNumber <= 95)
	{
		Copy_u8IntNumber -= 64;
		NVIC_DIS2_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 96 && Copy_u8IntNumber <= 127)
	{
		Copy_u8IntNumber -= 96;
		NVIC_DIS3_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 128 && Copy_u8IntNumber <= 138)
	{
		Copy_u8IntNumber -= 128;
		NVIC_DIS4_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else
	{
		Local_u8ErrorStatus = 1;		/**< _SET_ERROR_STATUS */
	}
	return Local_u8ErrorStatus;
}

u8 NVIC_u8SetPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorStatus;				/**< _Define_ERROR_STATUS */
	if(Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
	{
		NVIC_PEND0_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 32 && Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC_PEND1_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 64 && Copy_u8IntNumber <= 95)
	{
		Copy_u8IntNumber -= 64;
		NVIC_PEND2_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 96 && Copy_u8IntNumber <= 127)
	{
		Copy_u8IntNumber -= 96;
		NVIC_PEND3_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 128 && Copy_u8IntNumber <= 138)
	{
		Copy_u8IntNumber -= 128;
		NVIC_PEND4_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else
	{
		Local_u8ErrorStatus = 1;		/**< _SET_ERROR_STATUS */
	}
	return Local_u8ErrorStatus;
}

u8 NVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorStatus;				/**< _Define_ERROR_STATUS */
	if(Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
	{
		NVIC_UNPEND0_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 32 && Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC_UNPEND1_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 64 && Copy_u8IntNumber <= 95)
	{
		Copy_u8IntNumber -= 64;
		NVIC_UNPEND2_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 96 && Copy_u8IntNumber <= 127)
	{
		Copy_u8IntNumber -= 96;
		NVIC_NVIC_UNPEND3_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 128 && Copy_u8IntNumber <= 138)
	{
		Copy_u8IntNumber -= 128;
		NVIC_UNPEND4_R = (1 << Copy_u8IntNumber); /**< _Atomic_Access */
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else
	{
		Local_u8ErrorStatus = 1;		/**< _SET_ERROR_STATUS */
	}
	return Local_u8ErrorStatus;
}


u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber, u8 *Copy_pu8Result)
{
	u8 Local_u8ErrorStatus;				/**< _Define_ERROR_STATUS */
	if(Copy_u8IntNumber >= 0 && Copy_u8IntNumber <= 31)
	{
		*Copy_pu8Result = GET_BIT(NVIC_ACTIVE0_R,Copy_u8IntNumber);
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 32 && Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		*Copy_pu8Result = GET_BIT(NVIC_ACTIVE1_R,Copy_u8IntNumber);
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 64 && Copy_u8IntNumber <= 95)
	{
		Copy_u8IntNumber -= 64;
		*Copy_pu8Result = GET_BIT(NVIC_ACTIVE2_R,Copy_u8IntNumber);
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 96 && Copy_u8IntNumber <= 127)
	{
		Copy_u8IntNumber -= 96;
		*Copy_pu8Result = GET_BIT(NVIC_ACTIVE3_R,Copy_u8IntNumber);
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else if(Copy_u8IntNumber >= 128 && Copy_u8IntNumber <= 138)
	{
		Copy_u8IntNumber -= 128;
		*Copy_pu8Result = GET_BIT(NVIC_ACTIVE4_R,Copy_u8IntNumber);
		Local_u8ErrorStatus = 0;		/**< _CLR_ERROR_STATUS */
	}
	else
	{
		Local_u8ErrorStatus = 1;		/**< _SET_ERROR_STATUS */
	}
	return Local_u8ErrorStatus;
}