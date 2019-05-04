#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //outfileNAme is inputName + ".counts\0", so add 8 to its length.
  char * outFileName = malloc((strlen(inputName) + 8) * sizeof(*outFileName));
  strncpy(outFileName, inputName, strlen(inputName)+1);
  strncat(outFileName, ".counts", 7);
  return outFileName;
}
