#include "UART.h"
void UART_sendString(const u8 *Str){
u32 string_length = strlen(str);
for(u32 i = 0; i<string_length; i++){
UART_sendByte(Str[i]);
}
}
