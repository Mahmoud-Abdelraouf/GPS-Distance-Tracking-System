#include "TM4C123GH6PM.h"
#include "stdint.h"
#include "string.h"
#include "STD_TYPES.h"
#include "stdint.h"
#include "string.h"
#include "UART_interface.h"
#include "GPS_interface.h"
#include "GPS_ERROR_STATE.h"
#include "LCD_interface.h"

  f32 latitude,longitude;

int main() {
    UART_voidInit(UART5, UART_BDR_9600, UART_DATA_8, UART_PARITY_NONE, UART_STOP_BIT_1);
   LCD_voidInit();
   GPS_ERROR_State_t functionErrorState;


    while(1) {

        functionErrorState =GPS_voidReceiveSentence();
        f32 distance = GPS_f32getDistance();
        LCD_voidSendNumber(distance);


    }
}
