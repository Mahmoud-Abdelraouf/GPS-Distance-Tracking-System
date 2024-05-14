//***********************************************************
//********** Name    : ASU_EMBEDDED_TEAM_3      *************
//********** Date    : 25/04/2023               *************
//********** SWC     : HAL_GPS                  *************
//********** Version : 1.0                      *************
//***********************************************************

#ifndef __HAL_GPS_INTERFACE_H__
#define __HAL_GPS_INTERFACE_H__
/** \brief
 *
 * \param
 * \return
 *
 */
void GPS_voidReceiveSentence(f64 *copy_f64Latitude,f64 *copy_f64Longitude, u8 *copy_u8Speed);

/** \brief
 *
 * \param
 * \return
 *
 */
void GPS_voidExtractCoordinates(u8 *copy_pu8Sentence,f64 *copy_f64Latitude,f64 *copy_f64Longitude, u8 *copy_u8Speed);

/** \brief
 *
 * \param
 * \return
 *
 */

//f64 GPS_f64GetDistance(void);


#endif // __HAL_GPS_INTERFACE_H__
