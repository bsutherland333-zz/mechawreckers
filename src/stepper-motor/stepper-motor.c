#include "stepper-motor.h"

void StepperMotor__init() {
    // Configure motor 1 using OC1
    OC1CON1 = 0;
    OC1CON2 = 0;
    OC1CON1bits.OCTSEL = 0b111;
    OC1CON2bits.SYNCSEL = 0x1F;
    OC1CON2bits.OCTRIG = 0;
    OC1CON1bits.OCM = 0b110;
    
    // Configure motor 2 using OC2
    OC2CON1 = 0;
    OC2CON2 = 0;
    OC2CON1bits.OCTSEL = 0b111;
    OC2CON2bits.SYNCSEL = 0x1F;
    OC2CON2bits.OCTRIG = 0;
    OC2CON1bits.OCM = 0b110;
    
    // Set default values
    StepperMotor__set_direction(1, 0);
    StepperMotor__set_direction(2, 0);
    StepperMotor__set_speed(1, 1);
    StepperMotor__set_speed(2, 1);
}

void StepperMotor__set_direction(int motor, int direction) {
    // direction = 0 is clockwise, direction = 1 is counterclockwise
    
    switch (motor) {
        case 1:
            if (direction == 0) {
                _LATA1 = 1;
            } else if (direction == 1) {
                _LATA1 = 0;
            }
            break;
        case 2:
            if (direction == 0) {
                _LATA0 = 1;
            } else if (direction == 1) {
                _LATA0 = 0;
            }
            break;
    }
}

void StepperMotor__set_speed(int motor, float speed) {
    // speed is in rotations per second
    float steps_per_sec = 0.0;
    
    switch (motor) {
        case 1:
            steps_per_sec = speed * _StepperMotor__steps_per_rotation * 
                                  (1 / _StepperMotor__step_size_1);

            // Saturate speed
            if (steps_per_sec > _StepperMotor__max_hz) {
                steps_per_sec = _StepperMotor__max_hz;
            }

            // Set PWM hz to correct speed and duty cycle to 50%
            OC1RS = (4000000 / steps_per_sec) - 1;
            OC1R = ((4000000 / steps_per_sec) - 1) * 0.5;
            
            break;
        case 2:
            steps_per_sec = speed * _StepperMotor__steps_per_rotation * 
                                  (1 / _StepperMotor__step_size_2);

            // Saturate speed
            if (steps_per_sec > _StepperMotor__max_hz) {
                steps_per_sec = _StepperMotor__max_hz;
            }

            // Set PWM hz to correct speed and duty cycle to 50%
            OC2RS = (4000000 / steps_per_sec) - 1;
            OC2R = ((4000000 / steps_per_sec) - 1) * 0.5;
            
            break;
    }
}

void StepperMotor__rotate(int motor, float rotations) {
    
}