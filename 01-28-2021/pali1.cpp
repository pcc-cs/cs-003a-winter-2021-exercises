/**
 * Check for palindromes using recursion.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include <cstring>

#define SIZE 0x100

/**
 * isPali checks if given string is a palindrome.
 * - s: string to check, never null
 * - n: length of the string, always >= 0
 */
bool isPali(const char *s, int n) {
  // Base case, don't forget this!
  if (n < 2) {
    return true;
  }

  if (s[0] != s[n - 1]) {
    return false;
  }
  return isPali(s + 1, n - 2);
}

int main() {
  char s[SIZE];
  
  // Loop ends when there is no more input (e.g., with Ctrl+D on BASH shell)
  while (scanf("%s", s) > 0) {
    printf("%s\n", isPali(s, strlen(s)) ? "Palindrome" : "Not palindrome");
  }
}