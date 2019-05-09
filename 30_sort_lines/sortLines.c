#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void loadarray(FILE * f) {
  
  char ** array = NULL;
  char * line = NULL;
  size_t size;
  size_t str_num = 0;
  while (getline(&line, &size, f) >= 0) {
    array = realloc(array, (str_num+1) * sizeof(*array));
    array[str_num] = line;
    line = NULL;
    str_num++;
  }
  free(line);
  sortData(array, str_num);
  for (int i =0; i < str_num; i++) {
    free(array[i]);
  }
  free(array);
}
 
int main(int argc, char ** argv) {
  if (argc == 1) {
    loadarray(stdin);
  }
  else if (argc > 1) {
    for ( int i = 1; i < argc; i++ ) {
      FILE * f = fopen(argv[i], "r");
      if (f == NULL) {
	perror("Can't read the file!");
	return EXIT_FAILURE;
      }
      loadarray(f);
      if (fclose(f) != 0) {
	perror("Cant' close the file!");
	return EXIT_FAILURE;
      }
    }
  }
 
  
  return EXIT_SUCCESS;
}
