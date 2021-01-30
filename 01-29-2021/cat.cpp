/**
 * Cat (derived class).
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include "cat.h"

Cat::Cat(double w) : Animal(w) {
}

std::string Cat::sound() const {
  return _sound;
}

std::string Cat::name() const {
  return _name;
}

void Cat::shed() {
  _weight -= 0.1;
}