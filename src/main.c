/* Mechawreckers    MEEN 330   Oct. 2021 2

main.c -- the code that the robot executes
*/


#include <xc.h>

#include "analog-read/analog-read.h"




#pragma config FNOSC = FRCDIV  // Update value in global-params if changed

int main(int argc, char **argv) 
{
    _RCDIV = 0b101;
    // Sets all pin registers to 0
    TRISA = 0;
    TRISB = 0;
    ANSA = 0;
    ANSB = 0;
    
    analog_init();
  
    setup_analog(0);
    setup_analog(1);
    setup_analog(2);
    setup_analog(3);
    

    while (1)
    {
        if(read_analog_pin(5) > 4095/2)
        {
            _LATA2 = 1;
        }
        else
        {
            _LATA2 = 1;
        }
    }
    return 0;
}