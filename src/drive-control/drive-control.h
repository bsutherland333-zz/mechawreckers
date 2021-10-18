/* Mechawreckers    MEEN 330   Oct 2021

drive-control.h -- A library that contains high level commands to control the robot, such as 
"go forward" or "rotate". methods will include commands for rates and distances 
*/


#ifndef DRIVE_CONTROL_H_
#define DRIVE_CONTROL_H_

#include "../stepper-motor/stepper-motor.h"

// Hardware defined-values
#define _DriveControl__wheel_diameter = 8.0;  //cm
#define _DriveControl__wheel_distance = 22.5;  //cm


// ---- Driving Methods ----
void driveForward(float rate);

void driveBackwards(float rate);

void driveForward(float rate, float distance);

void driveBackwards(float rate, float distance);

// ---- Rotating Methods ---- 

void rotateCW(float rate);

void rotateCCW(float rate);

void rotateCW(float rate, float degrees);

void rotateCCW(float rate, float degrees);



// ---- Turning methods ----

void turnRight(float rate);

void turnLeft(float rate);

void turnRight(float rate, float degrees, float radius);

void turnLeft(float rate, float degrees, float radius);


#endif
