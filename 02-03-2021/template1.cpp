/**
 * Simple template function.
 *
 * Copyright (c) 2021, Sekhar Ravinutala
 */

#include <cstdio>
#include <string>

// Swap for int
void swapInt(int *ap, int *bp) {
  int c = *ap;
  *ap = *bp;
  *bp = c;
}

// Similar logic, but needs another implementation
void swapString(std::string *ap, std::string *bp) {
  std::string c = *ap;
  *ap = *bp;
  *bp = c;
}

int main() {
  // Swap for int
  int i1 = 100, i2 = 200;
  printf("i1 = %d, i2 = %d\n", i1, i2);
  swapInt(&i1, &i2);
  printf("i1 = %d, i2 = %d\n", i1, i2);

  // Swap for std::string
  std::string s1 = "foo", s2 = "bar";
  printf("s1 = %s, s2 = %s\n", s1.c_str(), s2.c_str());
  swapString(&s1, &s2);
  printf("s1 = %s, s2 = %s\n", s1.c_str(), s2.c_str());
}