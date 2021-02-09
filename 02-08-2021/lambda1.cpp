/**
 * Lambda nuances.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>

int main() {
  int x = 100;
  auto plusX = [x](int y) {
    return x + y;
  };
  printf("plusX(10) = %d\n", plusX(10));

  // plusX() continues to use x value of 100
  x = 200;
  printf("plusX(10) = %d\n", plusX(10));  
}