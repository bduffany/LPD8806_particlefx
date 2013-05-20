#ifndef PARTICLE_H
#define PARTICLE_H

#include "LPD8806.h"
#include "StripSpace.h"
#include "BTimer.h"

/** Class representing a particle which will be rendered on the LPD8806 */
class Particle {
protected:
  StripSpace * axis; // Axis along which to move
  BTimer * timer;    // Timer for motion calculation
  uint32_t color;    // Color of this particle
  double pos;        // Current position of this particle
  int velocity;      // Current velocity of this particle
public:
  Particle(StripSpace * axis, BTimer * timer, uint32_t color, uint8_t start_pixel, int velocity);
  Particle(LPD8806 * strip, BTimer * timer, uint32_t color, uint8_t start_pixel, int velocity);
  void update();
  void render();
};

#endif