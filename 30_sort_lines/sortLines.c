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

void sortStdin(){
  char * line=NULL;
  size_t size = 0;
  char ** lineArray = NULL;
  int cnt = 0;
  printf("Please enter all of the lines to add to the corpus for sorting, then use control-D to end the list:\n");
  while(getline(&line, &size, stdin) >= 0){
    lineArray = realloc(lineArray, (cnt+1)*sizeof(*lineArray));
    lineArray[cnt] = line;
    line = NULL;
    cnt += 1;
  }
  free(line);
  sortData(lineArray, cnt);
  for(int i = 0; i < cnt; i++){
    printf("%s", lineArray[i]);
    free(lineArray[i]);
  }
  free(lineArray);
}

void sortFiles(char ** argv, int argc){
  char * line=NULL;
  size_t size = 0;
  char ** lineArray = NULL;
  for(int i = 1; i < argc; i ++){
    int cnt = 0;
    FILE * f = fopen(argv[i], "r");
    if(f == NULL){
      perror("Could not open file");
      exit(EXIT_FAILURE);
    }
    while(getline(&line, &size, f) >= 0){
      lineArray = realloc(lineArray,(cnt+1)*sizeof(*lineArray));
      lineArray[cnt] = line;
      line = NULL;
      cnt += 1;
    }
    free(line);
    sortData(lineArray, cnt);
    for(int j = 0; j < cnt; j++){
      printf("%s", lineArray[j]);
      free(lineArray[j]);
    }
  }
  free(lineArray);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    exit(EXIT_FAILURE);
   }
  printf("All files sorted!\n");
}

int main(int argc, char ** argv) {
  if(argc == 1) sortStdin();
  if(argc > 1) sortFiles(argv, argc);
  return EXIT_SUCCESS;
}
