#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count_f (FILE *f, int * count) {
  // [0, 25]
  int c;
  while ((c = fgetc(f))!= EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      count[c] += 1;
    }
  }
}



int get_max_idx(int * array, int size) {
  int max_idx = 0;
  for (int i = 1; i < size; i++ ) {
    if (array[i] > array[max_idx]) {
      max_idx = i;
    }
  }
  return max_idx;
}
    

int main(int argc, char ** argv) {
  if (argc != 2) {
    perror("Invalid command line argument\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Couldn't open file\n");
    return EXIT_FAILURE;
  }
  int count[26] = {0};
  count_f(f, count);
  int  max_idx = get_max_idx(count, 26);
  int key = (max_idx - ('e'-'a') + 26) %26;
  printf("%d\n",key);
  return EXIT_SUCCESS;
}
  
