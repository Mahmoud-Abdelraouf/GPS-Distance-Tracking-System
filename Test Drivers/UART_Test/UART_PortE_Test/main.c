#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "string.h"
#include "STD_TYPES.h"
#include "stdint.h"
#include "string.h"
#include "UART_interface.h"



void RGBLED_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x20; //Port F Clock enable
    while((SYSCTL_PRGPIO_R & 0x20) == 0) {}; //Delay
    GPIO_PORTF_DIR_R |= 0x0E; //Enable Output
    GPIO_PORTF_AFSEL_R &= ~(0x0E); //No alternate function
    GPIO_PORTF_PCTL_R &= ~(0x0000FFF0); //Clear PCTL bit
    GPIO_PORTF_DEN_R |= 0x0E; //Enable Digital Pins 3 2 1
    GPIO_PORTF_AMSEL_R &= ~(0x0E); //Disable Analog Mode
    GPIO_PORTF_DATA_R &= ~(0x0E); //Initialize LEDS to be off
}

void RGB_set(uint8_t mask) {
    mask &= 0x0E;
    GPIO_PORTF_DATA_R |= mask;
}

void RGB_clear(uint8_t mask) {
    mask &= 0x0E;
    GPIO_PORTF_DATA_R &= ~mask;
}




int main() {
    int i;
    unsigned char command;
    UART_voidInit5();
    RGBLED_Init();

    RGBLED_Init();
  //test 1
    /*while(1) {
        UART_voidSendByte('f');

    }*/

  //test 2
   while(1) {
       UART_voidSendString("Enter Command:\n");

       //  UART_SendString(command);
        //UART_sendByte(command);
         command = UART_u8RecieveByte();
        if(command == 'A') {
            RGB_clear(0x0E); //clear all leds
            RGB_set(0x02); //turn red on
        }
        else if(command == 'B') {
            RGB_clear(0x0E); //clear all leds
            RGB_set(0x04); //turn blue on
        }
        else if(command == 'D') {
            RGB_clear(0x0E); //clear all leds
            RGB_set(0x08); //turn GREEN on
        }
        
   }

}
