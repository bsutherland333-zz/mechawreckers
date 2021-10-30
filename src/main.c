/* Mechawreckers    MEEN 330   Oct. 2021 2

main.c -- the code that the robot executes
*/

#include <xc.h>
#include "analog-read/analog-read.h"
#include "drive-control/drive-control.h"

#pragma config FNOSC = FRCDIV  // Update value in global-params if changed

void main_init();

int main(int argc, char **argv)
{
    main_init();

    DriveControl__init();
    DriveControl__rotateCW_dist(90, 180);
    while (DriveControl__checkDriveStatus());

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