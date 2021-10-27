/*
 * Class for controlling stepper motors.
 *
 * The pic24 does not allow for an address to be passed as a function argument,
 * so motor outputs will need to be pre-configured in this class.
 *
 * Motor numbers are defined by the PWM signal they use. (i.e. motor 1 uses OC1 (pin 14)).
 *
 * Currently the right motor is motor 1 and the left motor is motor 2.
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
void StepperMotor__init();

// This function defines motor rotation speed (rotations per second), direction (0 is clockwise, 1 is counter-clockwise,
// and distance (total rotations).
// This will run continually until stopped with completeRotations or stopMotion.
void StepperMotor__rotate(int motor, int direction, float speed, float rotations);

// This will stop each individual motor once the desired number of rotations has been completed. Motors do not need to
// stop all at once, they can stop individually.
// Note: THIS IS BLOCKING CODE. Do not use for conditional movement.
void StepperMotor__completeRotations();

// This will stop each motor immediately regardless of the number of completed rotations. Is not blocking code and is
// useful for conditional movement.
void StepperMotor__stopMotion();

// ---- Private class functions ----

void _StepperMotor__setDirection(int motor, int direction);
void _StepperMotor__setSpeed(int motor, float speed);
void _StepperMotor__setRotations(int motor, float rotations);

#endif