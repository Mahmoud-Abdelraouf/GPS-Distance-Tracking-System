//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3      *************
//********** Date    : 25/04/2023               *************
//********** SWC     : HAL_LCD                  *************
//********** Version : 1.0                      *************
//***********************************************************
#ifndef __HAL_LCD_PRIVATE_H__
#define __HAL_LCD_PRIVATE_H__
/**
 *
 * LCD_MODES
 *
 * */
#define LCD_8_BIT_MODE          8
#define LCD_4_BIT_MODE          4
/**
 *
 * LCD_COMMANDS
 *
 * */
#define LCD_8_BIT_MODE_COMMAND                  0x38
#define LCD_DISPLAY_ON_COMMAND                  0x0C
#define LCD_CLEAR_COMMAND                       0x01
#define LCD_4_BIT_MODE_COMMAND_1                0x33
#define LCD_4_BIT_MODE_COMMAND_2                0x32
#define LCD_4_BIT_MODE_COMMAND_3                0x28

#endif // __HAL_LCD_PRIVATE_H__
