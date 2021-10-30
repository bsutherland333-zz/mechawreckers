#include "localization/localization.h"

#include <stdio.h>
#include <stdlib.h>

#include "drive-control/drive-control.h"
#include "stepper-motor/stepper-motor.h"

void Localization__pointAnalogMax(int pin, unsigned scan_range) {
    while (scan_range >= 360) {
        scan_range -= 360;
    }


    // Tunable values
    const float turn_rate = 90;  // deg/second
    const int samples_per_degree = 4;


    // Set values
    int sample_index = 0;
    const int num_samples = scan_range * samples_per_degree;
    const float single_sample_time = turn_rate * samples_per_degree;  // Equivalent to 1 / logging_hz


    // Initialize dynamic arrays for storing data
    float *logged_angles = malloc(sizeof (float) * num_samples); /* n is the length of the array */
    for (int i = 0; i < num_samples; ++i)
    {
        logged_angles[i] = 0.0;
    }
    float *logged_adc = malloc(sizeof (float) * num_samples); /* n is the length of the array */
    for (int i = 0; i < num_samples; ++i)
    {
        logged_adc[i] = 0.0;
    }


    // Collect data
    DriveControl__rotateCW_dist(turn_rate, (float) scan_range);
    while (StepperMotor__checkMotorStatus())
    {
        if (currAngle() > sample_index / samples_per_degree) {
            logged_adc[sample_index] = // TODO: add ADC channel
            logged_angles[sample_index] = currAngle();
            ++sample_index;
        }
    }

    // Smooth data

    // Find max value

    // Turn towards max value


    // Delete dynamics arrays
    free(logged_angles);
    free(logged_adc);
}