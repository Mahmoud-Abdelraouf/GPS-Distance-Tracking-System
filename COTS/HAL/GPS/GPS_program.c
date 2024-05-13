/***********************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_3      *************/
/********** Date    : 25/04/2023               *************/
/********** SWC     : HAL_GPS                  *************/
/********** Version : 1.0                      *************/
/***********************************************************/

/******************************< SYSTEM ****************************/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/******************************< LIB ******************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************< MCAL ******************************/
#include "UART_interface.h"

/******************************< HAL ******************************/
/**< LCD */
#include "CLCD_interface.h"

/**< GPS */
#include "GPS_private.h"
#include "GPS_interface.h"
#include "GPS_config.h"

/******************************< Global Variables *****************/
extern char GPS_SpeedArr[5];

/******************************< Function Implementation ******************************/
void GPS_ReceiveSentence(f64 *Latitude,f64 *Longitude, u8 *Speed)
{
    static u8 UART_InitFlag = 0;
    u8 Local_ReadCounter  = 0;
    u8 Local_GPS_Sentence[100];
    u8 Local_GPS_Check[] = "$GNRMC,";
    u8 Local_ReceivedChar;
    if(UART_InitFlag == 0)
    {
        UART_Init(UART2, UART_BDR_9600, UART_DATA_8, UART_PARITY_NONE, UART_STOP_BIT_1);
        UART_InitFlag++;
    }
    do
    {
        UART_ReceiveByte(UART2, &Local_ReceivedChar);
        if (Local_ReceivedChar == Local_GPS_Check[0])
        {
            UART_ReceiveByte(UART2, &Local_ReceivedChar);
            if (Local_ReceivedChar == Local_GPS_Check[1])
            {
                UART_ReceiveByte(UART2, &Local_ReceivedChar);
                if (Local_ReceivedChar == Local_GPS_Check[2])
                {
                    UART_ReceiveByte(UART2, &Local_ReceivedChar);
                    if (Local_ReceivedChar == Local_GPS_Check[3])
                    {
                        UART_ReceiveByte(UART2, &Local_ReceivedChar);
                        if (Local_ReceivedChar == Local_GPS_Check[4])
                        {
                            UART_ReceiveByte(UART2,&Local_ReceivedChar);
                            if (Local_ReceivedChar == Local_GPS_Check[5])
                            {
                                UART_ReceiveByte(UART2,&Local_ReceivedChar);
                                if (Local_ReceivedChar == Local_GPS_Check[6])
                                {
                                    UART_ReceiveByte(UART2,&Local_ReceivedChar);
                                    while(Local_ReceivedChar != '*')
                                    {
                                        Local_GPS_Sentence[Local_ReadCounter] = Local_ReceivedChar;
                                        UART_ReceiveByte(UART2,&Local_ReceivedChar);
                                        Local_ReadCounter++;
                                    }
                                    GPS_ExtractCoordinates(Local_GPS_Sentence,Latitude,Longitude,Speed);
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(Local_ReadCounter == 0);
}

void GPS_ExtractCoordinates(u8 *Sentence, f64 *Latitude, f64 *Longitude, u8 *Speed)
{
    f32 Local_f32Deg,Lcoal_f32Min,Local_f32Sec;
    u8 Local_u8CommaCount = 0;
    u8 j = 0;
    u8 k = 0;
    u8 l = 0;
    char longARR[15] = {0};
    char altitudeARR[15] = {0};
    u8 i = 0;
    char speedArr[10];
    while(Local_u8CommaCount<7)
    {
        if (Sentence[i] == ',')
        {
            Local_u8CommaCount++;
            i++;
        }
        if(Local_u8CommaCount == 1)
        {
            if (Sentence[i]!='A')
            {
                GPS_ReceiveSentence(Latitude,Longitude,Speed);
            }
        }
        if(Local_u8CommaCount == 2)
        {
            altitudeARR[j++]=Sentence[i];
        }
        if(Local_u8CommaCount == 4)
        {
            longARR[k++]=Sentence[i];
        }
        if(Local_u8CommaCount == 6)
        {
            speedArr[l++]=Sentence[i];
        }
        i++;
    }
    *Latitude = atof(altitudeARR);
    Local_f32Deg = *Latitude/100;
    Lcoal_f32Min = *Latitude - (f32)(Local_f32Deg*100);
    Local_f32Sec = Lcoal_f32Min/60.0;
    *Latitude = Local_f32Deg + Local_f32Sec;

    *Longitude = atof(longARR);
    Local_f32Deg = *Longitude/100;
    Lcoal_f32Min = *Longitude - (f32)(Local_f32Deg*100);
    Local_f32Sec = Lcoal_f32Min/60.0;
    *Longitude = Local_f32Deg + Local_f32Sec;

    for(int i = 0 ;i<4;i++)
    {
        GPS_SpeedArr[i] = speedArr[i];
    }
    speedArr[i] = '\0';
    *Speed = atof(speedArr);
}
