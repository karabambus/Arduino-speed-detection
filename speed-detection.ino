///////////////////declaration////////////////////////////////////
// sensor diffrence detection
int sensor_curr_0 = 0;
int sensor_curr_1 = 0;
int sensor_value_0 = 0;
int sensor_value_1 = 0;
//time markers
unsigned long end_time = 0;
unsigned long start_time = 0;
unsigned long time_elapsed= 0;
// calibration settings
const int sensitivity = 5; // inverted   
const int readSpeed = 2; // inverted
const int distance = 18; 
const int conversion_factor = 1000; //1000 is from microsec to sec 10^-6
// output 
unsigned long speed = 0; // can be set to unsigned int 
//////////////////////setup/////////////////////////////////////
void setup(){
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}
//////////////////////main//////////////////////////////////////
void loop()
{
  sensor_value_0 = analogRead(A0);
  delay(2);
  sensor_curr_0 = analogRead(A0);

  if(sensor_value_0 > (sensor_curr_0 + sensitivity)){ 
    start_time = micros();
    sensor_value_1 = analogRead(A1);
    delay(2);
    sensor_curr_1 = analogRead(A1);
    while (!(sensor_value_1 > (sensor_curr_1 + sensitivity))) {
      sensor_value_1 = analogRead(A1);
      delay(2);
      sensor_curr_1 = analogRead(A1);
      Serial.println("waiting for detection");
    }
    end_time = micros();
    time_elapsed = end_time - start_time;
    Serial.print("Time elapsed is: ");
    Serial.print(time_elapsed);
    Serial.println(" microseconds");
    speed = time_elapsed/(distance*conversion_factor);
    Serial.print("Speed is: ");
    Serial.print(speed);
    Serial.println(" cm/s");   
  }
}




