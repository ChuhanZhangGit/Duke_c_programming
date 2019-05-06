#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_SIZE 12

void rotate(char matrix[10][10]){
  char r_matrix[10][10];
  for (int i = 0; i < 10; i++){
    for (int j = 0; j <10; j++){
      r_matrix[j][9-i] = matrix[i][j];
    }
  }
  for (int i = 0; i < 10; i++){
    for (int j = 0; j <10; j++){
      matrix[i][j] = r_matrix[i][j];
    }
  }

}

void copystr(char * str, char * array) {
  for (int i = 0; i < 10; i++) {
    array[i] = str[i];
  }
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    perror("error was: ");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("error was: ");
  }
  char line[LINE_SIZE];
  char matrix[10][10];
  int row_num = 0;
  while (fgets(line, LINE_SIZE, f) != NULL) {
    if (strchr(line, '\n') == NULL) {
      printf("Line is too long!\n");
      return EXIT_FAILURE;
    }
    if ((strchr(line, '\n')- line) != 10 ) {
      printf("Line is too short!\n");
      return EXIT_FAILURE;
    }
    if (row_num == 10) {
      printf("Too many lines.");
      return EXIT_FAILURE;
    }
    copystr(line, matrix[row_num]);
    row_num ++; 
  }
  if (row_num < 10) {
    printf("Too little lines.");
    return EXIT_FAILURE;
  }
  rotate(matrix);
  for (int i =0 ; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
}
