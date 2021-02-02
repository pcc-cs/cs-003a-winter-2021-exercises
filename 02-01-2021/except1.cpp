/**
 * Exceptions.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>

class Read {
 private:
  // Exceptions progate upwards automatically
  int a() {
    return b();
  }

  int b() {
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
  // Throws const char * exception in case of error
  int readInt() {
    return a();
  }
};

int main() {
  try {
    Read r1;
    int i1 = r1.readInt();
    printf("i1 = %d\n", i1);
  
  // "Catch" the exception that may be thrown
  // The parameter type MUST match the type being thrown
  } catch (const char *msg) {
    fprintf(stderr, "error: %s\n", msg);
  }
}