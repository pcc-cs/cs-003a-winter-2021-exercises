/**
 * Classes.
 *
 Copyright (c) 2020, Sekhar Ravinutala.
*/

#include <cstdio>

typedef const char *String;

int main() {
  // "String" is easier to write and read than "const char *"
  String s1 = "Hello!";
  printf("s1: %s\n", s1);
  const char *s2 = "Hi!";
  printf("s2: %s\n", s2);
}