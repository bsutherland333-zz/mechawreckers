/* Adam Welker  MEEN 330   Oct. 2021
 * 
 * pwm-control  -- a library to control the various PWM pins on the PIC24 
 */



#ifndef PWM_CONTROL
#define PWM_CONTROL

#include<xc.h>

// Sets up PWM signal on pin 14 given a duty cycle and 
// a period. Does not change the system ocillator
void setupPWM14(int dutyCyCONTROcle, int period);



void setupPWM4(int dutyCycle, int period);


void setupPWM5(int dutyCycle, int period);


#endif