/* Mechawreckers    MEEN 330   Oct. 2021 2

main.c -- the code that the robot executes
*/

#include <xc.h>
#include "global-params.h"
#include "analog-read/analog-read.h"
#include "drive-control/drive-control.h"
#include "pic-com/pic-com.h"

#pragma config FNOSC = FRCDIV  // Update value in global-params if changed
#pragma config OSCIOFNC = OFF // enable pin 8,10
#pragma config SOSCSRC = DIG // enable pin 9

#define IR_THRESHOLD 500
#define QRD_THRESHOLD 350

#define IR_SAMPLE_SIZE 100


//enum STATE {ON_LINE, RIGHT_OF_LINE, LEFT_OF_LINE, OFF_LINE_IR, OFF_LINE_NO_IR, ON_CROSS}; // state in our state machine

enum STATE {LINE_FOLLOWING, GETTING_BALLS, CENTERING, SHOOTING, RETURN_TO_GOAL};

int state = LINE_FOLLOWING;

void main_init();

void line_Following_Machine();

void ball_Getting_Machine();

void centering_Machine();

void shooting_Machine();

void delay(int s)
{
    int k = 0;
    while(k < s)
    {
        k++;
    }
}

int main(int argc, char **argv)
{
    main_init();

    DriveControl__init();
    
    PicCom__init(18);
    
    
    Analog__init(); // initialize analog reading
    
    Analog__setup(3); //setup up rear QRD
    Analog__setup(4); // setup front right QRD
    Analog__setup(13); // setup right QRD
    Analog__setup(12); // setup front left QRD
    Analog__setup(11); // setup left QRD
    Analog__setup(10); // setup photodiode
    
    
    
    while(1)
    {
        if(state == LINE_FOLLOWING)
        {
            line_Following_Machine();
        }
        else if(state == GETTING_BALLS)
        {
            ball_Getting_Machine();
        }
        else if(state == CENTERING)
        {
            centering_Machine();
        }
        else if(state == SHOOTING)
        {
            shooting_Machine();
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



void line_Following_Machine()
{
    enum SUB_STATE {ON_LINE, RIGHT_OF_LINE, LEFT_OF_LINE, OFF_LINE_IR, OFF_LINE_NO_IR, ON_CROSS}; // state in our state machine
    
    
    
    // make sensor variables
    int qrd_rear = 0;
    int qrd_right = 0;
    int qrd_left = 0;
    int qrd_fright = 0;
    int qrd_fleft = 0;
    
    int ir_curr = 0;
    int ir_prev = 0;
    
    // begin state machine assuming no ir and off line
    DriveControl__rotateCW(30);
    int sub_state = OFF_LINE_NO_IR;
    
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
        if(sub_state == OFF_LINE_NO_IR)
        {
            if(ir_curr >= IR_THRESHOLD && (ir_prev >= ir_curr || qrd_fright || qrd_fleft)) // if we're above our limit and decreasing
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to move forwards

                sub_state = OFF_LINE_IR; // change state
            }
        }
        else if(sub_state == OFF_LINE_IR)
        {
            if(qrd_fright && !qrd_fleft) // if RIGHT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to move forwards

                sub_state = RIGHT_OF_LINE; // transition of right of line state
            }
            else if(!qrd_fright && qrd_fleft) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                sub_state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(qrd_fright && qrd_fleft) // if Both QRD are on
            {

                sub_state = ON_LINE; // transition to left of line state
            }
            /*
            else if(qrd_left && qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                sub_state = ON_CROSS;
            }
            */
        }
        else if(sub_state == ON_LINE)
        {
            if(qrd_fright && !qrd_fleft) // if RIGHT QRD is on we are left of the line
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                sub_state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && qrd_fleft) // if LEFT QRD is on we are right of the line
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to veer left

                sub_state = RIGHT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement();
                DriveControl__rotateCW(30); // begin to turn right to find the LED

                sub_state = OFF_LINE_NO_IR;
            }
            else if(qrd_left || qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                sub_state = ON_CROSS;
            }
        }
        else if(sub_state == RIGHT_OF_LINE)
        {
            if(qrd_fright && !qrd_fleft) // if left QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                sub_state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && qrd_fleft) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to go forward

                sub_state = ON_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__rotateCCW(30); // begin to rotate left

                sub_state = OFF_LINE_NO_IR; // transition to left of line state
            }
            else if(qrd_right || qrd_left) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                sub_state = ON_CROSS;
            }
        }
        else if(sub_state == LEFT_OF_LINE)
        {
            if(!qrd_fright && qrd_fleft) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to veer right

                sub_state = RIGHT_OF_LINE; // transition to left of line state
            }
            else if(qrd_fright && qrd_fleft) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to go forward

                sub_state = ON_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__rotateCW(30); // begin to rotate left

                sub_state = OFF_LINE_NO_IR; // transition to left of line state
            }
            else if(qrd_left || qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                sub_state = ON_CROSS;
            }
        }
        else if(sub_state == ON_CROSS) // the accept state
        {
            state = GETTING_BALLS;
            break; // accept the state machine and break the loop
        }

    }
}

