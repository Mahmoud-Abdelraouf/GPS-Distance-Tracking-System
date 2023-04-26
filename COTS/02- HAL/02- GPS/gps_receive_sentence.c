#include "GPS.h"
/*
 * Description :
 * Receive a complete NMEA sentence from GPS module
 */
 
void gps_receive_sentence(u8* sentence) {


  
  u8 c = UART_recieveByte();
  while(c != '$') { 
   // Ignore characters until start of sentence
    c =  UART_recieveByte();
  }
  
  
UART_receiveString(u8 *Str);

}
