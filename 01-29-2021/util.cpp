/**
 * Utility function(s).
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include "animal.h"

// This does NOT need to be aware of the derived classes
void dump(const Animal *ap) {
  printf("name: %s, weight: %.1lf\n", ap->name().c_str(), ap->weight());
}