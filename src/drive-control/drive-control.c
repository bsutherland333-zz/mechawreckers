// Source file for drive control library

#include "global-params.h"
#include "drive-control.h"

void DriveControl__init()
{
    StepperMotor__init();
}

void DriveControl__stopMovement()
{
    StepperMotor__stopMotion(1);
    StepperMotor__stopMotion(2);
}

int DriveControl__checkDriveStatus()
{
    if (StepperMotor__checkMotorStatus(1) + StepperMotor__checkMotorStatus(2) == 0)
    {
        return 0;
    } else
    {
        return 1;
    }
}

void DriveControl__driveForwards(float rate)
{
    // reset the stepper motors

    float w = 2 * rate / _DRIVECONTROL__WHEEL_DIAMETER; // find angular rate (radians/sec)

    float rps = w / (2 * PI); // find rotations per second

    // drive motors
    StepperMotor__rotate(1, 0, rps, 0);
    StepperMotor__rotate(2, 1, rps, 0);
}

void DriveControl__driveForwards_dist(float rate, float distance)
{
    // reset the stepper motors

    float w = 2 * rate / _DRIVECONTROL__WHEEL_DIAMETER; // find angular rate (radians/sec)

    float rps = w / (2 * PI); // find rotations per second

    float num_rotations = distance / (_DRIVECONTROL__WHEEL_DIAMETER * PI); // find number of rotations

    // drive motors
    StepperMotor__rotate(1, 0, rps, num_rotations);
    StepperMotor__rotate(2, 1, rps, num_rotations);
}


void DriveControl__driveBackwards(float rate)
{
    // reset the stepper motors

    float w = 2 * rate / _DRIVECONTROL__WHEEL_DIAMETER; // find angular rate (radians/sec)

    float rps = w / (2 * PI); // find rotations per second

    // drive motors
    StepperMotor__rotate(1, 1, rps, 0);
    StepperMotor__rotate(2, 0, rps, 0);
}

void DriveControl__driveBackwards_dist(float rate, float distance)
{
    // reset the stepper motors

    float w = 2 * rate / _DRIVECONTROL__WHEEL_DIAMETER; // find angular rate (radians/sec)

    float rps = w / (2 * PI); // find rotations per second

    float num_rotations = distance / (_DRIVECONTROL__WHEEL_DIAMETER * PI); // find number of rotations

    // drive motors
    StepperMotor__rotate(1, 1, rps, num_rotations);
    StepperMotor__rotate(2, 0, rps, num_rotations);
}


void DriveControl__rotateCW(float rate)
{
    // Reset Steppers


    // find the necessary RPS
    float rps = rate * (_DRIVECONTROL__WHEEL_DISTANCE / _DRIVECONTROL__WHEEL_DIAMETER) / 360.0;

    // Run motors
    StepperMotor__rotate(1, 1, rps, 0);
    StepperMotor__rotate(2, 1, rps, 0);
}

void DriveControl__rotateCW_dist(float rate, float degrees)
{
    // Reset Steppers


    // find the necessary RPS
    float rps = rate * (_DRIVECONTROL__WHEEL_DISTANCE / _DRIVECONTROL__WHEEL_DIAMETER) / 360.0;

    // Find the necessary rotations
    float rotations = degrees * (_DRIVECONTROL__WHEEL_DISTANCE / _DRIVECONTROL__WHEEL_DIAMETER) / 360.0;

    // Run motors
    StepperMotor__rotate(1, 1, rps, rotations);
    StepperMotor__rotate(2, 1, rps, rotations);
}


void DriveControl__rotateCCW(float rate)
{
    // Reset Steppers


    // find the necessary RPS
    float rps = rate * (_DRIVECONTROL__WHEEL_DISTANCE / _DRIVECONTROL__WHEEL_DIAMETER) / 360.0;

    // Run motors
    StepperMotor__rotate(1, 0, rps, 0);
    StepperMotor__rotate(2, 0, rps, 0);
}

void DriveControl__rotateCCW_dist(float rate, float degrees)
{
    // Reset Steppers


    // find the necessary RPS
    float rps = rate * (_DRIVECONTROL__WHEEL_DISTANCE / _DRIVECONTROL__WHEEL_DIAMETER) / 360.0;

    // Find the necessary rotations
    float rotations = degrees * (_DRIVECONTROL__WHEEL_DISTANCE / _DRIVECONTROL__WHEEL_DIAMETER) / 360.0;

    // Run motors
    StepperMotor__rotate(1, 0, rps, rotations);
    StepperMotor__rotate(2, 0, rps, rotations);
}


