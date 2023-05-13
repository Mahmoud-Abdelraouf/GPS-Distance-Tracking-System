/*
 * APP.h
 *
 *  Created on: May 13, 2023
 *      Author: karim
 */

#ifndef __APP_APP_H__
#define __APP_APP_H__

#define M_PI            3.1415926
#define Earth_Radius    6371000

//*****************************************************************************
//
// function prototypes
//
//*****************************************************************************

/** \brief  function that calculates straightline distance between 2 points (in kilometers)
 *
 * \param
 * \return
 *
 */
 void APP_voidGetDistance(f32 copy_f32startLatitude, f32 copy_f32startLongitude,f32 copy_f32endLatitude, f32 copy_f32endLongitude, f32 *copy_pf32distance);

 /** \brief
 *
 * \param
 * \return
 *
 */
 void APP_voidGetTotalDistance(f32 copy_f32latitude, f32 copy_f32longitude, f32* copy_pf32distance);

 /** \brief
 *
 * \param
 * \return
 *
 */
 u8 APP_u8LightLED(f32 copy_f32startLatitude, f32 copy_f32startLongitude, f32 copy_f32endLatitude, f32 copy_f32endLongitude);



#endif /* __APP_APP_H__ */
