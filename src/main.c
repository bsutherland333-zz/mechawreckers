#include <xc.h>

#include "drive-control.h"

// Oscillator
#pragma config FNOSC = FRC

int main(int argc, char** argv) {
    // Sets all pin registers to 0
    TRISA = 0;
    TRISB = 0;
    ANSA = 0;
    ANSB = 0;

    StepperMotor__init();
    StepperMotor__set_direction(1, 0);
    StepperMotor__set_direction(1, 0);
    StepperMotor__rotate(1, 3);

    return 0;
}

