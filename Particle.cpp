#include "Particle.h"

/** Set the master position scaling factor to s */
static void Particle::setPositionScale(double s) {
  position_scale = s;
}

/** Set the master time scaling factor to s */
static void Particle::setTimeScale(double s) {
  time_scale = s;
}

/** Constructor that takes in the appropriate parameters */
Particle::Particle(StripSpace * axis, uint32_t color, uint8_t start_pixel, int velocity) {
  position_scale = 1.0; // Use pixels by default
  time_scale = 1.0 / 1000.0; // Scale to seconds by default
  timer = BTimer();
  this->axis = axis;
  this->color = color;
  pos = start_pixel;
  this->velocity = velocity;
  timer->start();
}

/** Constructor that takes in a single LPD8806 pointer */
Particle::Particle(LPD8806 * strip, uint32_t color, uint8_t start_pixel, int velocity) {
  StripSpace * s = new StripSpace(strip);
  Particle(s, color, start_pixel, velocity);  
}

/** Determine the new location of the particle */
void Particle::update() {
  long deltaT = timer->getTime() * time_scale;         // Time since the last update, in milliseconds, then scaled by TIME_SCALE
  timer->reset();
  double deltaX = velocity * deltaT * position_scale;  // Change in position since the last update, in pixels, then scaled by POSITION_SCALE
  pos += deltaX;
  uint16_t m = axis->numPixels(); 
  pos = (((int)pos % m) + m)  % m;
}

/** Render this particle with the appropriate color on the correct strip */
void Particle::render() {
  uint16_t px = (uint16_t)pos;
  LPD8806 * str = axis->getStrip(px);
  uint16_t ind = axis->getPixelIndex(px);
  str->setPixelColor(ind, color);
}