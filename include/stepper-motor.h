/* 
 * Class for controlling stepper motors.
 * The pic24 does not allow for an address to be passed as a function argument,
 * so motor outputs will need to be pre-configured in this class.
 */

#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include <xc.h>

// Hardware-defined values
#define _StepperMotor__max_hz 500.0  // hz
#define _StepperMotor__steps_per_rotation 200.0  // steps
#define _StepperMotor__step_size_1 0.5
#define _StepperMotor__step_size_2 0.5

void StepperMotor__init();
void StepperMotor__set_direction(int motor, int direction);
void StepperMotor__set_speed(int motor, float speed);
void StepperMotor__rotate(int motor, float rotations);

#endif
