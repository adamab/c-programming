#include <stdlib.h>

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
