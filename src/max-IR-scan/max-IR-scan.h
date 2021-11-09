#ifndef MAX_IR_SCAN_H_
#define MAX_IR_SCAN_H_

// TODO: This class has not been tested since it has been re-written, please test ASAP

// Values for scanning
#define NUMBER_OF_SAMPLES 100
#define ANALOG_THRESHOLD 500

// Initialization function must be run before class is used
void MaxIRScan__init(int analog_register);

// Reset values to 0. Run this before using this max finder class again.
void MaxIRScan__reset();

// Checks to see if current analog value is less than the last time this function is run. Will return 0 if current
//  value is not less than, and will return 1 if the current value is greater than the last value. Also, will return 0
//  if current value is below the set threshold.
int MaxIRScan__poll();

// Checks to see if the current analog value is above the threshold. Return 0 if it is below and 1 if it is above.
int MaxIRScan__checkIfVisible();

#endif //MAX_IR_SCAN_H_