//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3		*************
//********** Date    : 26/04/2023              	*************
//********** SWC     : HAL_LED                  *************
//********** Version : 1.0                    	*************
//***********************************************************

#ifndef __HAL_LED_INTERFACE_H__
#define __HAL_LED_INTERFACE_H__


//MACROS for colours
#define RED_LED  	 	1
#define BLUE_LED 		2
#define GREEN_LED	    3

// functions for LEDs
void LED_voidLedInit(u8 copy_u8LedColour);        //function to initialize a specific LED
void LED_voidLedOn(u8 copy_u8LedColour);	      //function to turn on a specific LED	
void LED_voidLedOff(u8 copy_u8LedColour);	      //function to turn off a specific LED
void LED_voidLedTog(u8 copy_u8LedColour);         //function to toggle a specific LED
void LED_voidLedBlinkOnce(u8 copy_u8LedColour);	  //function to make a specific LED	blink once
void LED_voidLedBlinkTwice(u8 copy_u8LedColour);  //function to make a specific LED	blink twice

#endif //__HAL_LED_INTERFACE_H__