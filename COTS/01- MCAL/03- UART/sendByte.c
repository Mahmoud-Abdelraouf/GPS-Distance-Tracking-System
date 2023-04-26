#include "UART.h"
#include "STD_TYPES.h"
#include "TM4C123GH6PM.h"

void UART_sendByte(const u8 data){
	while ((UART0_FR_R & 0x0020) !=0); //check if the buffer is full
	UART0_DR_R =data;  // wait until Tx buffer not full, before giving it another byte 
}