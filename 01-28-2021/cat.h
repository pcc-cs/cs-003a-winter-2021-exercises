/**
 * Cat (derived class).
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#ifndef CAT_H_
#define CAT_H_

#include <string>
#include "animal.h"

class Cat : public Animal {
 private:
  std::string _name = "Cat";
  std::string _sound = "meow";

 public:
  Cat(double);
  std::string name() const;
  std::string sound() const;
};

#endif  // CAT_H_
