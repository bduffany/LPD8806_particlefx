#include "StripSpace.h"

/** Constructor that takes the start strip as a parameter */
StripSpace::StripSpace(LPD8806 * start) {
  this->start = new LinkCell(start);
  last = this->start;
  length = 1;
}

/** Constructor that takes the number of strips, followed by num LPD8806 pointers */
StripSpace::StripSpace(int num, ...) {
  va_list arguments;
  va_start(arguments, num);
  LPD8806 * lpd = va_arg(arguments, LPD8806 * );
  LinkCell * prev = new LinkCell(lpd);
  LinkCell * cur;
  start = cell;
  for (int i = 1; i < num; i++ ) {
      lpd = va_arg(arguments, LPD8806 * );
      cur = new LinkCell(lpd, NULL);
      prev->setNext(cur);
      prev = cur;
  }
  length = num;
  va_end(arguments);
} 

/** Add another strip to the StripSpace */
void StripSpace::add(LPD8806 * str) {
  last->setNext(new LinkCell(str));
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

/** Constructor for a link cell that takes the datum and next cell as the params */
StripSpace::LinkCell::LinkCell(LPD8806 * datum, LinkCell * next) {
  this->datum = datum;
  this->next = next;
}

/** Constructor for a link cell that only takes the datum */
StripSpace::LinkCell::LinkCell(LPD8806 * datum) {
  LinkCell(datum, NULL);
}

/** Sets the LPD8806 pointer contained by this cell to d */
void StripSpace::LinkCell::setDatum(LPD8806 * d) {
  datum = d;
}

/** Returns the LPD8806 pointer contained by this cell */
LPD8806 * StripSpace::LinkCell::getDatum() {
  return datum;
}

/** Sets the next LinkCell to which this cell should point */
void StripSpace::LinkCell::setNext(LinkCell * n) {
  next = n;
}

/** Get the next link cell */
LinkCell * StripSpace::LinkCell::getNext() {
  return next;
}

/** Return whether the next element is not NULL */
bool StripSpace::LinkCell::hasNext() {
  if (next) return true;
  return false;
}