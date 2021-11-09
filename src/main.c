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

#define THRESHOLD 500


enum STATE {ON_LINE, RIGHT_OF_LINE, LEFT_OF_LINE, OFF_LINE_IR, OFF_LINE_NO_IR, ON_CROSS}; // state in our state machine


void main_init();

int main(int argc, char **argv)
{
    main_init();

    DriveControl__init();
    
    
    analog_init();
    
    
    // begin state machine assuming no ir and off line
    int state = OFF_LINE_NO_IR;
    DriveControl__rotateCW(2*PI/15);
    
    while(1)
    {
        // Read in QRD right
        // Read in QRD left
        
        // set previous IR value as current value
        // set current IR value as average of n inputs
        
        // Observe current state
        if(state == OFF_LINE_NO_IR)
        {
            if(current_ir_val >= THRESHOLD && prev_ir_val >= current_ir_val) // if we're above our limit and decreasing
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to move forwards

                state = OFF_LINE_IR; // change state
            }
        }
        else if(state == OFF_LINE_IR)
        {
            if(0) // if RIGHT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,50); // begin to move forwards
                
                state = RIGHT_OF_LINE; // transition of right of line state
            }
            else if(0) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,50); // begin to veer left
                
                state = LEFT_OF_LINE; // transition to left of line state 
            }
            else if(0) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to move forwards
                
                state = ON_LINE; // transition to left of line state 
            }
        }
        else if(state == ON_LINE)
        {
            if(0) // if RIGHT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,50); // begin to veer left
                
                state = LEFT_OF_LINE; // transition to left of line state 
            }
            else if(0) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,50); // begin to veer left
                
                state = RIGHT_OF_LINE; // transition to left of line state 
            }
            else if(0) // if Both QRD are off
            {
                DriveControl__stopMovement();
                DriveControl__rotateCW(2*PI/15); // begin to turn right to find the LED
                
                state == OFF_LINE_NO_IR;
            }
        }
        else if(state == RIGHT_OF_LINE)
        {
            if(0) // if RIGHT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,50); // begin to veer left
                
                state = LEFT_OF_LINE; // transition to left of line state 
            }
            else if(0) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to go forward
                
                state = ON_LINE; // transition to left of line state 
            }
            else if(0) // if Both QRD are off
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__rotateCCW(5); // begin to rotate left
                
                state = OFF_LINE_NO_IR; // transition to left of line state 
            }            
        }
        else if(state == LEFT_OF_LINE)
        {
             if(0) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,50); // begin to veer right
                
                state = RIGHT_OF_LINE; // transition to left of line state 
            }
            else if(0) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to go forward
                
                state = ON_LINE; // transition to left of line state 
            }
            else if(0) // if Both QRD are off
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__rotateCCW(5); // begin to rotate left
                
                state = OFF_LINE_NO_IR; // transition to left of line state 
            }             
        }
        else if(state == ON_CROSS) // the accept state
        {
            DriveControl__stopMovement(); // stop the motors
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
}