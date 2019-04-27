#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned get_largest_element(unsigned * arr, size_t n) {
  int largestElem = 0;
  int elem = 0;
  int largestValue = 0;
  for(int i = 0; i < n; i++){
    elem = arr[i];
    if(elem > largestElem){
      largestElem = elem;
      largestValue = i;
    }
  }
  return largestValue;
}

void breaker(FILE * f) {
  unsigned letArray[26];
  int c = 0;
  int largest = 0;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      letArray[c] += 1;
    }
  }
  largest = get_largest_element(letArray, 26);
  printf("%d\n", 4 - largest);
}

void main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: breaker inputFileName\n");
    exit(EXIT_FAILURE);
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    exit(EXIT_FAILURE);
  }
  breaker(f);
  if (fclose(f) != 0) {
    perror("Failed to close the file to decrypt!");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
