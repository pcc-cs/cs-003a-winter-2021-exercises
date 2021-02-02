/**
 * Exceptions, catching and then rethrowing a different type.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include <climits>
#include <cstdlib>

enum class Error {
  INVALID_INPUT = 100, OUT_OF_MEMORY, DIVIDE_BY_ZERO
};

class Read {
 private:
  int a() {
    try {
      return b();
    
    // Catch one type of exception and throw another type
    } catch (const char* msg) {
      throw Error::INVALID_INPUT;
    }
  }

  int b() {
    // Exception propagates upward automatically
    return c();
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
  // Throws Error type exception
  int readInt() {
    return a();
  }
};

int main() {
    Read r1;
    int i1;
    
    try {
      i1 = r1.readInt();
    } catch (int err) {
      // Do whatever is necessary for handling error
      fprintf(stderr, "error code %d reading value\n", int(err));
      exit(1);
    }
    printf("i1 = %d\n", i1);
}