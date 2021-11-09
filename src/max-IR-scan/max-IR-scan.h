#ifndef MAX_IR_SCAN_H_
#define MAX_IR_SCAN_H_

#define NUMBER_OF_SAMPLES 100
#define ANALOG_THRESHOLD 500

void MaxIRScan__init(int analog_register);
void MaxIRScan__reset();
int MaxIRScan__poll();
int MaxIRScan__checkIfVisible();

#endif //MAX_IR_SCAN_H_