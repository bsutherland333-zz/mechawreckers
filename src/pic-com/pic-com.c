/*
 * Source code for pic com library
 */

#include "timer/timer.h"

#include "pic-com/pic-com.h"

#define TIMER_NUMBER 1
#define FLAG_DURATION 0.1

int __commPin = 0;

void PicCom__init(int pin)
{
    __commPin = pin;
    switch (__commPin)
    {
        case 2:
            _TRISA0 = 1;
            _ANSA0 = 0;
            break;
        case 3:
            _TRISA1 = 1;
            _ANSA1 = 0;
            break;
        case 4:
            _TRISB0 = 1;
            _ANSB0 = 0;
            break;
        case 5:
            _TRISB1 = 1;
            _ANSB1 = 0;
            break;
        case 6:
            _TRISB2 = 1;
            _ANSB2 = 0;
            break;
        case 7:
            _TRISA2 = 1;
            _ANSA2 = 0;
            break;
        case 8:
            _TRISA3 = 1;
            _ANSA3 = 0;
            break;
        case 9:
            _TRISB4 = 1;
            _ANSB4 = 0;
            break;
        case 10:
            _TRISA4 = 1;
            // _ANSA4 = 0;
            break;
        case 11:
            _TRISB7 = 1;
            // _ANSB7 = 0;
            break;
        case 12:
            _TRISB8 = 1;
            // _ANSB8 = 0;
            break;
        case 13:
            _TRISB9 = 1;
            // _ANSB9 = 0;
            break;
        case 14:
            _TRISA6 = 1;
            // _ANSA6 = 0;
            break;
        case 15:
            _TRISB12 = 1;
            _ANSB12 = 0;
            break;
        case 16:
            _TRISB13 = 1;
            _ANSB13 = 0;
            break;
        case 17:
            _TRISB14 = 1;
            _ANSB14 = 0;
            break;
        case 18:
            _TRISB15 = 1;
            _ANSB15 = 0;
            break;
        default:
            break;
    }
}

int PicCom__getStatus()
{
    int status = 0;

    switch (__commPin)
    {
        case 2:
            status = _RA0;
            break;
        case 3:
            status = _RA1;
            break;
        case 4:
            status = _RB0;
            break;
        case 5:
            status = _RB1;
            break;
        case 6:
            status = _RB2;
            break;
        case 7:
            status = _RA2;
            break;
        case 8:
            status = _RA3;
            break;
        case 9:
            status = _RB4;
            break;
        case 10:
            status = _RA4;
            break;
        case 11:
            status = _RB7;
            break;
        case 12:
            status = _RB8;
            break;
        case 13:
            status = _RB9;
            break;
        case 14:
            status = _RA6;
            break;
        case 15:
            status = _RB12;
            break;
        case 16:
            status = _RB13;
            break;
        case 17:
            status = _RB14;
            break;
        case 18:
            status = _RB15;
            break;
        default:
            break;
    }
    return status;
}

void PicCom__sendFlag()
{
    switch (__commPin)
    {
        case 2:
            _TRISA0 = 0;
            _LATA0 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATA0 = 0;
            _TRISA0 = 1;
            break;
        case 3:
            _TRISA1 = 0;
            _LATA1 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATA1 = 0;
            _TRISA1 = 1;
            break;
        case 4:
            _TRISB0 = 0;
            _LATB0 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB0 = 0;
            _TRISB0 = 1;
            break;
        case 5:
            _TRISB1 = 0;
            _LATB1 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB1 = 0;
            _TRISB1 = 1;
            break;
        case 6:
            _TRISB2 = 0;
            _LATB2 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB2 = 0;
            _TRISB2 = 1;
            break;
        case 7:
            _TRISA2 = 0;
            _LATA2 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATA2 = 0;
            _TRISA2 = 1;
            break;
        case 8:
            _TRISA3 = 0;
            _LATA3 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATA3 = 0;
            _TRISA3 = 1;
            break;
        case 9:
            _TRISB4 = 0;
            _LATB4 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB4 = 0;
            _TRISB4 = 1;
            break;
        case 10:
            _TRISA4 = 0;
            _LATA4 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATA4 = 0;
            _TRISA4 = 1;
            break;
        case 11:
            _TRISB7 = 0;
            _LATB7 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB7 = 0;
            _TRISB7 = 1;
            break;
        case 12:
            _TRISB8 = 0;
            _LATB8 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB8 = 0;
            _TRISB8 = 1;
            break;
        case 13:
            _TRISB9 = 0;
            _LATB9 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB9 = 0;
            _TRISB9 = 1;
            break;
        case 14:
            _TRISA6 = 0;
            _LATA6 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATA6 = 0;
            _TRISA6 = 1;
            break;
        case 15:
            _TRISB12 = 0;
            _LATB12 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB12 = 0;
            _TRISB12 = 1;
            break;
        case 16:
            _TRISB13 = 0;
            _LATB13 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB13 = 0;
            _TRISB13 = 1;
            break;
        case 17:
            _TRISB14 = 0;
            _LATB14 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB14 = 0;
            _TRISB14 = 1;
            break;
        case 18:
            _TRISB15 = 0;
            _LATB15 = 1;
            Timer__set(TIMER_NUMBER, FLAG_DURATION);
            Timer__waitForCompletion(TIMER_NUMBER);
            _LATB15 = 0;
            _TRISB15 = 1;
            break;
        default:
            break;
    }
}