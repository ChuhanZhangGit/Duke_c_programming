#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);


int helper (unsigned x, unsigned y, unsigned expected) {
  if (power(x, y) == expected) {
    return EXIT_SUCCESS;
  }
  else {
    printf("Test Failed on x = %u, y = %u\n", x, y);
    exit(EXIT_FAILURE);
  }
}

int main (void) {
  helper(2, 3, 8);
  helper(-1, 1, 4294967295);
  helper('A', 1, 65);
  helper(1, -1, 1);
  helper(0, 0, 1);
  helper(0, 2, 0);
  printf("Correct Implimentation!");
  return EXIT_SUCCESS;
}
