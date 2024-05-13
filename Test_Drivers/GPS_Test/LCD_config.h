//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3      *************
//********** Date    : 25/04/2023               *************
//********** SWC     : HAL_LCD                  *************
//********** Version : 1.0                      *************
//***********************************************************
#ifndef __HAL_LCD_CONFIG_H__
#define __HAL_LCD_CONFIG_H__
//***************************************************SELECT LCD MODE**********************************************
/**
 *
 * LCD_MODE_OPTIONS
 *  YOUR OPTIONS: 1) LCD_4_BIT_MODE
 *                2) LCD_8_BIT_MODE
 *
 */
#define LCD_MODE    LCD_4_BIT_MODE

//**********************************************SELECT MC PIN*****************************************************
/**
 *
 * YOUR OPTIONS:
 *  For PORTS Choose :
 *      1-DIO_u8_PORTA
 *      2-DIO_u8_PORTB
 *      3-DIO_u8_PORTC
 *      4-DIO_u8_PORTD
 *      5-DIO_u8_PORTE
 *      6-DIO_u8_PORTF
 *  For PINS Choose :
 *      1-DIO_u8_PIN0
 *      2-DIO_u8_PIN1
 *      3-DIO_u8_PIN2
 *      4-DIO_u8_PIN3
 *      5-DIO_u8_PIN4
 *      6-DIO_u8_PIN5
 *      7-DIO_u8_PIN6
 *      8-DIO_u8_PIN7
 *
 * */
//*************************CONTROL PORT*************************
#define LCD_CONTROL_PORT                DIO_u8_PORTB
#define LCD_RS_PIN                      DIO_u8_PIN5
#define LCD_RW_PIN                      DIO_u8_PIN7
#define LCD_EN_PIN                      DIO_u8_PIN4
//*************************DATA PORT****************************
#define LCD_DATA_PORT                   DIO_u8_PORTB
#define LCD_D0_PIN                      DIO_u8_PIN7
#define LCD_D1_PIN                      DIO_u8_PIN6
#define LCD_D2_PIN                      DIO_u8_PIN5
#define LCD_D3_PIN                      DIO_u8_PIN4


#define LCD_D4_PIN                      DIO_u8_PIN3
#define LCD_D5_PIN                      DIO_u8_PIN2
#define LCD_D6_PIN                      DIO_u8_PIN1
#define LCD_D7_PIN                      DIO_u8_PIN0


//*************************************************************


#endif // __HAL_LCD_CONFIG_H__
