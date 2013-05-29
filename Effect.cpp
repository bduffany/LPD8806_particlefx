#include "Effect.h"

/** Set the master position scaling factor to s */
static void Effect::setPositionScale(double s) {
  position_scale = s;
}

/** Set the master time scaling factor to s */
static void Effect::setTimeScale(double s) {
  time_scale = s;
}