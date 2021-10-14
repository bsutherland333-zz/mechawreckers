/* 
 * Class for controlling stepper motors.
 * 
 * The pic24 does not allow for an address to be passed as a function argument,
 * so motor outputs will need to be pre-configured in this class.
 */

#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

// Hardware-defined values
#define _STEPPERMOTOR__MAX_HZ 500.0  // hz
#define _STEPPERMOTOR__STEPS_PER_ROTATION 200.0  // steps
#define _STEPPERMOTOR__STEP_SIZE_1 0.5
#define _STEPPERMOTOR__STEP_SIZE_2 0.5
#define _STEPPERMOTOR__DIRECTION_PIN_1 _LATA0
#define _STEPPERMOTOR__DIRECTION_PIN_2 _LATA1

void StepperMotor__init();
void StepperMotor__rotate(int motor, int direction, float speed, float rotations);

void _StepperMotor__setDirection(int motor, int direction);
void _StepperMotor__setSpeed(int motor, float speed);
void _StepperMotor__setRotations(int motor, float rotations);
void StepperMotor__completeRotations();

#endif
