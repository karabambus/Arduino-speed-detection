#include "Arduino.h"
#include "Speed_Radar.h"
Speed_Radar::Speed_Radar(int sensitivity, int read_speed, int distance, int conversion_factor){
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
	Serial.begin(9600);

	// sensor diffrence detection
	this->sensor_curr_0 = 0;
	this->sensor_curr_1 = 0;
	this->sensor_value_0 = 0;
	this->sensor_value_1 = 0;
	//time markers
	this->end_time = 0;
	this->start_time = 0;
	this->time_elapsed= 0;
	// calibration settings
	this->sensitivity = sensitivity; // inverted   
	this->read_speed = read_speed; // inverted
	this->distance = distance; 
	this->conversion_factor = conversion_factor; //1000 is from microsec to sec 10^-6
	// output 
	this->speed = 0; // can be set to unsigned int 
}

void Speed_Radar::Detect_Speed(){
	sensor_value_0 = analogRead(A0);
  	delay(read_speed);
  	sensor_curr_0 = analogRead(A0);

  	if(sensor_value_0 > (sensor_curr_0 + sensitivity)){ 
    	start_time = micros();
    	sensor_value_1 = analogRead(A1);
    	delay(read_speed);
    	sensor_curr_1 = analogRead(A1);
    	while (!(sensor_value_1 > (sensor_curr_1 + sensitivity))) {
      		sensor_value_1 = analogRead(A1);
      		delay(read_speed);
      		sensor_curr_1 = analogRead(A1);
      		Serial.println("waiting for detection");
      	}
      	end_time = micros();
	    time_elapsed = end_time - start_time;
	    speed = time_elapsed/(distance*conversion_factor);
	    Print_Result();
    }

}


void Speed_Radar::Print_Result(){
    Serial.print("Time elapsed is: ");
    Serial.print(time_elapsed);
    Serial.println(" microseconds");
    speed = time_elapsed/(distance*conversion_factor);
    Serial.print("Speed is: ");
    Serial.print(speed);
    Serial.println(" cm/s"); 
}