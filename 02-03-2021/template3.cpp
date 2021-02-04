/**
 * Simplete template function.
 *
 * Copyright (c) 2021, Sekhar Ravinutala
 */

#include <cstdio>
#include <string>

#include "util.h"

int main() {
  // Swap for int
  int i1 = 100, i2 = 200;
  printf("i1 = %d, i2 = %d\n", i1, i2);
  swap(&i1, &i2);
  printf("i1 = %d, i2 = %d\n", i1, i2);

  // Swap for std::string
  std::string s1 = "foo", s2 = "bar";
  printf("s1 = %s, s2 = %s\n", s1.c_str(), s2.c_str());
  swap(&s1, &s2);
  printf("s1 = %s, s2 = %s\n", s1.c_str(), s2.c_str());
}