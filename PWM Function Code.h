/*
 * File:   PWM_TEST.c
 * Author:
 *
 * Created on November 8, 2021, 8:09 PM
 */


#include "xc.h"

#pragma config FNOSC = FRCDIV

void PWM1(float freq, float DC);

int main(void)
{
    _RCDIV = 0b011;

    TRISA = 0x00;
    TRISB = 0x0000;

    while (1)
    {
        PWM1(50, .025);
    }
    return 0;
}

void PWM1(float freq, float DC)
{
    freq = ((4000000 / 8) / freq) - 1;
    DC = (freq + 1) * DC;

    //Servo rotation ~ 205 degrees, 50Hz freq and <.02-.13> DC .075DC center

    OC1RS = freq;
    OC1R = DC;

    OC1CON1 = 0;
    OC1CON2 = 0;

    // Configure OC1
    OC1CON1bits.OCTSEL = 0b111; // System (peripheral) clock as timing source
    OC1CON2bits.SYNCSEL = 0x1F; // Select OC1 as synchronization source
    OC1CON2bits.OCTRIG = 0;     // Synchronizes with OC1 source instead of
    OC1CON1bits.OCM = 0b110;    // Edge-aligned PWM mode

}