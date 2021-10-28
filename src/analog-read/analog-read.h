/*
   Mechawreckers    MEEN330    Oct 2021

   analog-read.h -- a library that supports the analog read functions of the PIC24F16KA301  
*/


#ifndef ANALOG_READ
#define ANALOG_READ

#include <xc.h>

// sets up analog pins

void analog_init() // configures the analogo read register settings

void setup_analog(int register) // sets up an analog register


// gives the current analog reading of a AN register
int read_analog(int register);

// gives the current analog reading of a particular pin
int read_analog_pin(int pin);



#endif