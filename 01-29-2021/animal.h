/**
 * Animal (base class).
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/
#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

// Because there is a "pure virtual" function, this class is "abstract"
// and CANNOT be instantiated
// "Abstract" classes define an "interface"
class Animal {
 protected:
  double _weight;

 public:
  Animal(double);
  // The "virtual" keyword is what enables "polymorphism"
  // There is no implementation in Animal, this is "pure virtual"
  virtual std::string name() const = 0;
  double weight() const;
};

#endif  // ANIMAL_H_