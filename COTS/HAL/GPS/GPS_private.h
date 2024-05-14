/************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_3		*************/
/********** Date    : 26/04/2023              	*************/
/********** SWC     : HAL_LED                   *************/
/********** Version : 1.0                    	*************/
/************************************************************/
#ifndef GPS_PRIVATE_H__
#define GPS_PRIVATE_H__

#define M_PI            3.1415926
#define Earth_Radius    6371000

/**
 * @brief Extracts coordinates and speed from a GPS sentence.
 *
 * This function extracts latitude, longitude, and speed information from a GPS sentence.
 * It parses the NMEA sentence provided as input and retrieves the necessary fields.
 * The extracted latitude and longitude values are converted from degree-minute format
 * to decimal degrees format.
 *
 * @param Sentence Pointer to the NMEA sentence string.
 * @param Latitude Pointer to store the latitude value.
 * @param Longitude Pointer to store the longitude value.
 * @param Speed Pointer to store the speed value.
 *
 * @note The NMEA sentence format should follow the pattern:
 *       $GNRMC,HHMMSS.ss,A,DDMM.MMMMM,N,DDDMM.MMMMM,W,SSS.S,TTT.T,DDMMYY,D.D,V*CC
 *       where:
 *       - $GNRMC is the sentence identifier.
 *       - HHMMSS.ss is the UTC time of the position fix.
 *       - A indicates data validity (A: Valid, V: Invalid).
 *       - DDMM.MMMMM is the latitude in degrees and decimal minutes format.
 *       - N indicates the latitude hemisphere (N: North, S: South).
 *       - DDDMM.MMMMM is the longitude in degrees and decimal minutes format.
 *       - W indicates the longitude hemisphere (E: East, W: West).
 *       - SSS.S is the speed over ground in knots.
 *       - TTT.T is the track angle in degrees.
 *       - DDMMYY is the UTC date of the position fix.
 *       - D.D is the magnetic variation.
 *       - V indicates the mode of operation (A: Autonomous, D: Differential).
 *       - CC is the checksum.
 */
static void GPS_ExtractCoordinates(u8 *Sentence, f64 *Latitude, f64 *Longitude, u8 *Speed);

#endif /* GPS_PRIVATE_H__ */
