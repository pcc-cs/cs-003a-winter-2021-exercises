/**
 * Test templated version of stack.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <string>
#include <iostream>
#include "stack.h"

#define CHECK(s, b) printf("%s: %s\n", b ? "pass" : "fail", s)

int main() {
  // Stack used with std::string type
  Stack<std::string> s1;

  // Note that these const char * params create corresponding
  // std::string class instances in s2.push()
  s1.push("Jim");
  s1.push("Lisa");
  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;

  // Stack used with double type
  Stack<double> s2;

  s2.push(100);
  CHECK("should not be empty after push", !s2.empty());
  CHECK("size should be 1 after one push", s2.size() == 1);
  CHECK("last pushed item should be on top", s2.top() == 100);

  s2.push(200);
  CHECK("should not be empty after push", !s2.empty());
  CHECK("size should be 2 after second push", s2.size() == 2);
  CHECK("last pushed item should be on top", s2.top() == 200);

  CHECK("should pop the last pushed value", s2.pop() == 200);
  CHECK("should not be empty after pop", !s2.empty());
  CHECK("size should be 1 after one pop", s2.size() == 1);
  CHECK("last pushed item should be on top", s2.top() == 100);
}