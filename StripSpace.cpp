#include "StripSpace.h"

/** Constructor that takes the start strip as a parameter */
StripSpace::StripSpace(LPD8806 * start) {
  LinkCell s = LinkCell(start, NULL);
  this->start = &s;
  last = this->start;
  length = 1;
}

/** Constructor that takes the number of strips, followed by num LPD8806 pointers */
StripSpace::StripSpace(int num, ...) {
  va_list arguments;
  va_start(arguments, num);
  LPD8806 * ptr = va_arg(arguments, LPD8806 * );
  LinkCell empty = LinkCell(NULL, NULL);
  LinkCell cells[num] = {empty};
  cells[0].setDatum(ptr);
  for (int i = 1; i < num; i++ ) {
      ptr = va_arg(arguments, LPD8806 * );
      cells[i].setDatum(ptr);
      cells[i - 1].setNext(ptr);
  }
  va_end(arguments);
  length = num;
} 

/** Add another strip to the StripSpace */
void StripSpace::add(LPD8806 * str) {
  LinkCell l = LinkCell(str, NULL);
  last->setNext(&l);
  last = last->getNext();
  ++length;
}

/** Return the last LPD8806 pointer in this StripSpace */
LPD8806 * StripSpace::getLast() {
  return last->getDatum();
}

/** Get the strip at the specified pixel p */
LPD8806 * StripSpace::getStrip(uint16_t p) {
  LinkCell * s = start;
  uint16_t upper = s->getDatum()->numPixels();
  while (p >= upper) {
    s = s->getNext();
    upper+= s->getDatum()->numPixels();
  }
  return s->getDatum();
}

/** Returns the corresponding pixel index of p into getStrip(p) */
uint16_t StripSpace::getPixelIndex(uint16_t p) {
  LinkCell * s = start;
  uint16_t upper = s->getDatum()->numPixels(); 
  uint16_t lower = 0;
  while (p >= upper) {
    if (! s->hasNext()) {
      return -1;
    }
    lower = upper;
    s = s->getNext();
    upper+= s->getDatum()->numPixels();
  }
  return p - lower;
}

/** Return the total number of pixels in this link of strips */
uint16_t StripSpace::numPixels() {
  if (!start) {
    return 0;
  }
  LinkCell * s = start;
  uint16_t n = s->getDatum()->numPixels();
  while (s->hasNext()) {
    s = s->getNext();
    n += s->getDatum()->numPixels();
  }
  return n;
}