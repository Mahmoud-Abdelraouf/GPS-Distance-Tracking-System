#ifndef GPS_H
#define GPS_H


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"

void gps_receive_sentence(u8* sentence);
void extract_coordinates(u8* sentence, f32* latitude, f32* longitude);

#endif
