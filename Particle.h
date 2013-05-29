#ifndef PARTICLE_H
#define PARTICLE_H

#include "Effect.h"
#include "LPD8806.h"
#include "StripSpace.h"
#include "BTimer.h"

/** Class representing a particle which will be rendered on the LPD8806 */
class Particle : public Effect {
protected:
  BTimer timer;      // Timer for motion calculation
  uint32_t color;    // Color of this particle
  double pos;        // Current position of this particle
  int velocity;      // Current velocity of this particle
public:
  Particle(StripSpace * axis, uint32_t color, uint8_t start_pixel, int velocity);
  Particle(LPD8806 * strip, uint32_t color, uint8_t start_pixel, int velocity);
};

#endif