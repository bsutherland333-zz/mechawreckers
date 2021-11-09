/*
 * Source code for pic com library
 */

#include "pic-com.h"


int __checkFlag()
{
    int flag = 0;

    switch (rx) // read in the rx pin as flag
    {
            
        case 2:
            
            flag = _RA0;
            break;
            
        case 3:
            
            flag = _RA1;
            break;
            
        case 4:
            
            flag = _RB0;
            break;
            
        case 5:
            
            flag = _RB1;
            break;
            
        case 6:
            
            flag = _RB2;
            break;
            
        case 7:
            
            flag = _RA2;
            break;
            
        case 8:
            
            flag = _RA3;
            break;
            
        case 9:
           
            flag = _RB4;
            break;
            
        case 10:
            
            flag = _RA4;
            break;
            
        case 11:
            
            flag = _RB7;
            break;
            
        case 12:
            
            flag = _RB8;
            break;
            
        case 13:
            
            flag = _RB9;
            break;
            
        case 14:
            
            flag = _RA6;
            break;
            
        case 15:
            
            flag = _RB12;
            break;
            
        case 16:
            
            flag = _RB13;
            break;
            
        case 17:
            
            flag = _RB14;
            break;
            
        
        case 18:
           
            flag = _RB15;
            break;
            
        default:
            break;
    }
    
    return flag; // return flag
}

    
void __changeFlag(int val)
{

    switch (tx) // set the tx pin to val
    {
            
        case 2:
            
            _LATA0 = val;
            break;
            
        case 3:
            
            _LATA1 = val;
            break;
            
        case 4:
            
            _LATB0 = val;
            break;
            
        case 5:
            
            _LATB1 = val;
            break;
            
        case 6:
            
            _LATB2 = val;
            break;
            
        case 7:
            
            _LATA2 = val;
            break;
            
        case 8:
            
            _LATA3 = val;
            break;
            
        case 9:
           
            _LATB4 = val;
            break;
            
        case 10:
            
            _LATA4 = val;
            break;
            
        case 11:
            
            _LATB7 = val;
            break;
            
        case 12:
            
            _LATB8 = val;
            break;
            
        case 13:
            
            _LATB9 = val;
            break;
            
        case 14:
            
            _LATA6 = val;
            break;
            
        case 15:
            
            _LATB12 = val;
            break;
            
        case 16:
            
            _LATB13 = val;
            break;
            
        case 17:
            
            _LATB14 = val;
            break;
            
        
        case 18:
           
            _LATB15 = val;
            break;
            
        default:
            break;
    }

}


void PicCom__init(int tx_pin, int rx_pin)
{
    tx = tx_pin;
    rx = rx_pin;
    
    
    switch (rx) // configure the rx pin
    {
        case 2:
            
            _TRISA0 = 1;
            _ANSA0 = 0;
            break;
            
        case 3:
            
            _TRISA1 = 1;
            _ANSA1 = 0;
            break;
            
        case 4:
            
            _TRISB0 = 1;
            _ANSB0 = 0;
            break;
            
        case 5:
            
            _TRISB1 = 1;
            _ANSB1 = 0;
            break;
            
        case 6:
            
            _TRISB2 = 1;
            _ANSB2 = 0;
            break;
            
        case 7:
            
            _TRISA2 = 1;
            _ANSA2 = 0;
            break;
            
        case 8:
            
            _TRISA3 = 1;
            _ANSA3 = 0;
            break;
            
        case 9:
           
            _TRISB4 = 1;
            _ANSB4 = 0;
            break;
            
        case 10:
            
            _TRISA4 = 1;

            break;
            
        case 11:
            
            _TRISB7 = 1;

            break;
            
        case 12:
            
            _TRISB8 = 1;

            break;
            
        case 13:
            
            _TRISB9 = 1;
            
            break;
            
        case 14:
            
            _TRISA6 = 1;

            break;
            
        case 15:
            
            _TRISB12 = 1;
            _ANSB12 = 0;
            break;
            
        case 16:
            
            _TRISB13 = 1;
            _ANSB13 = 0;
            break;
            
        case 17:
            
            _TRISB14 = 1;
            _ANSB14 = 0;
            break;
            
        
        case 18:
           
            _TRISB15 = 1;
            _ANSB15 = 0;
            break;
            
        default:
            break;
    }
    
    switch (tx) // configure the tx pi
    {
        case 2:
            
            _TRISA0 = 0;
            _ANSA0 = 0;
            break;
            
        case 3:
            
            _TRISA1 = 0;
            _ANSA1 = 0;
            break;
            
        case 4:
            
            _TRISB0 = 0;
            _ANSB0 = 0;
            break;
            
        case 5:
            
            _TRISB1 = 0;
            _ANSB1 = 0;
            break;
            
        case 6:
            
            _TRISB2 = 0;
            _ANSB2 = 0;
            break;
            
        case 7:
            
            _TRISA2 = 0;
            _ANSA2 = 0;
            break;
            
        case 8:
            
            _TRISA3 = 0;
            _ANSA3 = 0;
            break;
            
        case 9:
           
            _TRISB4 = 0;
            _ANSB4 = 0;
            break;
            
        case 10:
            
            _TRISA4 = 0;

            break;
            
        case 11:
            
            _TRISB7 = 0;

            break;
            
        case 12:
            
            _TRISB8 = 0;

            break;
            
        case 13:
            
            _TRISB9 = 0;
            
            break;
            
        case 14:
            
            _TRISA6 = 0;

            break;
            
        case 15:
            
            _TRISB12 = 0;
            _ANSB12 = 0;
            break;
            
        case 16:
            
            _TRISB13 = 0;
            _ANSB13 = 0;
            break;
            
        case 17:
            
            _TRISB14 = 0;
            _ANSB14 = 0;
            break;
            
        
        case 18:
           
            _TRISB15 = 0;
            _ANSB15 = 0;
            break;
            
        default:
            break;
    }
}


// checks the status of the rx flag. If the flag is up,
// then lower the tx flag. 
int PicCom__getStatus()
{
    int status = __checkFlag();
    
    if(status) // if the rx flag is on
    {
        __changeFlag(0); // turn off the tx flag
    }
    
    return status;
}


// send a tx flag
void PicCom__sendFlag()
{
    __changeFlag(1);
}