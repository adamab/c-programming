#include <stdio.h>
#include <stdlib.h>

int * arrayMax(int * array, int n) {
  // Check for length, and return NULL if 0
  if (n == 0) return NULL;
  // Initialize maxIndex to 0
  int maxIndex = 0;
  // Loop thorugh the length of the array (exclusive)
  for (int i=0; i < n, i++) {
    // If the value of the array at index i is greater than the value at maxIndex
    if (array[i] > array[maxIndex]) {
      // Set the value of maxIndex to equal i
      maxIndex = i;
    }
  }
  // Return the address of array at maxIndex
  return &array[maxIndex];
}

void doTest(int * array, int n) {
  printf("arrayMax(");
  if (array == NULL) {
    printf("NULL");
  }
  else {
    printf("{");
    for (int i =0; i < n; i++) {
      printf("%d", array[i]);
      if (i < n -1) {
	printf(", ");
      }
    }
    printf("}");
  }
  printf(", %d) is \n", n);
  int * p = arrayMax (array, n);
  if (p == NULL) {
    printf("NULL\n");
  }
  else {
    printf("%d\n", *p);
  }
}

int main(void) {
  int array1[] = { 77, 33, 19, 99, 42, 6, 27, 4};
  int array2[] = { -3, -42, -99, -1000, -999, -88, -77};
  int array3[] = { 425, 59, -3, 77, 0, 36};

  doTest (array1, 8);
  doTest (array2, 7);
  doTest (array3, 6);
  doTest (NULL, 0);
  doTest (array1, 0);
  
  return EXIT_SUCCESS;
}