void ball_Getting_Machine()
{
    // drive back, then forwards to get another ball
    DriveControl__driveBackwards_dist(10, 10);
    while(DriveControl__checkDriveStatus())
    {
    }
    DriveControl__driveForwards_dist(10, 10);
    while(DriveControl__checkDriveStatus())
    {
    }
    DriveControl__driveBackwards_dist(10, 10);
    while(DriveControl__checkDriveStatus())
    {
    }

    state = CENTERING; // switch state to centering

}


void centering_Machine()
{
    enum SUB_STATE {ON_LINE, RIGHT_OF_LINE, LEFT_OF_LINE, OFF_LINE, ON_CROSS}; // state in our state machine
    
    
    
    // make sensor variables
    int qrd_rear = 0;
    int qrd_right = 0;
    int qrd_left = 0;
    int qrd_fright = 0;
    int qrd_fleft = 0;
    

    
    // begin state machine assuming no ir and off line
    DriveControl__driveBackwards(30);
    int sub_state = ON_LINE;
    
    
    // TEMP FIX  -- drive backwards until left and right qrd's detect the cross    
    while(!qrd_left && !qrd_left)
    {
        qrd_right = (Analog__read(13) >= QRD_THRESHOLD);
        qrd_left = (Analog__read(11) >= QRD_THRESHOLD);
        
    }
    
    // TEMP FIX -- once cross is found, begin shooting
    DriveControl__stopMovement();
    state = SHOOTING;
    /* --- -------------- // TODO: Implement backwards line following
    while(1)
    {
        //read QRD INPUTS
        qrd_rear = (Analog__read(3) >= QRD_THRESHOLD);
        qrd_fright = (Analog__read(4) >= QRD_THRESHOLD);
        qrd_right = (Analog__read(13) >= QRD_THRESHOLD);
        qrd_fleft = (Analog__read(12) >= QRD_THRESHOLD);
        qrd_left = (Analog__read(11) >= QRD_THRESHOLD);
                
                
                
     
        if(sub_state == OFF_LINE)
        {
            if(qrd_fright && !qrd_fleft) // if RIGHT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to move forwards

                sub_state = RIGHT_OF_LINE; // transition of right of line state
            }
            else if(!qrd_fright && qrd_fleft) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                sub_state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(qrd_fright && qrd_fleft) // if Both QRD are on
            {

                sub_state = ON_LINE; // transition to left of line state
            }
            else if(qrd_left && qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                sub_state = ON_CROSS;
            }
        }
        else if(sub_state == ON_LINE)
        {
            if(qrd_fright && !qrd_fleft) // if RIGHT QRD is on we are left of the line
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                sub_state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && qrd_fleft) // if LEFT QRD is on we are right of the line
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to veer left

                sub_state = RIGHT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement();
                DriveControl__rotateCW(30); // begin to turn right to find the LED

                sub_state = OFF_LINE;
            }
            else if(qrd_left || qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                sub_state = ON_CROSS;
            }
        }
        else if(sub_state == RIGHT_OF_LINE)
        {
            if(qrd_fright && !qrd_fleft) // if left QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnRight(5,25); // begin to veer left

                sub_state = LEFT_OF_LINE; // transition to left of line state
            }
            else if(!qrd_fright && qrd_fleft) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to go forward

                sub_state = ON_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__rotateCCW(30); // begin to rotate left

                sub_state = OFF_LINE; // transition to left of line state
            }
            else if(qrd_right || qrd_left) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                sub_state = ON_CROSS;
            }
        }
        else if(sub_state == LEFT_OF_LINE)
        {
            if(!qrd_fright && qrd_fleft) // if LEFT QRD is on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__turnLeft(5,25); // begin to veer right

                sub_state = RIGHT_OF_LINE; // transition to left of line state
            }
            else if(qrd_fright && qrd_fleft) // if Both QRD are on
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__driveForwards(5); // begin to go forward

                sub_state = ON_LINE; // transition to left of line state
            }
            else if(!qrd_fright && !qrd_fleft) // if Both QRD are off
            {
                DriveControl__stopMovement(); // stop the robot
                DriveControl__rotateCW(30); // begin to rotate left

                sub_state = OFF_LINE; // transition to left of line state
            }
            else if(qrd_left || qrd_right) // if side sensors are on and at least 1 forward sensor
            {
                DriveControl__stopMovement(); // stop all

                sub_state = ON_CROSS;
            }
        }
        else if(sub_state == ON_CROSS) // the accept state
        {
            state = SHOOTING;
            break; // accept the state machine and break the loop
        }

    }
     * 
     */
}

void shooting_Machine()
{
    PicCom__sendFlag(); // send a flag to the turret
    
    while(!PicCom__getStatus()) // wait for a return signal
    {
    }
    
    state == RETURN_TO_GOAL;
}