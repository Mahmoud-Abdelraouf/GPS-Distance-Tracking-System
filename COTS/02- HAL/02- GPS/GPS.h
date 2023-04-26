#ifndef GPS_H
#define GPS_H


#include "../LIB/STD_TYPES.h"
#include "../LIB/ERROR_STATE.h"

void gps_receive_sentence(char* sentence);
void extract_coordinates(char* sentence, float* latitude, float* longitude);

#endif