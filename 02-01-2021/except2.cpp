/**
 * Exceptions, shows you can catch exceptions anywhere in the call chain.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include <climits>
#include <cstdlib>

class Read {
 private:
  int a() {
    return b();
  }

  int b() {
    try {
      return c();
    } catch (const char* msg) {
      return INT_MIN;
    }
  }

  int c() {
    int i;
    if (scanf("%d", &i) == 0) {
      throw "invalid input";
    }
    return i;
  }

 public:
  // Read int value from stdin
  // Return INT_MIN in case of error
  int readInt() {
    return a();
  }
};

int main() {
    Read r1;
    int i1 = r1.readInt();
    if (i1 == INT_MIN) {
      // Do whatever is necessary for handling error
      fprintf(stderr, "error reading value\n");
      exit(1);
    }
    printf("i1 = %d\n", i1);
}