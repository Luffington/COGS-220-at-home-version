# Milestone 1
## Get the robot to move
### In this entry, I enabled the robot to both move and to follow a line, completing two milestones at once. 
### 
### I initialized a calibration sequence for the line sensors to detect the black pathway of the maze against the surrounding surface. After calibrating for a delay of 20ms, the robot will begin to follow the line following a speed difference function that is derived from PID controller logic. The sensors output values continuously as they detect the line. 2500 is read as following the center of the line. Turning right will increase the readout up to 5000 or a 90* right turn. Turning left will reduce the readout as far as zero or a 90* left turn. The left and right speeds are initialized at 200 each with additions or subtractions of the speed difference according to the direction needed for correction. The speed difference is calculated through use of a formula: (error/4) + (error-Lasterror*6).

### After compiling this code, the robot's behaviour has been shown to follow the line for its length with minute bang-bang corrections as it travels. When it reaches the end, it turns 180* and follows the line back to the beginning. It repeats this behaviour until the serial.begin time of 9600ms expires. 
