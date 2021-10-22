#include <xc.h>

#include "drive-control/drive-control.h"


#pragma config FNOSC = FRC  // Update value in global-params if changed

int main(int argc, char** argv) {
    // Sets all pin registers to 0
    TRISA = 0;
    TRISB = 0;
    ANSA = 0;
    ANSB = 0;

    
    rotateCCW(2*3.1415/10);
    
    while (1);
    return 0;
}

