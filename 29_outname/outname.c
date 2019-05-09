#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  // ".counts" on the end for 7 more space + 1 Null terminator
  char * outfileName = malloc((strlen(inputName)+ 8) * sizeof(*outfileName));
  strcpy(outfileName, inputName);
  strcat(outfileName, ".counts");
  return outfileName;

}
