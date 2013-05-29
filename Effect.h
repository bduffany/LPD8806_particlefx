#ifndef EFFECT_H
#define EFFECT_H

#include "StripSpace.h"

/** Abstract class representing an effect which will be rendered on the LPD8806 */
class Effect {
protected:
  static double position_scale; // Master position scaling factor
  static double time_scale;     // Master time scaling factor
  StripSpace * axis;            // Space on which to display the effect
public:
  static void setPositionScale(double s);
  static void setTimeScale(double s);
  virtual void update();
  virtual void render();
};

#endif