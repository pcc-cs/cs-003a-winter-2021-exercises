/**
 * Using std::map.
 *
 * Copyright (c) 2021, Sekhar Ravinutala
 */

#include <map>
#include <cstdio>

int main() {
  std::map<const char *, const char *> m1 = {
    // The \ below is called an "escape" character
    {"Jim", "6' 1\""},
    {"Lisa", "5' 7\""},
    {"Juan", "5' 11\""},
    {"Emily", "5' 2\""},
  };

  for (auto e : m1) {
    printf("%-12s%-12s\n", e.first, e.second);
  }

  m1["Lee"] = "6' 2\"";
  printf("Lee's height is %s\n", m1["Lee"]);
}