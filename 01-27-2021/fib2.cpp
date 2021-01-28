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

// Using memoization, with O(n) time complexity, O(n) space complexity
// Keyword "auto" automatically deduces the type, still statically typed
namespace {
  auto vals = new uint64_t[MAX]();  // The () at the end initializes values to 0
}
uint64_t fib2(int n) {
  // Always check for base case
  if (n < 2) {
    return n;
  }

  // Use cache
  if (vals[n] == 0) {
    // This expensive step runs only in case of cache miss
    vals[n] = fib2(n - 1) + fib2(n - 2);
  }
  return vals[n];
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

  printf("fib2(%d) = %lu\n", n, fib2(n));
  delete [] vals;  // Remember the [] to delete ALL the values
}