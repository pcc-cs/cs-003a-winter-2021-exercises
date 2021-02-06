/**
 * Type declarations.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstring>
#include <cstdio>

typedef int (*oper_t)(int, int);

int sum(int a, int b) {
  return a + b;
}

int diff(int a, int b) {
  return a - b;
}

int apply(oper_t oper, int a, int b) {
  return oper(a, b);
}

int main() {
  // Can't modify c1
  const char c1 = 'a';
  // c1 = 'b';

  // Can change pointer, but not the contents
  const char *s1 = "foo";
  s1 = "bar"; // OK
  // *s1 = 'b';
  // s1[1] = 'a';

  // Not allowed because "foo" is const char * that is read-only
  // char *s2 = "foo";

  // These are OK, can change all
  char *s2 = new char[4];
  strcpy(s2, "foo");
  *s2 = 'b';
  s2[1] = 'a';

  // Can't change pointer, but OK to change contents
  char * const s3 = (char * const) s2;
  // s3 = "bar";
  *s3 = 'b';

  // Can't change pointer or its contents
  const char * const s4 = s2;
  // s4 = "bar";
  // *s4 = 'b';

  int (*o1)(int, int) = sum;  // Direct way
  auto o2 = sum;  // Using "auto" keyword
  oper_t o3 = sum;  // Using typedef (custom type)

  oper_t add = sum;
  oper_t subtract = diff;
  printf("apply(add, 10, 20) = %d\n", apply(add, 10, 20));
  printf("apply(subtract, 10, 20) = %d\n", apply(subtract, 10, 20));
}