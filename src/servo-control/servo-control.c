#include "servo-control/servo-control.h"

#include "pwm-control/pwm-control.h"
#include "global-params.h"

// Hardware defined values for servos.
// Duty cycle needs to span from 0.025ms (min angle) to 0.125ms (max angle) at 50hz.
#define SERVO_FREQUENCY 50 // hz
#define DUTY_CYCLE_OFFSET 0.025 // Used to offset duty cycle to required duty cycle for zero
#define DUTY_CYCLE_SCALAR 1800.0 // Used to scale degrees to duty cycle equivalent

void ServoControl__setAngle(int pwm_register, float angle)
{
    float duty_cycle = ((angle / DUTY_CYCLE_SCALAR) + DUTY_CYCLE_OFFSET) * (CLOCK_HZ / SERVO_FREQUENCY);
    float period = (CLOCK_HZ / SERVO_FREQUENCY) - 1;

    switch (pwm_register)
    {
        case 1:
            PWMControl__init1(duty_cycle, period);
            break;
        case 2:
            PWMControl__init2(duty_cycle, period);
            break;
    }
}

void ServoControl__disableServo(int pwm_register)
{
    switch (pwm_register)
    {
        case 1:
            PWMControl__init1(0, 0);
            break;
        case 2:
            PWMControl__init2(0, 0);
            break;
    }
}