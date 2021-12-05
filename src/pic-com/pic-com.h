/*  Mechawreckers  MEEN 330   Nov. 2021
 *
 * pic-com.h -- a library that enables the communication of two PIC24's. This is
 * done using a binary signal flag going from on pic to another rather than a
 * serial communication stream
 */


#ifndef PIC_COM_H_
#define PIC_COM_H_

#include <xc.h>

// Initializes comm pin to be a digital input
void PicCom__init(int pin);

// Checks the status of the commPin
int PicCom__getStatus();

// Send a flag over the commPin
void PicCom__sendFlag();

#endif