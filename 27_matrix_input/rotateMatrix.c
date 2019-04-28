#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void rotate(char matrix[10][10]) {
  //Check for NULL case and return
  if (matrix == NULL) return;
  //Initialize temporary matrix
  char tmpMatrix[10][10];
  //Loop i from 0 to 9
  for (int i = 0; i < 10; i++){
    //Loop j from 0 to 9
    for (int j = 0; j < 10; j++){
      //Set tmpMatrix[i][j] to equal matrix[i][j]
      tmpMatrix[i][j] = matrix[i][j];
    }
  }
  //Loop i from 0 to 9
  for (int i = 0; i < 10; i++){
    //Loop j from 0 to 9
    for (int j = 0; j < 10; j++){
      //Set matrix[j][9-i] to equal tmpMatrix[i][j]
      matrix[j][9-i] = tmpMatrix[i][j];
    }
  }
}

void printMatrix(char matrix[10][10]) {
  if (matrix == NULL) {
    fprintf(stderr, "No matrix passed to printMatrix");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      printf(&matrix[i][j]);
    }
    printf("\n");
  }
}

void rotateMatrix(FILE * f){
  int i = 0, j = 0, c = 0;
  char matrix[10][10];
  while ((c = fgetc(f)) != EOF) {
    if(c != '\n' && j < 10){
      matrix[i][j] = c;
      j += 1;
    } else if(c == '\n' && j < 10){
      fprintf(stderr, "Newline in file before expected end of line at line %d position %d; all lines should be 10 characters long\n", i, j);
      exit(EXIT_FAILURE);
    } else if(c != '\n' && j == 10){
      fprintf(stderr, "Newline in file after expected end of line at line %d position %d; all lines should be 10 characters long\n", i, j);
      exit(EXIT_FAILURE);
    } else {
      i += 1;
      j = 0;
    }
  }
  if(i > 10) {
    fprintf(stderr, "Too many lines in file; there are %d lines and there should be only 10\n", i);
    exit(EXIT_FAILURE);
  }
  if(i < 10) {
    fprintf(stderr, "Too many lines in file; there are %d lines and there should be only 10\n", i);
    exit(EXIT_FAILURE);
  }
  rotate(matrix);
  printMatrix(matrix);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: rotateMatrix inputFileName\n");
    exit(EXIT_FAILURE);
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    exit(EXIT_FAILURE);
  }
  rotateMatrix(f);
  if (fclose(f) != 0) {
    perror("Failed to close the file to decrypt!");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
