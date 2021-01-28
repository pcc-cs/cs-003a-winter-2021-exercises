/**
 * Recursion examples.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include <cstdlib>
#include <cstdint>

// uint64_t rounds after MAX
#define MAX 92

// Using iteration, O(n) time complexity, O(1) space complexity
uint64_t fib3(int n) {
  uint64_t a = 0, b = 1, c;
  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

void error(const char *cmd) {
    // This prints to stderr (error stream) and not stdout (standard output)
    fprintf(stderr, "Usage: %s <+ve integer>\n", cmd);

    // By convention, anything other than 0 indicates failure
    exit(1);
}

// Note how the command line arguments are detected
int main(int argc, char *argv[]) {
  // Read n from command line
  int n;
  if (argc < 2 || sscanf(argv[1], "%d", &n) == 0 || n < 0 || n > MAX) {
    error(argv[0]);
  }

  printf("fib3(%d) = %lu\n", n, fib3(n));
}