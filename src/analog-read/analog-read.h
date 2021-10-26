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

void setup_analog_0(); // setus up analog on pin 2

void setup_analog_1(); // sets up analog on pin 3

void setup_analog_2(); // sets up analog on pin 4

void setup_analog_3(); // sets up analog on pin 5

void setup_analog_4(); // sets up analog on pin 6
 
void setup_analog_9(); // sets up analog on pin 18

void setup_analog_10(); // sets up analog on pin 17

void setup_analog_11(); // sets up analog on pin 16

void setup_analog_12(); // sets up analog on pin 15

void setup_analog_13(); // sets up analog on pin 7

void setup_analog_14(); // sets up analog on pin 8

void setup_analog_15(); // sets up analog on pin 9


// gives the current analog reading of a AN register
int read_analog(int register);

// gives the current analog reading of a particular pin
int read_analog_pin(int pin);



#endif