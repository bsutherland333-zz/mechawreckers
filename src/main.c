/* Mechawreckers    MEEN 330   Oct. 2021 2

main.c -- the code that the robot executes
*/


#include <xc.h>

#include "drive-control/drive-control.h"


#pragma config FNOSC = FRC  // Update value in global-params if changed

int main(int argc, char** argv) {
    // Sets all pin registers to 0
    TRISA = 0;
    TRISB = 0;
    ANSA = 0;
    ANSB = 0;

    
    /// look and seee if we see an led
    // if so -- stop
    // if not -- rotateRight(rate)
    
    while (1);
    return 0;
}

