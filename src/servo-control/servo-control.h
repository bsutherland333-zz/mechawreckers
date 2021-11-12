#ifndef SERVO_CONTROL_H_
#define SERVO_CONTROL_H_

// Sets servo to requested angle. Servo will hold position once set.
void ServoControl__setAngle(int pwm_register, float angle);

// Disables servo after being set, allowing it to move freely once again.
void ServoControl__disableServo(int pwm_register);

#endif  // SERVO_CONTROL_H_