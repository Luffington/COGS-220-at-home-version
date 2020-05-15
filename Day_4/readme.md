# Day 4
## Milestone 5
### This Milestone turned out to be pretty complicated, simply because it had so many components to it. To solve the maze, I used the left hand on the wall method (since there are no loops in the maze, following the left hand wall will always lead to the exit.)
## Defining the intersections
### To identify the varied types of intersections in the maze, I designated 7 different conditions from 7 possible outcomes:
### Intersection left turn
### Intersection right turn
### Intersection T
### Intersection cross
### Intersection left T
### Intersection right T
### Finish
### No intersection
### Once these different conditions were established, I needed to assign unique IR reading combinations to each of them, so the robot would be able to distinguish between the different cases. These were placed in a function called get_intersection_type. Depending on the readouts of the sensors, this function would return the identification of the intersection so that the appropriate turn could be made in response to it. I also had to designate two new terms, line on left ever, and line on right error, to account for instances when more than one path was available to be taken. In accordance with each turn, a different sequence of notes would be played through the buzzer to illustrate that the robot was recording the change in the path. 
## The Left Hand Strategy
### To get the robot (Who we have since named Cloud) to make a left turn at every possible point, I needed to input some functions that forced the robot to drive forward in response to any right turn. By doing this, Cloud could follow the instructions to turn left at all times, the only exception being instances where the path only turned right. In this case, Cloud would make the exception to follow this right turn by relying on similar logic that was used to solve the simple maze in the previous milestone. I also implemented a new turning function, the U turn, which would cause Cloud to spin 180* in response to a dead end and continue to follow the line. The amalgamation of these new functions resulted in Cloud always turning left throughout the maze, eventually winding his way to the finish line. 
### Because so much turning is being done across tape, I needed to implement a more robust way for Cloud to determine when he had reached the finish. Simply triggering the far end IR sensors was no longer sufficient because turning across intersections would trigger this prematurely and prevent him from reaching the end. To solve this, I included a small timer that would record the duration that both these sensors were exceeding the threshold. If they were to hover over a line for more than 55ms, the finish line would be recognized. This is because the finish line is so thick that these sensors will naturally stay triggered for a longer period of time than simply skimming over the sides of an intersection. 
## Music Time
### As a fun little indulgence into my newfound coding power, I designed a piece of code that would play the Final Fantasy victory fanfare when the robot reached the finish line (Hence the name Cloud). 



