#ifndef Speed_Radar_h
#define Speed_Radar_h
#include "Arduino.h"
class Speed_Radar{
  public:
    Speed_Radar(int sensitivity, int read_speed, int distance, int conversion_factor);
    //~Speed_Radar();
    void Detect_Speed();
    void Print_Result();
  private:
    //initialization settings
    byte analog_pin_0;
    byte analog_pin_1;
    int sensitivity;
    int read_speed;
    int distance;
    int conversion_factor;
    // sensor diffrence detection
    int sensor_curr_0;
    int sensor_curr_1;
    int sensor_value_0;
    int sensor_value_1;
    //time markers
    unsigned long end_time;
    unsigned long start_time;
    unsigned long time_elapsed; 
    //output
    unsigned int speed;
};
#endif

