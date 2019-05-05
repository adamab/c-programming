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

void addLineArray(char ** lineArray, char * line, int cnt, size_t totSize){
  realloc(lineArray, totSize*sizeof(**lineArray));
  lineArray[cnt] = line;
}

void sortStdin(){
  char * line;
  size_t size = 0;
  size_t totSize = 0;
  char ** lineArray = malloc(sizeof(**lineArray));
  int cnt = 0;
  while(*line != "END"){
    printf("Please enter a line to add to the corpus for sorting, or enter the word END to finish:\n");
    getline(line, &size, stdin);
    totSize += size;
    if(*line != "END") addLineArray(lineArray, line, cnt, totSize);
    cnt += 1;
  }
  sortData(lineArray, cnt);
  for(int i = 0; i < cnt; i++){
    printf("%s", lineArray[i]);
  }
}

void sortFiles(char ** argv, int argc){
  char * line;
  size_t size = 0;
  char ** lineArray = malloc(sizeof(**lineArray));
  for(int i = 1; i < argc; i ++){
    int cnt = 0;
    FILE * f = fopen(argv[i], "r");
    if(f == NULL){
      perror("Could not open file");
      exit(EXIT_FAILURE);
    }
    while(getline(line, &size, f) >= 0){
      totSize += size;
      addLineArray(lineArray, line, cnt, totSize);
      cnt += 1;
    }
    sortData(lineArray, cnt);
    for(int j = 0; j < cnt; j++){
      printf("%s", lineArray[j]);
    }
  }
  printf("All files sorted!");
}

int main(int argc, char ** argv) {
  if(argc == 1) sortStdin();
  if(argc > 1) sortFiles(argv, argc);
  return EXIT_SUCCESS;
}
