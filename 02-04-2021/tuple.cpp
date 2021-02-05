/**
 * Using std::tuple.
 *
 * Copyright (c) 2021, Sekhar Ravinutala
 */

#include <tuple>
#include <iostream>

struct Combo {
  int id;
  double gpa;
  const char *name;
};

void dump(int id, double gpa, const char *name) {
  std::cout << "ID: \t" << id << std::endl;
  std::cout << "GPA: \t" << gpa << std::endl;
  std::cout << "Name: \t" << name << std::endl;
  std::cout << std::endl;
}

int main() {
  // Using a tuple
  std::tuple<int, double, const char *> t1 = {124321, 3.95, "Jim Carrey"};
  dump(std::get<0>(t1), std::get<1>(t1), std::get<2>(t1));

  typedef std::tuple<int, double, const char *> combo_t;
  combo_t t2 = {124321, 3.95, "Jim Carrey"};
  dump(std::get<0>(t2), std::get<1>(t2), std::get<2>(t2));

  // Using struct
  Combo c1 = {124321, 3.95, "Jim Carrey"};
  dump(c1.id, c1.gpa, c1.name);
}