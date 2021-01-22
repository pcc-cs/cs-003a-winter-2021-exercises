/**
 * Operate on linked list.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include "list.h"

int main() {
  List l1;
  l1.add(100);
  l1.add(200);
  l1.dump();

  for (int i = 3; i < 10; i++) {
    l1.add(i * 100);
  }
  l1.dump();
}