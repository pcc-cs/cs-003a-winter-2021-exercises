/**
 * Unnamed namespace.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>

extern int sum(int);

// Unnamed namespace
namespace {
  int count = 100;
}

int main() {
  printf("count = %d\n", count);
  printf("sum(count) = %d\n", sum(count));
}