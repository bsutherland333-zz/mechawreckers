/*
 * Class for controlling stepper motors.
 *
 * The pic24 does not allow for an address to be passed as a function argument,
 * so motor outputs will need to be pre-configured in this class.
 *
 * Motor numbers are defined by the PWM signal they use. (i.e. motor 1 uses OC1 (pin 14)).
 *
 * Currently the right motor is motor 1 and the left motor is motor 2.
 *
 * NOTE: Motors will not run if the requested speed it too low.
 *
 * TODO: If someone gets bored they should switch this and its dependent code to use radians instead of rotations.
 * TODO: This library currently sets the PWM parameters in the setSpeed function directly, it should be using the PWM
 *  control library.
 * TODO: This library has not been tested since the post-scalar has been changed. It should be fine, but a quick
 *  verification would be good.
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

// ---- Motor Control ----

// Motors must be initialized before they are used. You can re-initialize them as many times as you like.
//  Using a motor without initialization may result in unpredictable behavior
void StepperMotor__init();

// This function defines motor rotation speed (rotations per second), direction (0 is clockwise, 1 is counter-clockwise,
//  and distance (total rotations).
// This will run continually until stopped with completeRotations or stopMotion.
void StepperMotor__rotate(int motor, int direction, float speed, float rotations);

// This will stop each motor immediately regardless of the number of completed rotations. Is not blocking code and is
//  useful for conditional movement.
void StepperMotor__stopMotion(int motor);

// This function will do two things:
//  - Check if motor needs to stop and will stop the motor if the PWM interrupt has reached it finished state.
//  - Will return 1 if motor is still spinning, and return 0 if it is not.
int StepperMotor__checkMotorStatus(int motor);

// ---- Private class functions ----

void _StepperMotor__setDirection(int motor, int direction);
void _StepperMotor__setSpeed(int motor, float speed);
void _StepperMotor__setRotations(int motor, float rotations);

#endif