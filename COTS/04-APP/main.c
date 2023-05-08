
#include "main.h"
#include <math.h>
#include <LED_interface.h>



int main(void){
	
}

APP_u8getDistance(f32 copy_f32startLatitude, f32 copy_f32startLongitude,f32 copy_f32endLatitude, f32 copy_f32endLongitude, f32* copy_pf32distance){
	// convert all coordinates from Degrees into Radians
	f32 Local_f32startLat = copy_f32startLatitude* M_PI/180;
	f32 Local_f32startLong = copy_f32startLongitude* M_PI/180;
	f32 Local_f32endLat = copy_f32endLatitude* M_PI/180;
	f32 Local_f32endLong = copy_f32endLongitude* M_PI/180;
	
	// calculate latitude difference and longitude difference
	f32 Local_f32latDifference = Local_f32endLat - Local_f32startLat;
	f32 Local_f32longDifference = Local_f32endLong - Local_f32startLong;
	
	//use Haversine formula
	f32 Local_f32a = sin(Local_f32latDifference / 2) * sin(Local_f32latDifference / 2) + cos(Local_f32startLat) * cos(Local_f32endLat) 
	* sin(Local_f32longDifference / 2) * sin(Local_f32longDifference / 2);
	f32 Local_f32c = 2 * atan2(sqrt(a), sqrt(1 - a));
	
	//Multipy by Earth's Radius to get the distance
	*copy_pf32distance = Local_f32c * Earth_Radius;
}
void APP_u8lightLED(f32 copy_f32startLatitude, f32 copy_f32startLogitude, f32 copy_f32endLatitude, f32 copy_f32endLongitude)
{
	//calc distance to endpoint
	f32 Local_f32distanceToEndPoint = 0;
	APP_u8getDistance(copy_f32startLatitude, copy_f32startLogitude, copy_f32endLatitude, copy_f32endLongitude, Local_f32distanceToEndPoint);
	//assuming args are in meters
	if (Local_f32distanceToEndPoint > 5){//red
		LED_voidLedInit();//assuming this call is needed
		LED_voidLedOn(LED_RED);
	} else if (Local_f32distanceToEndPoint < 5){//yellow
		LED_voidLedInit();//assuming this call is needed
		LED_voidLedOn(LED_BLUE);
	} else if (Local_f32distanceToEndPoint < 2){//green
		LED_voidLedInit();//assuming this call is needed
		LED_voidLedOn(LED_GREEN);
	}
}
