/**
 * Using namespaces.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <iostream>

// Don't do this since this brings all names into scope
using namespace std;

// Kind of OK because you're only pulling out the names you care about
using std::cout;
using std::endl;

int main() {
  // Recommended: use full namespace to reference
  std::cout << "Recommended" << std::endl;

  // Can cause name clashes since there is no namespace specified
  cout << "Not recommended" << endl;
}