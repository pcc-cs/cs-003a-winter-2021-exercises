/**
 * Animal (base class).
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/
#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal {
 private:
  std::string _name = "Animal";
  double _weight;

 public:
  Animal(double);
  // The "virtual" keyword is what enables "polymorphism"
  virtual std::string name() const;
  double weight() const;
};

#endif  // ANIMAL_H_