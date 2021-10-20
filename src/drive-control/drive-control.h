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

// drives the robot forward at a rate for an unspecified amound of time
// inputs -- rate in cm/s
void driveForward(float rate);

// drives the robot backwards at a rate for an unspedifiec amount of time
// inputs -- rate in cm/s
void driveBackwards(float rate);


//drives the robot forward at a rate for an unspecified amound of time
// inputs -- rate in cm/s
// -- distance in cm
void driveForward_dist(float rate, float distance);
 
//drives the robot back wards at a rate for an unspecified amound of time
// inputs -- rate in cm/s
// -- distance in cm
void driveBackwards_dist(float rate, float distance);

// ---- Rotating Methods ---- 

//rotates the robot clockwise at a rate for an unspecified amound of time
// inputs -- rate in rad/s
void rotateCW(float rate);

//rotates the robot counterclockwise  at a rate for an unspecified amound of time
// inputs -- rate in rad/s

void rotateCCW(float rate);

 
//drives the robot clockwise at a rate for an unspecified amound of time
// inputs -- rate in cm/s
// -- degrees of rotation
void rotateCW_dist(float rate, float degrees);

//drives the robot  counter clockwise at a rate for an unspecified amound of time
// inputs -- rate in cm/s
// -- degrees of rotation
void rotateCCW_dist(float rate, float degrees);



// ---- Turning methods ----

// turns the robot right about a radius equal to the wheel distances at a rate
// rate -- rad/second
void turnRight(float rate, float radius);

// turns the robot left about a radius equal to the wheel distances at a rate
// rate -- rad/second
void turnLeft(float rate, float radius);


// turns the robot right about a radius
// inputs : 
// rate -- rad/second
// radius in cm 
void turnRight_dist(float rate, float degrees, float radius);


// turns the robot right about a radius
// inputs : 
// rate -- rad/second
// radius in cm 
void turnLeft_dist(float rate, float degrees, float radius);


#endif
