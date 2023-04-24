//*********************************************************//
//********** Name    : ASU_EMBEDDED_TEAM_3		***********//
//********** Date    : 14/04/2023              	***********//
//********** SWC     : LCD                   	***********//
//********** Version : 1.0                    	***********//
//*********************************************************//
#ifndef __LCD_INTERFACE_C__H__
#define __LCD_INTERFACE_C__H__

#define RS 0x20  // GPIO pin connected to RS of LCD
#define E 0x10   // GPIO pin connected to E of LCD
#define DB_MASK 0xF0  // Mask for data pins connected to DB4-DB7 of LCD
#define BusyFlag //DB7 pin responsible for busy flag
#define RW 0x40 //GPIO connected to RW of LCD

#define DB0 0
#define DB1  1
#define DB2  2
#define DB3  3
#define DB4  4
#define DB5  5
#define DB6  6
#define DB7  7

void LCD_VoidCommand(unsigned char command);
void LCD_VoidChar(unsigned char data);
void LCD_VoidInit(void);
void LCD_check_BF(void);
void LCD_VoidString (unsigned char *str);

#endif
