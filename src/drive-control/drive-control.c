// Source file for drive control library

#include "drive-control.h"

void DriveControl__driveForward(float rate) {
    StepperMotor__init(); // reset the stepper motors

    float w = rate / _DRIVECONTROL__WHEEL_DIAMETER / 2; // find angular rate

    float rpm = w / 3.1415 / 2; // find rps

    // drive motors
    StepperMotor__rotate(2, 0, rpm, 1);
    StepperMotor__rotate(1, 0, rpm, 1);
}


void DriveControl__driveBackwards(float rate) {
    StepperMotor__init(); // reset the stepper motors

    float w = rate / _DRIVECONTROL__WHEEL_DIAMETER / 2; // find angular speed

    float rpm = w / 3.1415 / 2; // convert to rps

    // drive motors
    StepperMotor__rotate(2, 1, rpm, 1);
    StepperMotor__rotate(1, 1, rpm, 1);
}


void DriveControl__rotateCW(float rate) {
    // Reset Steppers
    StepperMotor__init();

    // find the necessary RPS
    float rpm = (rate * _DRIVECONTROL__WHEEL_DISTANCE) / (_DRIVECONTROL__WHEEL_DIAMETER * 3.1415 * 2);

    // Run motors
    StepperMotor__rotate(1, 1, rpm, 1);
    StepperMotor__rotate(2, 0, rpm, 1);
}


void DriveControl__rotateCCW(float rate) {
    // Reset Steppers
    StepperMotor__init();

    // find the necessary RPS
    float rpm = (rate * _DRIVECONTROL__WHEEL_DISTANCE) / (_DRIVECONTROL__WHEEL_DIAMETER * 3.1415 * 2);

    // Run motors
    StepperMotor__rotate(1, 0, rpm, 1);
    StepperMotor__rotate(2, 1, rpm, 1);
}


void DriveControl__turnRight(float rate, float radius) {
    // check if the radius is at least equal to half the wheel distance (one wheel is stationary)
    if (radius < _DRIVECONTROL__WHEEL_DISTANCE / 2) {
        DriveControl__rotateCW(rate); // if so, just rotate in place
        return;
    }

    StepperMotor__init(); // reset steppers


    // find the speed of the right motor
    float right_rps = (rate * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                      ((_DRIVECONTROL__WHEEL_DIAMETER / 2.0) * 3.1415 * 2);

    // find the speed of the left motor
    float left_rps = (rate * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                     ((_DRIVECONTROL__WHEEL_DIAMETER / 2.0) * 3.1415 * 2);


    // run the motors
    StepperMotor__rotate(1, 0, right_rps, 1); // right stepper
    StepperMotor__rotate(2, 0, left_rps, 1); // left stepper
}


void DriveControl__turnLeft(float rate, float radius) {
    // check if the radius is at least equal to half the wheel distance (one wheel is stationary)
    if (radius < _DRIVECONTROL__WHEEL_DISTANCE / 2) {
        DriveControl__rotateCW(rate); // if so, just rotate in place
        return;
    }

    StepperMotor__init(); // reset steppers


    // find the speed of the right motor
    float right_rps = (rate * (radius + _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                      ((_DRIVECONTROL__WHEEL_DIAMETER / 2.0) * 3.1415 * 2);

    // find the speed of the left motor
    float left_rps = (rate * (radius - _DRIVECONTROL__WHEEL_DISTANCE / 2.0)) /
                     ((_DRIVECONTROL__WHEEL_DIAMETER / 2.0) * 3.1415 * 2);


    // run the motors
    StepperMotor__rotate(1, 0, right_rps, 1); // right stepper
    StepperMotor__rotate(2, 0, left_rps, 1); // left stepper
}