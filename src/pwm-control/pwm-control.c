#include "pwm-control/pwm-control.h"

#include <xc.h>

#include "global-params.h"

void PWMControl__init1(float duty_cycle, float period)
{
    // CONFIGURE PWM1 USING OC1 (on pin 14)

    // Set period and duty cycle
    OC1RS = period;
    OC1R = duty_cycle;

    // Clear control bits
    OC1CON1 = 0;
    OC1CON2 = 0;

    // Configure OC1
    OC1CON1bits.OCTSEL = 0b111; // System (peripheral) clock as timing source
    OC1CON2bits.SYNCSEL = 0x1F; // Select OC1 as synchronization source
                                // (self synchronization) -- Although we
                                // selected the system clock to determine
                                // the rate at which the PWM timer increments,
                                // we could have selected a different source
                                // to determine when each PWM cycle initiates.
                                // From the FRM: When the SYNCSEL<4:0> bits
                                // (OCxCON2<4:0>) = 0b11111, they make the
                                // timer reset when it reaches the value of
                                // OCxRS, making the OCx module use its
                                // own Sync signal.
    OC1CON2bits.OCTRIG = 0;     // Synchronizes with OC1 source instead of
                                // triggering with the OC1 source
                                // "In Synchronous operation, the internal
                                // timer resets to zero when the source
                                // selected by the Trigger/Synchronization
                                // Source Selection (SYNCSEL) bits sends a
                                // Sync signal. In Trigger mode, the internal
                                // timer is held in the Reset state until the
                                // selected Trigger source sends a Sync
                                // signal." - Section 3.0 "Modes of Operation"
                                // "The synchronous operation of the timer is
                                // enabled when the OCTRIG bit = 0.... Whenever
                                // the selected module receives a
                                // synchronization signal, the timer will roll
                                // over to 0x0000 on the next positive edge of
                                // the selected clock." - Section 3.3.7
    OC1CON1bits.OCM = 0b110;    // Edge-aligned PWM mode
}

void PWMControl__init2(float duty_cycle, float period)
{
    // CONFIGURE PWM2 USING OC2 (on pin 4)
    _TRISB0 = 1;

    // Set period and duty cycle
    OC2RS = period;
    OC2R = duty_cycle;

    // Clear control bits
    OC2CON1 = 0;
    OC2CON2 = 0;

    // Configure OC1
    OC2CON1bits.OCTSEL = 0b111; // System (peripheral) clock as timing source
    OC2CON2bits.SYNCSEL = 0x1F; // Select OC1 as synchronization source
                                // (self synchronization) -- Although we
                                // selected the system clock to determine
                                // the rate at which the PWM timer increments,
                                // we could have selected a different source
                                // to determine when each PWM cycle initiates.
                                // From the FRM: When the SYNCSEL<4:0> bits
                                // (OCxCON2<4:0>) = 0b11111, they make the
                                // timer reset when it reaches the value of
                                // OCxRS, making the OCx module use its
                                // own Sync signal.
    OC2CON2bits.OCTRIG = 0;     // Synchronizes with OC1 source instead of
                                // triggering with the OC1 source
                                // "In Synchronous operation, the internal
                                // timer resets to zero when the source
                                // selected by the Trigger/Synchronization
                                // Source Selection (SYNCSEL) bits sends a
                                // Sync signal. In Trigger mode, the internal
                                // timer is held in the Reset state until the
                                // selected Trigger source sends a Sync
                                // signal." - Section 3.0 "Modes of Operation"
                                // "The synchronous operation of the timer is
                                // enabled when the OCTRIG bit = 0.... Whenever
                                // the selected module receives a
                                // synchronization signal, the timer will roll
                                // over to 0x0000 on the next positive edge of
                                // the selected clock." - Section 3.3.7
    OC2CON1bits.OCM = 0b110;    // Edge-aligned PWM mode
}

