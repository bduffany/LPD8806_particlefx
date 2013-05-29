#ifndef STRIPSPACE_H
#define STRIPSPACE_H

#include "LPD8806.h"
#include <stdarg.h>

/** Class to represent a chain of disjoint LPD8806 objects */
class StripSpace {
private:
  /** Class representing a single cell of the LPD8806 linked list */
  class LinkCell {
    private:
      LPD8806 * datum;
      LinkCell * next;
    public:
      LinkCell(LPD8806 * datum, LinkCell * next);
      LinkCell(LPD8806 * datum);
      void setDatum(LPD8806 * d);
      LPD8806 * getDatum();
      void setNext(LinkCell * n);
      LinkCell * getNext();
      bool hasNext();
  };
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