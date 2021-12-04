/* Mechawreckers    MEEN 330   Oct. 2021 2

main.c -- the code that the robot executes
*/

#include <xc.h>
#include "global-params.h"
#include "analog-read/analog-read.h"
#include "drive-control/drive-control.h"

#pragma config FNOSC = FRCDIV  // Update value in global-params if changed
#pragma config OSCIOFNC = OFF // enable pin 8,10
#pragma config SOSCSRC = DIG // enable pin 9

#define IR_THRESHOLD 500
#define QRD_THRESHOLD 350

#define IR_SAMPLE_SIZE 100


enum STATE {ON_LINE, RIGHT_OF_LINE, LEFT_OF_LINE, OFF_LINE_IR, OFF_LINE_NO_IR, ON_CROSS}; // state in our state machine


void main_init();

int main(int argc, char **argv)
{
    main_init();

    DriveControl__init();
    
    
    Analog__init(); // initialize analog reading
    
    Analog__setup(3); //setup up rear QRD
    Analog__setup(4); // setup front right QRD
    Analog__setup(13); // setup right QRD
    Analog__setup(12); // setup front left QRD
    Analog__setup(11); // setup left QRD
    Analog__setup(10); // setup photodiode
   
    
    // make sensor variables
    int qrd_rear = 0;
    int qrd_right = 0;
    int qrd_left = 0;
    int qrd_fright = 0;
    int qrd_fleft = 0;
    
    int ir_curr = 0;
    int ir_prev = 0;
    
    // begin state machine assuming no ir and off line
    DriveControl__rotateCW(15);
    int state = OFF_LINE_NO_IR;
    
    while(1)
    {
        //read QRD INPUTS
        qrd_rear = (Analog__read(3) >= QRD_THRESHOLD);
        qrd_fright = (Analog__read(4) >= QRD_THRESHOLD);
        qrd_right = (Analog__read(13) >= QRD_THRESHOLD);
        qrd_fleft = (Analog__read(12) >= QRD_THRESHOLD);
        qrd_left = (Analog__read(11) >= QRD_THRESHOLD);
        // set previous IR value as current value
        ir_prev = ir_curr;
        
        // set current IR value as average of n inputs
        
        float ave = 0;
        for(int i = 0; i <= IR_SAMPLE_SIZE; i++)
        {
            ave += Analog__read(10);
        }
        
        ir_curr = (int)(ave / (float)IR_SAMPLE_SIZE);
                
                
                
        // Observe current state
        if(state == OFF_LINE_NO_IR)
        {
            if(ir_curr >= IR_THRESHOLD && ir_prev >= ir_curr) // if we're above our limit and decreasing
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to move forwards

                state = OFF_LINE_IR; // change state
            }
        }
        else if(state == OFF_LINE_IR)
        {
            if(qrd_fright && !qrd_fleft) // if RIGHT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to move forwards

                state = RIGHT_OF_LINE; // transition of right of line state
            }
            else if(!qrd_fright && qrd_fleft) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(qrd_fright && qrd_fleft) // if Both QRD are on
            {

                state = ON_LINE; // transition to left of line state
            }
            else if(qrd_left && qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                state = ON_CROSS;
            }
        }
        else if(state == ON_LINE)
        {
            if(qrd_fright && !qrd_fleft) // if RIGHT QRD is on we are left of the line
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && qrd_fleft) // if LEFT QRD is on we are right of the line
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to veer left

                state = RIGHT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement();
                DriveControl__rotateCW(15); // begin to turn right to find the LED

                state == OFF_LINE_NO_IR;
            }
            else if(qrd_left || qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                state = ON_CROSS;
            }
        }
        else if(state == RIGHT_OF_LINE)
        {
            if(qrd_fright && !qrd_fleft) // if left QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && qrd_fleft) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to go forward

                state = ON_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__rotateCCW(15); // begin to rotate left

                state = OFF_LINE_NO_IR; // transition to left of line state
            }
            else if(qrd_right || qrd_left) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                state = ON_CROSS;
            }
        }
        else if(state == LEFT_OF_LINE)
        {
            if(!qrd_fright && qrd_fleft) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to veer right

                state = RIGHT_OF_LINE; // transition to left of line state
            }
            else if(qrd_fright && qrd_fleft) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to go forward

                state = ON_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__rotateCW(15); // begin to rotate left

                state = OFF_LINE_NO_IR; // transition to left of line state
            }
            else if(qrd_left || qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                state = ON_CROSS;
            }
        }
        else if(state == ON_CROSS) // the accept state
        {
            break; // accept the state machine and break the loop
        }

    }

    while(1) // STOP ALL
    {
        // do nothing
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

    // Sets post scalar to 8
    // Make sure to update value in global params if changed!!
    _RCDIV = 0b011;
}