/* Mechawreckers    MEEN 330   Oct. 2021 2

turret-main.c -- Main function for robot turret
*/

#include <xc.h>

#include "timer/timer.h"
#include "turret-control/turret-control.h"
#include "max-IR-scan/max-IR-scan.h"
#include "pic-com/pic-com.h"
#include "analog-read/analog-read.h"

#pragma config FNOSC = FRCDIV  // Update value in global-params if changed
#pragma config OSCIOFNC = OFF // enable pin 8,10
#pragma config SOSCSRC = DIG // enable pin 9

enum STATE {WAITING_FOR_COMMAND, SENDING_COMMAND, SEARCH_AND_FIRE, CHECK_BALL_STATUS}; // state in our state machine
enum BALL_COLOR {BLACK, WHITE};

void main_init();

int ballCheck()
{
    if (Analog__read(0) > 2000)  return BLACK;
    else                         return WHITE;
}

int main(int argc, char **argv)
{
    main_init();
    PicCom__init(17);
    TurretControl__init();
    Analog__init();
    MaxIRScan__init(9);
    Analog__setup(0);

    int currState = WAITING_FOR_COMMAND;
    int ballColor = WHITE;
    int fireCount = 0;
    int pos = 1;
    float time = .5;

    // Make sure other pic is fully initialized and ready
    Timer__set(1, 1);
    Timer__waitForCompletion(1);

    while (1) 
    {
        switch (currState)
        {
            case WAITING_FOR_COMMAND:
                if (PicCom__getStatus())
                {
                    currState = CHECK_BALL_STATUS;
                }
                break;
            
            
            case SENDING_COMMAND:
                PicCom__sendFlag();
                currState = WAITING_FOR_COMMAND;
                break;
            
            
            case SEARCH_AND_FIRE:
                // Turn till valid goal is found

                while (1) 
                {
                    if (pos > 3 )  pos = 1;
                    if (pos == 3)  time = 0.9;
                    
                    TurretControl__setTurretPosition(pos);
                    Timer__set(1, time);
                    Timer__waitForCompletion(1);
                    if ((ballColor == BLACK) && MaxIRScan__checkIfVisible()) break;
                    else if ((ballColor == WHITE) && !MaxIRScan__checkIfVisible()) break;
                    
                    pos++;
                    time = .5;
                }

                // Wait for motor to finish speeding up
                Timer__waitForCompletion(2);

                // Verify that the current goal is still valid
                if ((ballColor == BLACK) && !MaxIRScan__checkIfVisible()) {
                    break;
                } else if ((ballColor == WHITE) && MaxIRScan__checkIfVisible()) {
                    break;
                }

                // Fire ball
                TurretControl__activateTrigger();
                fireCount++;

                // Wait for fired ball to leave shooter and new ball to fall into QRD range
                Timer__set(1, 0.5);
                Timer__waitForCompletion(1);
                
                if(fireCount == 1 && ballCheck() == ballColor)
                {
                    TurretControl__activateTrigger();
                    fireCount++;
                }

                currState = CHECK_BALL_STATUS;
                break;
            
            
            case CHECK_BALL_STATUS:
                // Prepare turret to enter waiting state
                if (fireCount == 2) {
                    currState = SENDING_COMMAND;
                    fireCount = 0;
                    TurretControl__disableMotor();
                    TurretControl__setTurretPosition(1);
                    pos = 1;
                    break;
                }

                // Check and update ball color
                ballColor = ballCheck();

                // Set motor speed
                if (ballColor == WHITE) TurretControl__setMotorSpeed_white();
                else TurretControl__setMotorSpeed_black();

                // Allow time for motor to spin up to speed.
                Timer__set(2, 2.5);                          //ADJUST FOR TIME SAVING

                currState = SEARCH_AND_FIRE;
                break;
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

    // Sets post scalar to 8
    // Make sure to update value in global params if changed!!
    _RCDIV = 0b011;
}