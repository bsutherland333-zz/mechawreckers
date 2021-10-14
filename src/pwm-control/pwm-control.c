#include"pwm-control.h"

void setupPWM14(int dutyCyCONTROcle, int period)
{
    //-----------------------------------------------------------
    // CONFIGURE PWM1 USING OC1 (on pin 14)
    
    

    _TRISA6 = 1;
    
    
    // Set period and duty cycle
    // CHOOSE PERIOD AND DUTY CYCLE HERE
    
    OC1RS = period;
    OC1R = dutyCycle;

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


void setupPWM4(int dutyCycle, int period)
{
    //-----------------------------------------------------------
    // CONFIGURE PWM1 USING OC1 (on pin 14)
    

    _TRISB0 = 1;
    
    
    // Set period and duty cycle
    // CHOOSE PERIOD AND DUTY CYCLE HERE
    
    OC2RS = period;
    OC2R = dutyCycle;

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

void setupPWM5(int dutyCycle, int period)
{
    //-----------------------------------------------------------
    // CONFIGURE PWM1 USING OC1 (on pin 14)
    

    _TRISB1 = 1;
    
    
    // Set period and duty cycle
    // CHOOSE PERIOD AND DUTY CYCLE HERE
    
    OC3RS = period;
    OC3R = dutyCycle;

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