#include <Speed_Radar.h>
// calibration settings
int sensitivity = 5; // inverted   
int readSpeed = 2; // inverted
int distance = 18; 
int conversion_factor = 1000; //1000 is from microsec to sec 10^-6
//class inst
Speed_Radar sr(sensitivity, readSpeed, distance, conversion_factor);
//////////////////////setup/////////////////////////////////////
void setup(){

}
//////////////////////main//////////////////////////////////////
void loop()
{
  sr.Detect_Speed();  
}
