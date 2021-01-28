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

// Naive recursion, O(2^n) time complexity, O(n) space complexity
// Using uint64_t to maximize range of values
uint64_t fib1(int n) {
  // Base case, don't forget this or you will get an infinite loop
  if (n < 2) {
    return n;
  }

  return fib1(n - 1) + fib1(n - 2);
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

  printf("fib1(%d) = %lu\n", n, fib1(n));
}