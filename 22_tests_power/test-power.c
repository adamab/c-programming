#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

void run_check(unsigned x, unsigned y, unsigned expected_ans){

  if (power(x, y) == expected_ans) return;
  printf('Failed for x=%d, y=%d, expected=%d\n',x,y,expected_ans);
  exit(EXIT_FAILURE);
}

int main(){
  run_check(2,2,4);
  run_check(2,3,8);
  run_check(0,0,1);
  run_check(0,3,0);
  run_check(3,0,1);
  run_check(4294967295,1,4294967295);
  return EXIT_SUCCESS;

}
