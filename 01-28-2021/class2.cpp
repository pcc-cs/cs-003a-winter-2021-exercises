/**
 * Check inheritance, method overloading (polymorphism).
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include "cat.h"
#include "dog.h"
#include "util.h"

extern 

int main() {
  Animal a1(100);
  printf("a1.name() = %s, a1.weight() = %.1lf\n",
    a1.name().c_str(), a1.weight());

  Cat c1(10);
  printf("c1.name() = %s, c1.weight() = %.1lf, c1.sound() = %s\n",
    c1.name().c_str(), c1.weight(), c1.sound().c_str());

  Dog d1(20);
  printf("d1.name() = %s, d1.weight() = %.1lf, d1.sound() = %s\n",
    d1.name().c_str(), d1.weight(), d1.sound().c_str());

  Animal &ac1 = c1;
  dump(&ac1);

  Animal &ad1 = d1;
  dump(&ad1);

  Animal *ac1p = &c1;
  dump(ac1p);

  Animal *ad1p = &d1;
  dump(ad1p);
}