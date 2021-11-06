/* Mechawreckers    MEEN 330   Oct. 2021 2

main.c -- the code that the robot executes
*/

#include <xc.h>
#include "analog-read/analog-read.h"
#include "drive-control/drive-control.h"

#pragma config FNOSC = FRCDIV  // Update value in global-params if changed
#pragma config OSCIOFNC = OFF // enable pin 8,10
#pragma config SOSCSRC = DIG // enable pin 9

#define THRESHOLD 500


enum STATE {SEEKING,  FOUND}; // state in our state machine


void main_init();

int main(int argc, char **argv)
{
    main_init();

    DriveControl__init();
    
    
    analog_init();
    setup_analog(14);
    
    int current_ir_val = 0;
    int prev_ir_val = 0;
    
    // begin state machine
    
    int state = FOUND;
    
    while(1)
    {
        // get all our info
        prev_ir_val = current_ir_val;
        
        double ave = 0;
        for(int i  = 0; i < 100; i++)
        {
            ave += (double)read_analog_pin(8)/100;
        }
        
        current_ir_val = (int)ave; // current val is an average of 1000 readings
        
        // choose current state
        if(state == SEEKING)
        {
            if(current_ir_val >= THRESHOLD && prev_ir_val >= current_ir_val) // if we're above our limit and decreasing
            {
                DriveControl__stopMovement();
                _LATB2 = 1;
                state = FOUND;
            }
        }
        else if(state == FOUND)
        {
            if(current_ir_val < THRESHOLD) // if we lose track of the LED, then transition
            {
                DriveControl__rotateCW(2*3.1415/8);
                _LATB2 = 0;
                state = SEEKING;
            }
        }
    }

    return 0;
}

void main_init()
{
    // Sets all pins to be output
    TRISA = 0;
    TRISB = 0;
    // Sets all pins to be digital
    ANSA = 0;
    ANSB = 0;
}