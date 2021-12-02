#include "turret-control/turret-control.h"

#include "servo-control/servo-control.h"
#include "pwm-control/pwm-control.h"
#include "global-params.h"
#include "timer/timer.h"

#define MOTOR_FREQUENCY 1000.0

void TurretControl__init()
{
    TurretControl__setTurretPosition(2);
    __setTriggerLoad();
}

void TurretControl__setTurretPosition(int position)
{
    switch (position)
    {
        case 1:
            ServoControl__setAngle(1, 175);
            break;
        case 2:
            ServoControl__setAngle(1, 90);
            break;
        case 3:
            ServoControl__setAngle(1, 0);
            break;
    }
}

void TurretControl__setMotorSpeed_black()
{
    __setMotorSpeed(0.47);
}

void TurretControl__setMotorSpeed_white()
{
    __setMotorSpeed(0.55);
}

void TurretControl__disableMotor()
{
    __setMotorSpeed(0.0);
}

void __setMotorSpeed(float motor_speed)
{
    float period = CLOCK_HZ / MOTOR_FREQUENCY - 1;
    float duty_cycle = CLOCK_HZ / MOTOR_FREQUENCY * motor_speed;

    PWMControl__init3(duty_cycle, period);
}

void TurretControl__activateTrigger()
{
    __setTriggerFire();
    Timer__set(1, 0.5);
    Timer__waitForCompletion(1);
    __setTriggerLoad();
}

void __setTriggerFire()
{
    ServoControl__setAngle(2, 70);
}

void __setTriggerLoad()
{
    ServoControl__setAngle(2, 125);
}