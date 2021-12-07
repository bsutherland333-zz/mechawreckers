/* Mechawreckers    MEEN 330   Oct 2021

drive-control.h -- A library that contains high level commands to control the robot, such as
"go forward" or "rotate". methods will include commands for rates and distances
*/


#ifndef DRIVE_CONTROL_H_
#define DRIVE_CONTROL_H_

#include "stepper-motor/stepper-motor.h"

// Hardware defined-values
#define _DRIVECONTROL__WHEEL_DIAMETER 8.0f  //cm
#define _DRIVECONTROL__WHEEL_DISTANCE 21.0f //cm

void DriveControl__init();

// Stops all driving motion regardless of state
void DriveControl__stopMovement();

// Checks to see if the robot has driven the requested distance and stops the robot if it has.
// Return 1 if still driving, 0 if done.
int DriveControl__checkDriveStatus();

// ---- Driving Methods ----

// drives the robot forward at a rate for an unspecified amount of time
// inputs -- rate in cm/s
void DriveControl__driveForwards(float rate);

// drives the robot backwards at a rate for an unspecified amount of time
// inputs -- rate in cm/s
void DriveControl__driveBackwards(float rate);


//drives the robot forward at a rate for an unspecified amount of time
// inputs -- rate in cm/s
// -- distance in cm
void DriveControl__driveForwards_dist(float rate, float distance);

//drives the robot back wards at a rate for an unspecified amount of time
// inputs -- rate in cm/s
// -- distance in cm
void DriveControl__driveBackwards_dist(float rate, float distance);



// ---- Rotating Methods ----

//rotates the robot clockwise at a rate for an unspecified amount of time
// inputs -- rate in deg/s
void DriveControl__rotateCW(float rate);

//rotates the robot counterclockwise  at a rate for an unspecified amount of time
// inputs -- rate in deg/s
void DriveControl__rotateCCW(float rate);


//drives the robot clockwise at a rate for an unspecified amount of time
// inputs -- rate in deg/s
// -- degrees of rotation
void DriveControl__rotateCW_dist(float rate, float degrees);

//drives the robot  counter-clockwise at a rate for an unspecified amount of time
// inputs -- rate in deg/s
// -- degrees of rotation
void DriveControl__rotateCCW_dist(float rate, float degrees);



// ---- Turning methods ----

// turns the robot right about a radius equal to the wheel distances at a rate
// rate -- cm/second down the center line
// radius -- cm
void DriveControl__turnRight(float rate, float radius);

// turns the robot left about a radius equal to the wheel distances at a rate
// rate -- cm/second down the center line
// radius -- cm
void DriveControl__turnLeft(float rate, float radius);


// turns the robot backwards and right about a radius equal to the wheel distances at a rate
// rate -- cm/second down the center line
// radius -- cm
void DriveControl__backRight(float rate, float radius);

// turns the robot backwards and left about a radius equal to the wheel distances at a rate
// rate -- cm/second down the center line
// radius -- cm
void DriveControl__backLeft(float rate, float radius);


// turns the robot right about a radius
// inputs :
// rate -- cm/second down the center line
// radius in cm
// angle in degrees
void DriveControl__turnRight_dist(float rate, float degrees, float radius);


// turns the robot right about a radius
// inputs :
// rate -- cm/second down the center line
// radius in cm
// angle in degrees
void DriveControl__turnLeft_dist(float rate, float degrees, float radius);


#endif