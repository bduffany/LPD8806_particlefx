#include "BTimer.h"

/** Constructor that initializes things to 0 */
BTimer::BTimer() : 
  stopped(false),
  start_ms(0),
  stopped_time(0) {}

/** Start the timer */
void BTimer::start() {
  start_ms = millis();
  stopped = false;
}

/** Restarts the timer */
void BTimer::reset() {
  start(); // lol  
}

/** Stops the timer. */
void BTimer::stop() {
  stopped_time = millis();
  stopped = true;
}

/** Returns the time elapsed since we started, or if we're stopped,
 *  returns the time elapsed from the time we started to the time we stopped. */
long BTimer::getTime() {
  if (stopped) 
    return stopped_time - start_ms;

  return millis() - start_ms;
}

/** Tests whether t milliseconds have elapsed since we last started (or reset) */
bool BTimer::timeHasPassed(long t) {
  return getTime() >= t;
}