void DriveControl__turnRight(float rate, float radius)
{
    // check if the radius is at least equal to half the wheel distance (one wheel is stationary)
    if (radius < _DRIVECONTROL__WHEEL_DISTANCE / 2)
    {
        DriveControl__rotateCW(rate); // if so, just rotate in place
        return;
    }

    // reset steppers

    // find the speed of the right motor
    float right_rps = (rate * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                      (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;

    // find the speed of the left motor
    float left_rps = (rate * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                     (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;


    // run the motors
    StepperMotor__rotate(1, 0, right_rps, 0); // right stepper
    StepperMotor__rotate(2, 1, left_rps, 0); // left stepper
}


void DriveControl__backRight(float rate, float radius)
{
    // check if the radius is at least equal to half the wheel distance (one wheel is stationary)
    if (radius < _DRIVECONTROL__WHEEL_DISTANCE / 2)
    {
        DriveControl__rotateCW(rate); // if so, just rotate in place
        return;
    }

    // reset steppers

    // find the speed of the right motor
    float right_rps = (rate * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                      (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;

    // find the speed of the left motor
    float left_rps = (rate * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                     (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;


    // run the motors
    StepperMotor__rotate(1, 1, right_rps, 0); // right stepper
    StepperMotor__rotate(2, 0, left_rps, 0); // left stepper
}

void DriveControl__turnRight_dist(float rate, float radius, float angle)
{
    // check if the radius is at least equal to half the wheel distance (one wheel is stationary)
    if (radius < _DRIVECONTROL__WHEEL_DISTANCE / 2)
    {
        DriveControl__rotateCW(rate); // if so, just rotate in place
        return;
    }

    // reset steppers

    // find the speed of the right motor
    float right_rps = (rate * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                      (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;

    // find the speed of the left motor
    float left_rps = (rate * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                     (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;

    // find the number of rotations
    angle = angle * (PI / 180); // Converts degrees to radians
    float right_rotations = (angle * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                            (_DRIVECONTROL__WHEEL_DIAMETER * PI);
    float left_rotations = (angle * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                           (_DRIVECONTROL__WHEEL_DIAMETER * PI);


    // run the motors
    StepperMotor__rotate(1, 0, right_rps, right_rotations); // right stepper
    StepperMotor__rotate(2, 1, left_rps, left_rotations); // left stepper
}


void DriveControl__turnLeft(float rate, float radius)
{
    // check if the radius is at least equal to half the wheel distance (one wheel is stationary)
    if (radius < _DRIVECONTROL__WHEEL_DISTANCE / 2)
    {
        DriveControl__rotateCW(rate); // if so, just rotate in place
        return;
    }

    // reset steppers

    // find the speed of the right motor
    float right_rps = (rate * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                      (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;

    // find the speed of the left motor
    float left_rps = (rate * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                     (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;


    // run the motors
    StepperMotor__rotate(1, 0, right_rps, 0); // right stepper
    StepperMotor__rotate(2, 1, left_rps, 0); // left stepper
}


void DriveControl__backLeft(float rate, float radius)
{
    // check if the radius is at least equal to half the wheel distance (one wheel is stationary)
    if (radius < _DRIVECONTROL__WHEEL_DISTANCE / 2)
    {
        DriveControl__rotateCW(rate); // if so, just rotate in place
        return;
    }

    // reset steppers

    // find the speed of the right motor
    float right_rps = (rate * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                      (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;

    // find the speed of the left motor
    float left_rps = (rate * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                     (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;


    // run the motors
    StepperMotor__rotate(1, 1, right_rps, 0); // right stepper
    StepperMotor__rotate(2, 0, left_rps, 0); // left stepper
}


void DriveControl__turnLeft_dist(float rate, float radius, float angle)
{
    // check if the radius is at least equal to half the wheel distance (one wheel is stationary)
    if (radius < _DRIVECONTROL__WHEEL_DISTANCE / 2)
    {
        DriveControl__rotateCW(rate); // if so, just rotate in place
        return;
    }

    // reset steppers

    // find the speed of the right motor
    float right_rps = (rate * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                      (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;

    // find the speed of the left motor
    float left_rps = (rate * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                     (_DRIVECONTROL__WHEEL_DIAMETER * PI) / radius;

    // find the number of rotations
    angle = angle * (PI / 180); // Converts degrees to radians
    float right_rotations = (angle * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                            (_DRIVECONTROL__WHEEL_DIAMETER * PI);
    float left_rotations = (angle * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                           (_DRIVECONTROL__WHEEL_DIAMETER * PI);


    // run the motors
    StepperMotor__rotate(1, 0, right_rps, right_rotations); // right stepper
    StepperMotor__rotate(2, 1, left_rps, left_rotations); // left stepper
}