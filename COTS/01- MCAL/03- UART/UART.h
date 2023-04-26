#ifndef UART_H
#define UART_H


#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"

void UART_Init(void);
void UART_sendByte(const uint8 data);
uint8 UART_recieveByte(void);
void UART_sendString(const uint *Str);
void UART_receiveString(uint8 *Str);



#endif
