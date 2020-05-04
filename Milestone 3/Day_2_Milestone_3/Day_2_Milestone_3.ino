#include <Wire.h>
#include <ZumoShield.h>
ZumoMotors motors;
ZumoReflectanceSensorArray linesensors(QTR_NO_EMITTER_PIN);
ZumoBuzzer buzzer;

unsigned int sensor_vals[6]; 

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Serial.println ("Calibration begin.");
int i;
for(i = 0; i<250; i++){
  linesensors.calibrate();
  delay(20);
}
Serial.println("Calibration complete!");
delay(1000);
}
int LastError = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int p = linesensors.readLine(sensor_vals, true);
  //calculate error from deisred target
  int error = p - 2500;

  //calculate motor differential
  int speedDifference = (error / 4) + (error-LastError)*6; 
  LastError = error;

  int leftSpeed = 200 + speedDifference;
  int rightSpeed = 200 - speedDifference;

  motors.setSpeeds(leftSpeed, rightSpeed);
  }
 
  
//motors.setSpeeds(300,300);
//delay(4000);
//motors.setSpeeds(0,0);
//while(true){
  
//}
