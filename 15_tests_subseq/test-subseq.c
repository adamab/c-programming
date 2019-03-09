#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(){
  int test1[7] = {1,2,3,4,5,4,8};
  int test2[9] = {1,2,6,5,5,4,8,7,8};
  int test3[4] = {5,3,4,4};
  int test4[5] = {3,4,4,8,7};
  int test5[9] = {4,8,6,5,4,3,2,1,0};
  int test6[2] = {1,0};
  int test7[5] = {1,1,13,4,511};

  if (maxSeq(test1, 7) != 5) printf("Failed for 1,2,3,4,5,4,8\n"); exit(EXIT_FAILURE);
  if (maxSeq(test2, 9) != 3) printf("Failed for 1,2,6,5,5,4,8,7,8\n"); exit(EXIT_FAILURE);
  if (maxSeq(test3, 4) != 2) printf("Failed for 5,3,4,4\n"); exit(EXIT_FAILURE);
  if (maxSeq(test4, 5) != 2) printf("Failed for 3,4,4,8,7\n"); exit(EXIT_FAILURE);
  if (maxSeq(test5, 9) != 2) printf("Failed for 4,8,6,5,4,3,2,1,0\n"); exit(EXIT_FAILURE);
  if (maxSeq(test6, 2) != 1) printf("Failed for 1,0\n"); exit(EXIT_FAILURE);
  if (maxSeq(test7, 5) != 2) printf("Failed for 1,1,13,4,511\n"); exit(EXIT_FAILURE);

  return EXIT_SUCCESS;
}