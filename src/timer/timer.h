#ifndef TIMER_H_
#define TIMER_H_

// Set a timer for specified amount of time. Current only has timer 1 and 2 implemented (5 exist).
void Timer__set(int timer, float duration);

// Returns a 1 if that timer is running, returns 0 if it is completed.
int Timer__status(int timer);

// Blocks code execution till the timer has finished. BLOCKING CODE.
void Timer__waitForCompletion(int timer);

#endif  // TIMER_H_