#ifndef TURRET_CONTROL_H_
#define TURRET_CONTROL_H_

void TurretControl__init();

void TurretControl__setTurretPosition(int position);

void TurretControl__setMotorSpeed_black();
void TurretControl__setMotorSpeed_white();
void TurretControl__disableMotor();
void __setMotorSpeed(float motor_speed);

void TurretControl__activateTrigger();
void __setTriggerFire();
void __setTriggerLoad();

#endif // TURRET_CONTROL_H_