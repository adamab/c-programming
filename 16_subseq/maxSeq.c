#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  //Check if size n is less than 0, return -1 if so
  //if(n < 0) return -1;
  //Check if size n is 0, return 0 if so
  if(n <= 0) return 0;
  //Create variable count initialized to 1
  int count = 1;
  //Create variable maxCount initialized to 1
  int maxCount = 1;
  //Loop from 1 to n(exclusive)
  for(int i = 1; i < n; i++){
  //Check if value at index of current step is greater than the value at index of the previous step
  //Add 1 to count if the above holds
    if(array[i] > array[i-1]) count+=1;
    //Otherwise, count = 1
    else count = 1;
  //Check if value of count is greater than maxCount
  //Set the value of maxCount to the value of count if the above holds
    if(count > maxCount) maxCount = count;
  }
  //Return the value of maxCount
  return maxCount;
}
