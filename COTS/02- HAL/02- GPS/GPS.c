//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3      *************
//********** Date    : 25/04/2023               *************
//********** SWC     : HAL_GPS                  *************
//********** Version : 1.0                      *************
//***********************************************************
#include "GPS.h"
/**
 * Description :
 * Receive a complete NMEA sentence from GPS module
 */
 
void GPS_voidReceiveSentence(u8* sentence) 
{
	u8 c = UART_recieveByte();
	while(c != '$') 
	{ 
		// Ignore characters until start of sentence
		c =  UART_recieveByte();
	}
	UART_receiveString(u8 *Str);
}
/**
 * Description :
 * return the coordinates of your current location using gps module 
 */
void GPS_voidExtractCoordinates(u8* sentence, f32* latitude, f32* longitude)
{
	u8* token;
	u32 field_count = 0;
	
	// Split sentence into tokens based on comma delimiter
	token = strtok(sentence, ",");
	while (token != NULL) {
	// Check if token is latitude or longitude field
	if (field_count == 2) 
	{
		// Convert latitude from DDMM.MMMM format to decimal degrees
		f32 degrees = floor(atof(token) / 100);
		f32 minutes = atof(token) - degrees * 100;
		*latitude = degrees + minutes / 60;
	} 
	else if (field_count == 4)
	{
		// Convert longitude from DDDMM.MMMM format to decimal degrees
		f32 degrees = floor(atof(token) / 100);
		f32 minutes = atof(token) - degrees * 100;
		*longitude = degrees + minutes / 60;
	}
	// Move to next token
	token = strtok(NULL, ",");
	field_count++;
	}
}