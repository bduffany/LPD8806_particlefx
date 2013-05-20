#ifndef BTIMER_H
#define BTIMER_H

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

/** Class for a simple timer using the Arduino */
class BTimer {
private:
  long 
    start_ms, 
    stopped_time;
  bool stopped;
public:
	BTimer();
  void 
    start(),
    stop(),
    reset();
  long getTime();
  bool timeHasPassed(long t); 
};

#endif // BTIMER_H