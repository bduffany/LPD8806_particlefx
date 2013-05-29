#ifndef PARTICLE_H
#define PARTICLE_H

#include "LPD8806.h"
#include "StripSpace.h"
#include "BTimer.h"

/** Class representing a particle which will be rendered on the LPD8806 */
class Particle {
protected:
	static double position_scale; // Master position scaling factor
	static double time_scale; // Master time scaling factor
  StripSpace * axis; // Axis along which to move
  BTimer timer;      // Timer for motion calculation
  uint32_t color;    // Color of this particle
  double pos;        // Current position of this particle
  int velocity;      // Current velocity of this particle
public:
	static void setPositionScale(double s);
	static void setTimeScale(double s);
  Particle(StripSpace * axis, uint32_t color, uint8_t start_pixel, int velocity);
  Particle(LPD8806 * strip, uint32_t color, uint8_t start_pixel, int velocity);
  void update();
  void render();
};

#endif