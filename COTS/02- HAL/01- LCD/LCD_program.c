#include "LCD_private.h"
#include"STD_TYPES.h"
#include "LCD_interface.h"


void LCD_VoidCommand(u8 command)
{
    GPIO_PORTB_DATA_R &= ~RS;  // set RS to 0 (command mode)
    GPIO_PORTB_DATA_R &= ~RW; //set RW to 0
    GPIO_PORTA_DATA_R &= ~DB_MASK;  // clear data pins
    GPIO_PORTA_DATA_R |= (command & 0xF0) >> 0;  // send high nibble
    GPIO_PORTB_DATA_R |= E;  // toggle E to latch high nibble
    STK_voidDelay(1);
    GPIO_PORTB_DATA_R &= ~E;  // toggle E to latch high nibble
    STK_voidDelay(1);
    GPIO_PORTA_DATA_R &= ~DB_MASK;  // clear data pins
    GPIO_PORTA_DATA_R |= (command & 0x0F) << 4;  // send low nibble
    GPIO_PORTB_DATA_R |= E;  // toggle E to latch low nibble
    STK_voidDelay(1);
    GPIO_PORTB_DATA_R &= ~E;  // toggle E to latch low nibble
    STK_voidDelay(1);
}

void LCD_VoidChar(u8 data)
{
    GPIO_PORTB_DATA_R |= RS;  // set RS to 1 (data mode)
    GPIO_PORTB_DATA_R &= ~RW; //set RW to 0
    GPIO_PORTA_DATA_R &= ~DB_MASK;  // clear data pins
    GPIO_PORTA_DATA_R |= (data & 0xF0) >> 0;  // send high nibble
    GPIO_PORTB_DATA_R |= E;  // toggle E to latch high nibble
    STK_voidDelay(1);
    GPIO_PORTB_DATA_R &= ~E;  // toggle E to latch high nibble
    STK_voidDelay(1);
    GPIO_PORTA_DATA_R &= ~DB_MASK;  // clear data pins
    GPIO_PORTA_DATA_R |= (data & 0x0F) << 4;  // send low nibble
    GPIO_PORTB_DATA_R |= E;  // toggle E to latch low nibble
    STK_voidDelay(1);
    GPIO_PORTB_DATA_R &= ~E;  // toggle E to latch low nibble
    STK_voidDelay(1);
}

void LCD_VoidInit(void)
{
    SYSCTL_RCGCGPIO_R |= 0x03;  // enable clock for Port A and Port B

    GPIO_PORTA_DIR_R |= DB_MASK;  // set data pins as output
    GPIO_PORTA_DEN_R |= DB_MASK;  // enable digital function for data pins
    GPIO_PORTB_DIR_R |= (RS | E);  // set RS and E pins as output
    GPIO_PORTB_DEN_R |= (RS | E);  // enable digital function for RS and E pins

    STK_voidDelay(20);  // wait for LCD to power up
    LCD_VoidCommand(0x20);  // function set command: 4-bit mode, 1-line display, 5x7 dot font
    LCD_VoidCommand(0x0C);  // display ON/OFF command: display on, cursor off, blinking off
    LCD_VoidCommand(0x01);  //   clear display command
    LCD_VoidCommand(0x06);  // entry mode set command: cursor moves to right after writing a character
}


void lcd_check_BF(void)
{
    u8 BF_copy;                         // busy flag 'mirror'
    GPIO_PORTA_DIR_R &= ~BusyFlag; // set D7 data direction to input
    GPIO_PORTB_DATA_R &= ~RS;                // select the Instruction Register (RS low)
    GPIO_PORTB_DATA_R |= RW;                 // read from LCD module (RW high)

    do
    {
        BF_copy = 0;                         // initialize busy flag 'mirror'
        GPIO_PORTB_DATA_R |= E;               // Enable pin high
        STK_voidDelay(1);

        BF_copy |= BusyFlag;  // get actual busy flag status

        GPIO_PORTB_DATA_R &= ~E;              // Enable pin low
        STK_voidDelay(1);

    } while (BusyFlag);                   // check again if busy flag was high

// arrive here if busy flag is clear -  clean up and return
    GPIO_PORTB_DATA_R &= ~RW;                // write to LCD module (RW low)       <-- (not really necessary)
    GPIO_PORTA_DIR_R |=BusyFlag;                  // reset D7 data direction to output
}
void LCD_VoidString (u8 *str) /* Send string to LCD function */
{
	u32 i;
	for(i=0;str[i]!='\0';i++)  /* Send each char of string till the NULL */
	{
		LCD_VoidChar (str[i]);  /* Call LCD data write */
	}
}


int main(void)
{
LCD_VoidInit();
    while (1)
        ;  // do nothing
}

