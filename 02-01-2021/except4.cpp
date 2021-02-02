/**
 * Exceptions, throwing and catching multiple types.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include <climits>
#include <cstdlib>
#include <exception>

enum class Error {
  INVALID_INPUT = 100, OUT_OF_MEMORY, DIVIDE_BY_ZERO
};

class Read {
private:
// Exceptions that can result: Error, const char *
  int a() {
    try {
      return b();

      // Catch one type of exception and throw another type
    }
    catch (int err) {
      // Any kind of error
      throw Error::INVALID_INPUT;
    }
  }

  // Exceptions that can result: int, const char *
  int b() {
    int i;
    // Exception propagates upward automatically, NOT prepared to catch
    c(&i);
    if (i < 0) {
      throw "must be positive";
    }
    return i;
  }

  // Exceptions that can result: int
  void c(int* ip) {
    if (scanf("%d", ip) == 0) {
      // Throw an int type exception
      throw 1;
    }
  }

public:
  // Read int value from stdin
  // Throws Error or const char * type exception
  int readInt() {
    return a();
  }
};

int main() {
  Read r1;
  int i1;

  try {
    i1 = r1.readInt();
  } catch (Error err) {
    // Do whatever is necessary for handling error
    fprintf(stderr, "error code %d reading value\n", int(err));
    exit(1);
  } catch (const char *msg) {
    fprintf(stderr, "error reading value: %s\n", msg);
    exit(1);
  }
  printf("i1 = %d\n", i1);
}