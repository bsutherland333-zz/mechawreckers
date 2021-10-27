/* Mechawreckers    MEEN 330   Oct 2021

drive-control.h -- A library that contains high level commands to control the robot, such as
"go forward" or "rotate". methods will include commands for rates and distances
*/


#ifndef DRIVE_CONTROL_H_
#define DRIVE_CONTROL_H_

#include "../stepper-motor/stepper-motor.h"

// Hardware defined-values
#define _DRIVECONTROL__WHEEL_DIAMETER 8.0f  //cm
#define _DRIVECONTROL__WHEEL_DISTANCE 22.5f //cm


// ---- Driving Methods ----

// drives the robot forward at a rate for an unspecified amount of time
// inputs -- rate in cm/s
void DriveControl__driveForward(float rate);

// drives the robot backwards at a rate for an unspecified amount of time
// inputs -- rate in cm/s
void DriveControl__driveBackwards(float rate);


//drives the robot forward at a rate for an unspecified amount of time
// inputs -- rate in cm/s
// -- distance in cm
void DriveControl__driveForward_dist(float rate, float distance);

//drives the robot back wards at a rate for an unspecified amount of time
// inputs -- rate in cm/s
// -- distance in cm
void DriveControl__driveBackwards_dist(float rate, float distance);

// ---- Rotating Methods ----

//rotates the robot clockwise at a rate for an unspecified amount of time
// inputs -- rate in rad/s
void DriveControl__rotateCW(float rate);

//rotates the robot counterclockwise  at a rate for an unspecified amount of time
// inputs -- rate in rad/s

void DriveControl__rotateCCW(float rate);


//drives the robot clockwise at a rate for an unspecified amount of time
// inputs -- rate in cm/s
// -- degrees of rotation
void DriveControl__rotateCW_dist(float rate, float degrees);

//drives the robot  counter-clockwise at a rate for an unspecified amount of time
// inputs -- rate in cm/s
// -- degrees of rotation
void DriveControl__rotateCCW_dist(float rate, float degrees);



// ---- Turning methods ----

// turns the robot right about a radius equal to the wheel distances at a rate
// rate -- rad/second
void DriveControl__turnRight(float rate, float radius);

// turns the robot left about a radius equal to the wheel distances at a rate
// rate -- rad/second
void DriveControl__turnLeft(float rate, float radius);


// turns the robot right about a radius
// inputs :
// rate -- rad/second
// radius in cm
void DriveControl__turnRight_dist(float rate, float degrees, float radius);


// turns the robot right about a radius
// inputs :
// rate -- rad/second
// radius in cm
void DriveControl__turnLeft_dist(float rate, float degrees, float radius);


#endif