void PWMControl__init3(float duty_cycle, float period)
{
    // CONFIGURE PWM3 USING OC3 (on pin 5)
    _TRISB1 = 1;

    // Set period and duty cycle
    OC3RS = period;
    OC3R = duty_cycle;

    // Clear control bits
    OC3CON1 = 0;
    OC3CON2 = 0;

    // Configure OC1
    OC3CON1bits.OCTSEL = 0b111; // System (peripheral) clock as timing source
    OC3CON2bits.SYNCSEL = 0x1F; // Select OC1 as synchronization source
                                // (self synchronization) -- Although we
                                // selected the system clock to determine
                                // the rate at which the PWM timer increments,
                                // we could have selected a different source
                                // to determine when each PWM cycle initiates.
                                // From the FRM: When the SYNCSEL<4:0> bits
                                // (OCxCON2<4:0>) = 0b11111, they make the
                                // timer reset when it reaches the value of
                                // OCxRS, making the OCx module use its
                                // own Sync signal.
    OC3CON2bits.OCTRIG = 0;     // Synchronizes with OC1 source instead of
                                // triggering with the OC1 source
                                // "In Synchronous operation, the internal
                                // timer resets to zero when the source
                                // selected by the Trigger/Synchronization
                                // Source Selection (SYNCSEL) bits sends a
                                // Sync signal. In Trigger mode, the internal
                                // timer is held in the Reset state until the
                                // selected Trigger source sends a Sync
                                // signal." - Section 3.0 "Modes of Operation"
                                // "The synchronous operation of the timer is
                                // enabled when the OCTRIG bit = 0.... Whenever
                                // the selected module receives a
                                // synchronization signal, the timer will roll
                                // over to 0x0000 on the next positive edge of
                                // the selected clock." - Section 3.3.7
    OC3CON1bits.OCM = 0b110;    // Edge-aligned PWM mode
}

// -----------------------------------------------------------------------------

int _PWMControl__interruptRunning1 = 0;
int _PWMControl__interruptCycles1 = 0;
int _PWMControl__interruptCurrCycles1 = 0;

void __attribute__((interrupt, no_auto_psv)) _OC1Interrupt(void)
{
    // Set interrupt flag to 0
    _OC1IF = 0;

    if (_PWMControl__interruptCurrCycles1 < _PWMControl__interruptCycles1)
    {
        _PWMControl__interruptCurrCycles1++;
        _PWMControl__interruptRunning1 = 1;
    } else
    {
        _PWMControl__interruptRunning1 = 0;
        _OC1IE = 0;     // Disable OC1 interrupt
    }

}

void PWMControl__setInterrupt1(int num_cycles)
{
    _PWMControl__interruptRunning1 = 1;
    _PWMControl__interruptCycles1 = num_cycles;
    _PWMControl__interruptCurrCycles1 = 0;

    _OC1IP = 4;     // Select OC1 interrupt priority
    _OC1IE = 1;     // Enable OC1 interrupt
    _OC1IF = 0;     // Clear OC1 interrupt flag
}

int PWMControl__getInterruptState1()
{
    return _PWMControl__interruptRunning1;
}


int _PWMControl__interruptRunning2 = 0;
int _PWMControl__interruptCycles2 = 0;
int _PWMControl__interruptCurrCycles2 = 0;

void __attribute__((interrupt, no_auto_psv)) _OC2Interrupt(void)
{
    // Set interrupt flag to 0
    _OC2IF = 0;

    if (_PWMControl__interruptCurrCycles2 < _PWMControl__interruptCycles2)
    {
        _PWMControl__interruptCurrCycles2++;
        _PWMControl__interruptRunning2 = 1;
    } else
    {
        _PWMControl__interruptRunning2 = 0;
        _OC2IE = 0;     // Disable OC2 interrupt
    }

}

void PWMControl__setInterrupt2(int num_cycles)
{
    _PWMControl__interruptRunning2 = 1;
    _PWMControl__interruptCycles2 = num_cycles;
    _PWMControl__interruptCurrCycles2 = 0;

    _OC2IP = 4;     // Select OC2 interrupt priority
    _OC2IE = 1;     // Enable OC2 interrupt
    _OC2IF = 0;     // Clear OC2 interrupt flag
}

int PWMControl__getInterruptState2()
{
    return _PWMControl__interruptRunning2;
}


int _PWMControl__interruptRunning3 = 0;
int _PWMControl__interruptCycles3 = 0;
int _PWMControl__interruptCurrCycles3 = 0;

void __attribute__((interrupt, no_auto_psv)) _OC3Interrupt(void)
{
    // Set interrupt flag to 0
    _OC3IF = 0;

    if (_PWMControl__interruptCurrCycles3 < _PWMControl__interruptCycles3)
    {
        _PWMControl__interruptCurrCycles3++;
        _PWMControl__interruptRunning3 = 1;
    } else
    {
        _PWMControl__interruptRunning3 = 0;
        _OC3IE = 0;     // Disable OC3 interrupt
    }

}

void PWMControl__setInterrupt3(int num_cycles)
{
    _PWMControl__interruptRunning3 = 1;
    _PWMControl__interruptCycles3 = num_cycles;
    _PWMControl__interruptCurrCycles3 = 0;

    _OC3IP = 4;     // Select OC3 interrupt priority
    _OC3IE = 1;     // Enable OC3 interrupt
    _OC3IF = 0;     // Clear OC3 interrupt flag
}

int PWMControl__getInterruptState3()
{
    return _PWMControl__interruptRunning3;
}