#ifndef UART_H
#define UART_H


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/TM4C123GH6PM.h"

void UART_Init(void);
void UART_sendByte(const u8 data);
u8 UART_recieveByte(void);
void UART_sendString(const u8 *Str);
void UART_receiveString(u8 *Str);



#endif
