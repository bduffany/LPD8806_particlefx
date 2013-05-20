#ifndef LINKCELL_H
#define LINKCELL_H

#include "LPD8806.h"

/** Class representing a single cell of the LPD8806 linked list */
class LinkCell {
  private:
    LPD8806 * datum;
    LinkCell * next;
  public:
    LinkCell(LPD8806 * datum, LinkCell * next);
    void setDatum(LPD8806 * d);
    LPD8806 * getDatum();
    void setNext(LinkCell * n);
    LinkCell * getNext();
    bool hasNext();
};

#endif