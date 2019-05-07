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

int create_matrix(char matrix[10][10], FILE * f) {
  int row_num = 0;
  char line[LINE_SIZE];
  while (fgets(line, LINE_SIZE, f) != NULL) {
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "Line %d is too long!\n", row_num+1);
      return -1;
    }
    if ((strchr(line, '\n')- line) != 10 ) {
      fprintf(stderr,"Line %d is too short!\n", row_num+1);
      return -1;
    }
    if (row_num == 10) {
      fprintf(stderr, "Too many lines.");
      return -1;
    }
    copystr(line, matrix[row_num]);
    row_num ++; 
  }
  if (row_num < 10) {
    fprintf(stderr,"Too little lines.");
    return -1;
  }
  return 1;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: filename %s", argv[0]);
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open the input file");
  }
  char matrix[10][10];
  if (create_matrix(matrix, f) != 1) {
    return EXIT_FAILURE;
  }
  
  if (fclose(f) != 0) {
    perror("Failed to close the input file");
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
