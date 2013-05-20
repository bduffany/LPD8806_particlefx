#include "Particle.h"

/** Constructor that takes in the appropriate parameters */
Particle::Particle(StripSpace * axis, BTimer * timer, uint32_t color, uint8_t start_pixel, int velocity) {
  this->axis = axis;
  this->timer = timer;
  this->color = color;
  pos = start_pixel;
  this->velocity = velocity;
  timer->start();
}

/** Constructor that takes in a single LPD8806 pointer */
Particle::Particle(LPD8806 * strip, BTimer * timer, uint32_t color, uint8_t start_pixel, int velocity) {
  StripSpace l = StripSpace(strip);
  Particle(&l, timer, color, start_pixel, velocity);  
}

/** Determine the new location of the particle */
void Particle::update() {
  long deltaT = timer->getTime();
  timer->reset();
  double deltaX = velocity * deltaT;
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