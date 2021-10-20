// Source file for drive control library

#include "drive-control.h"

void driveForward(float rate)
{
    StepperMotor__init(); // reset the stepper motors
    
    float w = rate / _DriveControl__wheel_diameter; // find angular rate
    
    float rpm  = w*30/3.1415; // find rmp
    
    // drive motors
    StepperMotor__rotate(2, 0, rpm, 1);
    StepperMotor__rotate(1, 0, rpm, 1);
}


void driveBackwards(float rate)
{
    StepperMotor__init(); // reset the stepper motors
    
    float w = rate / _DriveControl__wheel_diameter; // find angular speed
    
    float rpm  = w*30/3.1415; // convert to rpm
    
    // drive motors
    StepperMotor__rotate(2, 1, rpm, 1);
    StepperMotor__rotate(1, 1, rpm, 1);
}