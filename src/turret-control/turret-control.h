#ifndef TURRET_CONTROL_H_
#define TURRET_CONTROL_H_

// Used to initialize turret.
void TurretControl__init();

// Sets turret position at position 1, 2. or 3. 1 is CCW most position, 3 is CW most position;
void TurretControl__setTurretPosition(int position);

// Sets current motor speed. Note: this only sets the duty cycle of the PWM signal, so the motor response will not
//  be perfectly linear with the set value.
void TurretControl__setMotorSpeed_black();
void TurretControl__setMotorSpeed_white();
void TurretControl__disableMotor();
void __setMotorSpeed(float motor_speed);

// Used for firing the ball. Use activateTrigger to drop a ball into the shooter.
void TurretControl__activateTrigger();
void __setTriggerFire();
void __setTriggerLoad();

#endif // TURRET_CONTROL_H_