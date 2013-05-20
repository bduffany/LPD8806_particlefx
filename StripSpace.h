#ifndef STRIPSPACE_H
#define STRIPSPACE_H

#include "LPD8806.h"
#include "LinkCell.h"
#include <stdarg.h>

/** Class to represent a chain of disjoint LPD8806 objects */
class StripSpace {
private:
  LinkCell * start;
  LinkCell * last;
  uint8_t length;
public:
  StripSpace(LPD8806 * start);
  StripSpace(int num, ...);
  LPD8806 * getStrip(uint16_t p);
  uint16_t getPixelIndex(uint16_t p);
  uint16_t numPixels();
  void add(LPD8806 * str);
  LPD8806 * getLast();
};

#endif