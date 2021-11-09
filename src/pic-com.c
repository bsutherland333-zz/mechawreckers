/*
 * Source code for pic com library
 */

#include "pic-com.h"


int __checkFlag()
{
    
}


void PicCom__init(int tx_pin, int rx_pin)
{
    tx = tx_pin;
    rx = rx_pin;
}


// checks the status of the rx flag. If the flag is up,
// then lower the tx flag. 
int PicCom__getStatus();


// send a tx flag
void PicCom__sendFlag();