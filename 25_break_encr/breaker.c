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

void updateLetArray(unsigned * letArray, int let){
  for(int i = 0; i < 26, i ++){
    if(*let == arr[i][0]){
      arr[i][1] += 1;
      break;
    }
  }
}

void breaker(FILE * f) {
  unsigned letArray[26];
  int c = 0;
  int largest = 0;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      updateLetArray(letArray, c);
    }
  }
  largest = get_largest_element(letArray, 26);
  printf("%d\n", 4 - largest);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Usage: breaker inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  breaker(f);
  if (fclose(f) != 0) {
    perror("Failed to close the file to decrypt!");
    return EXIT_FAILURE;
  }
}
