#include <Wire.h>
#include <ZumoShield.h>
ZumoMotors motors;
ZumoReflectanceSensorArray linesensors(QTR_NO_EMITTER_PIN);
ZumoBuzzer buzzer;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Serial.println ("Calibration begin.");
int i;
int spin_direction = 1;
motors.setSpeeds(150*spin_direction, -150*spin_direction);
for(i = 0; i<80; i++){
  linesensors.calibrate();
  if(i%40 == 20){
    spin_direction = -spin_direction;
    motors.setSpeeds(150*spin_direction, -150*spin_direction);
  }
  delay(8);
}
Serial.println("Calibration complete!");
motors.setSpeeds(0,0);
delay(500);
}


unsigned int sensor_vals[6]; 
int BASE_SPEED = 200;
double PROPORTION_GAIN = 0.2;
double DERIVATIVE_GAIN = 3;
int lastError = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int line_position = linesensors.readLine(sensor_vals, true);
  //calculate error from deisred target
  void follow_line(){
  int error = line_position - 2500;
  int error_change = error - lastError;
    //calculate motor differential
 //old code: int speedDifference = (error / 4) + (error-lastError)*6; 
 
  int leftSpeed = BASE_SPEED + PROPORTION_GAIN * error + DERIVATIVE_GAIN * error_change; 
  int rightSpeed = BASE_SPEED + -PROPORTION_GAIN * error + -DERIVATIVE_GAIN * error_change;
   lastError = error;

  motors.setSpeeds(leftSpeed, rightSpeed);
  }
 
  
//}
