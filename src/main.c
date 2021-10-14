#include <xc.h>

#include "drive-control/drive-control.h"

#pragma config FNOSC = FRC  // Update value in global-params if changed

int main(int argc, char** argv) {
    // Sets all pin registers to 0
    TRISA = 0;
    TRISB = 0;
    ANSA = 0;
    ANSB = 0;

    StepperMotor__init();
    StepperMotor__rotate(2, 1, 1, 2);
    StepperMotor__rotate(1, 0, 1, 2);
    StepperMotor__completeRotations();
    
    StepperMotor__rotate(2, 1, 0.5, 1.33);
    StepperMotor__completeRotations();
    
    StepperMotor__rotate(2, 1, 1, 2);
    StepperMotor__rotate(1, 0, 1, 2);
    StepperMotor__completeRotations();
    
    
    
    while (1);
    return 0;
}

