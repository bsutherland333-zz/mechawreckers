/* Adam Welker  MEEN 330   Oct. 2021
 *
 * pwm-control  -- a library to control the various PWM pins on the PIC24
 *
 * NOTE: If the pic is not outputting a pwm signal as you think it should, your period or duty-cycle may be too large
 *  to store in its 16-bit memory. Increasing the post-scalar will make the values smaller and therefore more
 *  manageable.
 */

#ifndef PWM_CONTROL_H_
#define PWM_CONTROL_H_

void PWMControl__init1(float duty_cycle, float period);
void PWMControl__init2(float duty_cycle, float period);
void PWMControl__init3(float duty_cycle, float period);

// Use for created and monitoring PWM interrupts.
// getInterruptState will return 1 while the interrupt is still running and will return 0 once the interrupt has reached
// the number of cycles specified in setInterrupt.
void PWMControl__setInterrupt1(int num_cycles);
int PWMControl__getInterruptState1();

void PWMControl__setInterrupt2(int num_cycles);
int PWMControl__getInterruptState2();

void PWMControl__setInterrupt3(int num_cycles);
int PWMControl__getInterruptState3();

#endif