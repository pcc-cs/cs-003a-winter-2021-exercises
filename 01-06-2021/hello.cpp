/**
 * Example header comment.
 *
 Copyright (c) 2020, Sekhar Ravinutala.
*/

#include <iostream>

// Note the types for arguments and the return value
int sum(int a, int b) {
  return a + b;
}

int main() {
  std::cout << "Hello!" << std::endl;
  std::cout << "1 + 2 = " << sum(1, 2) << std::endl;
  // Can't do this:
  // std::cout << "1 + 2 = " << sum("1", "2") << std::endl;
}