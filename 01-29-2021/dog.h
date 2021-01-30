/**
 * Dog (derived class).
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#ifndef DOG_H
#define DOG_H

#include <string>
#include "animal.h"

class Dog : public Animal {
 private:
  std::string _name = "Dog";
  std::string _sound = "bark";

 public:
  Dog(double);
  std::string name() const;
  std::string sound() const;
};

#endif  // DOG_H
