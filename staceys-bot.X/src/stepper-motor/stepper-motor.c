#include "stepper-motor/stepper-motor.h"

#include <xc.h>

#include "global-params.h"
#include "pwm-control/pwm-control.h"

void StepperMotor__init() {
    // Initialize PWM for motor control
    PWMControl__init1(0, 0);
    PWMControl__init2(0, 0);
}


void StepperMotor__rotate(int motor, int direction, float speed, 
        float rotations) {
    _StepperMotor__setDirection(motor, direction);
    _StepperMotor__setSpeed(motor, speed);
    _StepperMotor__setRotations(motor, rotations);
}

void _StepperMotor__setDirection(int motor, int direction) {
    // direction = 0 is clockwise, direction = 1 is counterclockwise
    
    switch (motor) {
        case 1:
            if (direction == 0) {
                _STEPPERMOTOR__DIRECTION_PIN_1 = 1;
            } else if (direction == 1) {
                _STEPPERMOTOR__DIRECTION_PIN_1 = 0;
            }
            break;
        case 2:
            if (direction == 0) {
                _STEPPERMOTOR__DIRECTION_PIN_2 = 1;
            } else if (direction == 1) {
                _STEPPERMOTOR__DIRECTION_PIN_2 = 0;
            }
            break;
    }
}

void _StepperMotor__setSpeed(int motor, float speed) {
    // speed is in rotations per second
    float steps_per_sec = 0.0;
    
    switch (motor) {
        case 1:
            steps_per_sec = speed * _STEPPERMOTOR__STEPS_PER_ROTATION * 
                                  (1 / _STEPPERMOTOR__STEP_SIZE_1);

            // Saturate speed
            if (steps_per_sec > _STEPPERMOTOR__MAX_HZ) {
                steps_per_sec = _STEPPERMOTOR__MAX_HZ;
            }

            // Set PWM hz to correct speed and duty cycle to 50%
            OC1RS = (CLOCK_HZ / steps_per_sec) - 1;
            OC1R = ((CLOCK_HZ / steps_per_sec) - 1) * 0.5;
            
            break;
        case 2:
            steps_per_sec = speed * _STEPPERMOTOR__STEPS_PER_ROTATION * 
                                  (1 / _STEPPERMOTOR__STEP_SIZE_2);

            // Saturate speed
            if (steps_per_sec > _STEPPERMOTOR__MAX_HZ) {
                steps_per_sec = _STEPPERMOTOR__MAX_HZ;
            }

            // Set PWM hz to correct speed and duty cycle to 50%
            OC2RS = (CLOCK_HZ / steps_per_sec) - 1;
            OC2R = ((CLOCK_HZ / steps_per_sec) - 1) * 0.5;
            
            break;
    }
}

void _StepperMotor__setRotations(int motor, float rotations) {
    if (rotations < 0.001) {
        return;
    }
    
    int num_steps = 0;
    
    switch (motor) {
        case 1:
            num_steps = _STEPPERMOTOR__STEPS_PER_ROTATION * rotations *
                (1 / _STEPPERMOTOR__STEP_SIZE_1);
            PWMControl__setInterrupt1(num_steps);
            break;
        case 2:
            num_steps = _STEPPERMOTOR__STEPS_PER_ROTATION * rotations *
                (1 / _STEPPERMOTOR__STEP_SIZE_2);
            PWMControl__setInterrupt2(num_steps);
            break;
    }
}

void StepperMotor__completeRotations() {
    while ((PWMControl__getInterruptState1() + 
            PWMControl__getInterruptState2()) > 0) {
        
        if (PWMControl__getInterruptState1() == 0) {
            _StepperMotor__setSpeed(1, 0);
        }
        if (PWMControl__getInterruptState2() == 0) {
            _StepperMotor__setSpeed(2, 0);
        }
    }   
    
    _StepperMotor__setSpeed(1, 0);
    _StepperMotor__setSpeed(2, 0);
}
