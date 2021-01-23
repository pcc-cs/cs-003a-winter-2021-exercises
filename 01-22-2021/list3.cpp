/**
 * Writing tests for delete().
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include "list.h"

// Check a test
#define CHECK(s, b) printf("%s: %s\n", s, b ? "pass" : "fail")

int main() {
  List l1;

  // Note that these check some so-called "corner" or "edge" cases
  CHECK("remove on empty", l1.remove(100));
  l1.add(100);
  CHECK("remove non existent value", l1.remove(101));
  CHECK("remove single element", l1.remove(100));
  CHECK("removed element should be absent", !l1.search(100));
  l1.add(100); l1.add(200); l1.add(300);
  CHECK("remove internal value", l1.remove(200));
  CHECK("removed element should be absent", !l1.search(200));
  CHECK("remove tail element", l1.remove(300));
  l1.add(400);

  // Check that the list is 100 -> 400
  l1.dump();
}