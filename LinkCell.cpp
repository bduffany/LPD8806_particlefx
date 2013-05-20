#include "LinkCell.h"

/** Constructor for a link cell */
LinkCell::LinkCell(LPD8806 * datum, LinkCell * next) {
  this->datum = datum;
  this->next = next;
}

/** Returns the LPD8806 pointer contained by this cell */
LPD8806 * LinkCell::getDatum() {
  return datum;
}

/** Sets the next LinkCell to which this cell should point */
void LinkCell::setNext(LinkCell * n) {
  next = n;
}

/** Get the next link cell */
LinkCell * LinkCell::getNext() {
  return next;
}

/** Return whether the next element is not NULL */
bool LinkCell::hasNext() {
  if (next) return true;
  return false;
}