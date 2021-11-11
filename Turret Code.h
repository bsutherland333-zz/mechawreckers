/*
 * File:   PWM_TEST.c
 * Author: Adam Hale
 *
 * Created on November 8, 2021, 8:09 PM
 */


#include "xc.h"

#pragma config FNOSC = FRCDIV

void Turret(float pos);

void Trigger(float pos);

void Motor(float DC);

//Delay Function
void delay(int s)
{
    int k = 0;
    while (k < s)
        k++;
}

void __attribute__((interrupt, no_auto_psv)) _CNInterrupt(void)
{
    /* Working code is in the main function right now
	To enable communication between PICs, place the code to
	be executed when turret is triggered here. */
    _CNIF = 0;    //Clear interrupt flag
}

int main(void)
{
    _RCDIV = 0b011;    //Postscale by 8

    TRISA = 0x00;
    TRISB = 0x0000;    //RB1 needs to be set to 1 for CN to work

    //int trig = 0;

    _CN8IE = 1;     //Enable CN Interrupt on Pin 5 (RB1)
    _CN8PUE = 0;    //Disable pull up resistor
    _CNIP = 1;      //Set interrupt priority
    _CNIE = 1;      //Enable CN Interrupts
    _CNIF = 0;      //Clear CN Interrupt flag

    while (1)
    {
        Turret(90);     //90 degrees position
        Trigger(1);    //0 - hold ball, 1 - launch ball
        //Motor(.5);        //motor to 10%
    }
    return 0;
}

void Turret(float pos)
{
    float freq = ((4000000 / 8) / 50) - 1;    //servo frequency is 50 Hz
    float DC = (pos / 1800) + .025;    //Map angle to Duty Cycle ( 0 -> ,025) (180 -> .125)
    DC = (freq + 1) * DC;        //Calculate DC from provided angle

    //Servo rotation ~ 205 degrees, 50Hz freq and <.02-.13> DC .075DC center

    OC1RS = freq;    //output PWM freq
    OC1R = DC;    //Output PWM w/ DC

    OC1CON1 = 0;
    OC1CON2 = 0;
    OC1CON1bits.OCTSEL = 0b111;
    OC1CON2bits.SYNCSEL = 0x1F;
    OC1CON2bits.OCTRIG = 0;
    OC1CON1bits.OCM = 0b110;

}

void Trigger(float pos)
{
    float angle;
    if (pos == 1)
    {
        angle = 125;
    }    //adjust firing servo position here
    else
    {
        angle = 70;
    }        //adjust holding servo position here

    float freq = ((4000000 / 8) / 50) - 1;    //Servo frequency is 50 Hz
    float DC = (angle / 1800) + .025;    //Map angle to Duty Cycle ( 0 -> ,025) (180 -> .125)
    DC = (freq + 1) * DC;        //Calculate DC from provided angle

    //Servo rotation ~ 205 degrees, 50Hz freq and <.02-.13> DC .075DC center

    OC2RS = freq;
    OC2R = DC;

    OC2CON1 = 0;
    OC2CON2 = 0;
    OC2CON1bits.OCTSEL = 0b111; // System (peripheral) clock as timing source
    OC2CON2bits.SYNCSEL = 0x1F; // Select OC1 as synchronization source
    OC2CON2bits.OCTRIG = 0;     // Synchronizes with OC1 source instead of
    OC2CON1bits.OCM = 0b110;    // Edge-aligned PWM mode

}

void Motor(float DC)
{
    float freq = ((4000000 / 8) / 1000) - 1;    //Motor frequency 1000Hz
    DC = (freq + 1) * DC;

    OC3RS = freq;
    OC3R = DC;

    OC3CON1 = 0;
    OC3CON2 = 0;

    OC3CON1bits.OCTSEL = 0b111; // System (peripheral) clock as timing source
    OC3CON2bits.SYNCSEL = 0x1F; // Select OC1 as synchronization source
    OC3CON2bits.OCTRIG = 0;     // Synchronizes with OC1 source instead of
    OC3CON1bits.OCM = 0b110;    // Edge-aligned PWM mode

}