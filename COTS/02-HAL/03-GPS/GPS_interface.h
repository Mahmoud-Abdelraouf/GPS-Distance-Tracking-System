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
void GPS_voidReceiveSentence(void);

/** \brief
 *
 * \param
 * \return
 *
 */
void GPS_voidExtractCoordinates(u8* sentence);

/** \brief
 *
 * \param
 * \return
 *
 */

//f64 GPS_f64getDistance(void);

/** \brief
 *
 * \param
 * \return
 *
 */


#endif // __HAL_GPS_INTERFACE_H__
