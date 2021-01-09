/**
 * Dynamic arrays.
 *
 Copyright (c) 2020, Sekhar Ravinutala.
*/

#include <cstdio>
#include <random>

#define SIZE 10

// Note that changes persist after the function returns
void populate(int a[], int size) {
  for (int i = 0; i < size; i++) {
    a[i] = rand() % 1000;
  }
}

int main() {
  // Allocate memory with "new" - created on the "heap" (NOT stack)
  // a1 itself is however an "automatic" variable and is created on the stack
  int *a1 = new int[SIZE];
  populate(a1, SIZE);
  for (int i = 0; i < SIZE; i++) {
    if (i > 0) {
      printf(", ");
    }
    printf("%d", a1[i]); // a1[i] is equivalent to *(a1 + i)
  }
  printf("\n");

  // Note the difference in memory addresses
  printf("&a1 = %p, a1 = %p\n", &a1, a1);

  // Deallocate memory, ALWAYS do this to avoid memory leaks!!!
  // Don't forget the [] for arrays!
  delete [] a1;
}