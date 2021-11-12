#include "timer/timer.h"

#include <xc.h>

#include "global-params.h"

#define TIMER_SCALAR 64

int timer_1_status = 0;
int timer_2_status = 0;

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    _T1IF = 0;  // Clear timer1 interrupt flag
    timer_1_status = 0;
}

void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void)
{
    _T2IF = 0;  // Clear timer1 interrupt flag
    timer_2_status = 0;
}

void Timer__set(int timer, float duration)
{
    switch (timer)
    {
        case 1:
            // Configure Timer1 using T1CON register
            T1CONbits.TON = 1;      // Sets timer1 on
            T1CONbits.TCS = 0;      // Use internal clock
            T1CONbits.TCKPS = 0b10; // Pre-scaling to 1/64. Make sure to update all scalar values if changed
            TMR1 = 0;               // Sets timer to 0

            // Configure Timer1 interrupt
            _T1IP = 4;                          // Sets timer priority
            _T1IF = 0;                          // Clears interrupt flag
            _T1IE = 1;                          // Enables interrupt
            PR1 = CLOCK_HZ / TIMER_SCALAR * duration;    // Sets time to trigger interrupt

            timer_1_status = 1;

            break;
        case 2:
            // Configure Timer1 using T1CON register
            T2CONbits.TON = 1;      // Sets timer1 on
            T2CONbits.TCS = 0;      // Use internal clock
            T2CONbits.TCKPS = 0b10; // Pre-scaling to 1/64. Make sure to update all scalar values if changed
            TMR2 = 0;               // Sets timer to 0

            // Configure Timer1 interrupt
            _T2IP = 4;                          // Sets timer priority
            _T2IF = 0;                          // Clears interrupt flag
            _T2IE = 1;                          // Enables interrupt
            PR2 = CLOCK_HZ / TIMER_SCALAR * duration;    // Sets time to trigger interrupt

            timer_2_status = 1;

            break;
    }
}

int Timer__status(int timer)
{
    switch (timer)
    {
        case 1:
            return timer_1_status;
        case 2:
            return timer_2_status;
        default:
            return 0;
    }
}

void Timer__waitForCompletion(int timer)
{
    while (Timer__status(timer));
}