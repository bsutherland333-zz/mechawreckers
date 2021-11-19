#include "max-IR-scan.h"

#include "analog-read/analog-read.h"

int _MaxIRScan__curr_value = 0;
int _MaxIRScan__previous_value = 0;
int _MaxIRScan__register = -1;

void MaxIRScan__init(int analog_register)
{
    Analog__init();
    Analog__setup(analog_register);
    _MaxIRScan__register = analog_register;
    MaxIRScan__reset();
}

void MaxIRScan__reset()
{
    _MaxIRScan__curr_value = 0;
    _MaxIRScan__previous_value = 0;
}

int MaxIRScan__poll()
{
    _MaxIRScan__previous_value = _MaxIRScan__curr_value;

    double average = 0;
    for(int i = 0; i < NUMBER_OF_SAMPLES; i++)
    {
        average += (double)Analog__read(_MaxIRScan__register)/NUMBER_OF_SAMPLES;
    }

    _MaxIRScan__curr_value = (int)average;

    if(_MaxIRScan__curr_value >= ANALOG_THRESHOLD && _MaxIRScan__previous_value >= _MaxIRScan__curr_value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int MaxIRScan__checkIfVisible()
{
    MaxIRScan__poll();
    if (_MaxIRScan__curr_value > ANALOG_THRESHOLD)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}