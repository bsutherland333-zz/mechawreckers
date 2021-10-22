// Source file for drive control library

#include "drive-control.h"

void driveForward(float rate)
{
    StepperMotor__init(); // reset the stepper motors
    
    float w = rate / _DriveControl__wheel_diameter / 2; // find angular rate
    
    float rpm  = w/3.1415/2; // find rpm
    
    // drive motors
    StepperMotor__rotate(2, 0, rpm, 1);
    StepperMotor__rotate(1, 0, rpm, 1);
}


void driveBackwards(float rate)
{
    StepperMotor__init(); // reset the stepper motors
    
    float w = rate / _DriveControl__wheel_diameter / 2; // find angular speed
    
    float rpm  = w/3.1415/2; // convert to rpm
    
    // drive motors
    StepperMotor__rotate(2, 1, rpm, 1);
    StepperMotor__rotate(1, 1, rpm, 1);
}



void rotateCW(float rate)
{
    // Reset Steppers
    StepperMotor__init();
    
    // find the necessary RPM
    float rpm = (rate * _DriveControl__wheel_distance) / (_DriveControl__wheel_diameter* 3.1415 * 2);
    
    // Run motors
    StepperMotor__rotate(1, 1, rpm, 1);
    StepperMotor__rotate(2, 0, rpm, 1);
}


void rotateCCW(float rate)
{
    // Reset Steppers
    StepperMotor__init();
    
    // find the necessary RPM
    float rpm = (rate * _DriveControl__wheel_distance) / (_DriveControl__wheel_diameter* 3.1415 * 2);
    
    // Run motors
    StepperMotor__rotate(1, 0, rpm, 1);
    StepperMotor__rotate(2, 1, rpm, 1);
}