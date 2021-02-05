/**
 * Using std::set.
 *
 * Copyright (c) 2021, Sekhar Ravinutala
 */

#include <set>
#include <string>
#include <iostream>
#include <algorithm>

// Different ways to check membership
#define HAS1(s, v) (std::find(s.begin(), s.end(), v) != s.end())
#define HAS2(s, v) (s.count(v) > 0)

#define IN(s, v) (std::string(v) + ": " + (HAS2(s, v) ? "in set" : "not in set"))

std::ostream &operator<<(std::ostream &os, std::set<std::string> &s) {
  int i = 0;
  for (std::string v : s) {
    if (i++ > 0) {
      os << ", ";
    }
    os << v;
  }
  return os;
}

int main() {
  std::set<std::string> s1;
  std::string names[] = {"Jim", "Lisa", "Juan", "Emily"};
  for (auto &n : names) {
    s1.insert(n);
  }

  // Note that the keys are sorted in ascending lexical order
  // BUT it's best NOT to depend on that (not all languages maintain order)
  for (auto &n : s1) {
    std::cout << n << std::endl;
  }
  // Using operator overloading
  std::cout << s1 << std::endl;

  // Using macros
  std::cout << IN(s1, "Jim") << std::endl;
  std::cout << IN(s1, "John") << std::endl;
}