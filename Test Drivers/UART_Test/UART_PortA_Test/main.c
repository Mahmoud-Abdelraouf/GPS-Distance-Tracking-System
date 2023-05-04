#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "string.h"
#include "STD_TYPES.h"
#include "stdint.h"
#include "string.h"

void UART_Init(void){
SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
UART0_CTL_R &= ~ UART_CTL_UARTEN;
UART0_IBRD_R = 104;
UART0_FBRD_R = 11;
UART0_LCRH_R |= (UART_LCRH_WLEN_8 | UART_LCRH_FEN) ;
UART0_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
GPIO_PORTA_AFSEL_R |= 0x03;
GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R &= ~0xFF)|(GPIO_PCTL_PA1_U0TX|GPIO_PCTL_PA0_U0RX);
GPIO_PORTA_DEN_R |= 0x03;
GPIO_PORTA_AMSEL_R &= ~0x03;
}


/*
 * Description :
 * Function to send byte using UART0
 */

void UART_sendByte(const unsigned char data){
    while ((UART0_FR_R & 0X0020) !=0); //check if the buffer is full
    UART0_DR_R =data;  // wait until Tx buffer not full, before giving it another byte
}


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
    UART_Init();
      //RGBLED_Init();

    //RGBLED_Init();
    while(1) {
                 UART_sendByte('f');

    }

    //int i;
    //char command;
    //UART5_Init();
    //RGBLED_Init();
  /* while(1) {
      //  printstr("Enter Command:\n");

       //  UART_SendString(command);
        //UART_sendByte(command);
         command = UART_receiveByte();
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
        //UART_sendByte('\n');
//        for(i = 0; i < 1000000; i++) {}; // add delay between reading commands
   // } */

}
