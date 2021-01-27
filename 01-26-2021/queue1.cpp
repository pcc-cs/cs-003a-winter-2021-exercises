/**
 * Check out queue.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include "queue.h"

#define CHECK(s, b) printf("%s: %s\n", b ? "pass" : "fail", s)

int main() {
  Queue q1;
  CHECK("should be empty on creation", q1.empty());
  CHECK("next should be NONE on empty", q1.next() == NONE);

  q1.shift("Tom");
  CHECK("should not be empty after shift", !q1.empty());
  CHECK("size should be 1 after one shift", q1.size() == 1);
  CHECK("last pushed item should be next after one shift", q1.next() == "Tom");

  q1.shift("Lisa");
  CHECK("should not be empty after shift", !q1.empty());
  CHECK("size should be 2 after second push", q1.size() == 2);
  CHECK("next should not change after shift", q1.next() == "Tom");

  CHECK("should unshift the first value", q1.unshift() == "Tom");
  CHECK("should not be empty after unshift", !q1.empty());
  CHECK("size should be 1 after one unshift", q1.size() == 1);
  CHECK("second shifted item should be next", q1.next() == "Lisa");
}