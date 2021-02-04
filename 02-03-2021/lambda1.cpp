/**
 * Lambda functions.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

typedef bool (*compare_t)(int, int);

// For sorting in descending order
bool compare(int a, int b) {
  return a > b;
}

void dump(std::vector<int> v) {  
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) {
      printf(", ");
    }
    printf("%d", v[i]);
  }
  printf("\n");
}

void checkCompare(int a, int b, compare_t cmp) {
  printf("cmp(a, b) = %s\n", cmp(a, b) ? "true" : "false");
}

int main() {
  // Pass compare as a parameter
  checkCompare(100, 200, compare);

  std::vector<int> v1 = {40, -90, 22, 100, 10};
  std::sort(v1.begin(), v1.end(), compare);
  dump(v1);

  // The construct []... is called a "lambda" function
  std::sort(v1.begin(), v1.end(), [](int a, int b) {
    return a < b;
  });
  dump(v1);

  // You can also assign lambdas to variables
  // Note the use of "auto" for type
  auto descAbs = [](int a, int b) {
    return abs(a) > abs(b);
  };
  std::sort(v1.begin(), v1.end(), descAbs);
  dump(v1);
}