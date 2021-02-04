/**
 * Util logic to show you CANNOT separate template logic.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include "util.h"

// "Template" for swap
template <class T>
void swap(T *ap, T *bp) {
  T c = *ap;
  *ap = *bp;
  *bp = c;
}