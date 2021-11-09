/*  Mechawreckers  MEEN 330   Nov. 2021
 * 
 * pic-com.h -- a library that enables the communication of two PIC24's. This is
 * done using a binary signal flag going from on pic to another rather than a 
 * serial communication stream
 */


#ifndef PIC_COM
#define PIC_COM

#include<xc.h>

int tx = 0;
int rx = 0;


void PicCom__init(int tx_pin, int rx_pin);


// checks the status of the rx flag. If the flag is up,
// then lower the tx flag. 
int PicCom__getStatus();


// send a tx flag
void PicCom__sendFlag();

// lowers tx flag
void __lowerFlag();

// raises tx flag
void __raiseFlag();

// checks for flag
int __checkFlag();


#endif