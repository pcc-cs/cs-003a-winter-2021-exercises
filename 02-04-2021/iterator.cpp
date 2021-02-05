/**
 * Using iterators.
 *
 * Copyright (c) 2021, Sekhar Ravinutala
 */

#include <vector>
#include <iostream>

int main() {
  std::vector<int> v1 = {100, -3, 45, 6, 24};

  // This is an "iterator" that "points" to a member of the container
  auto v1i = v1.begin();

  // You can dereference it like a pointer, but it is NOT a pointer
  // It does this through operator overloading
  std::cout << *v1i << std::endl;

  // Increment like a pointer
  v1i++;
  std::cout << *v1i << std::endl;

  // Perform arithmetic
  v1i += 2;
  std::cout << *v1i << std::endl;
}