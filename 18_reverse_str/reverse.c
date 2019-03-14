#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  //Dereference str and store it in strcpy

  //Create the count integer n
  int n = 1;
  //Loop through str until reaching \0
  while (*str != '\0'){
  //Increase n by 1
    n++;
  //Increase str pointer by 1
    str++;
  }
  //Create strcpy with the size of n
  char strcpy[n+1];
  //Dereference str and store it in strcpy
  for (int j = 0; j < n; j++) strcpy[j] = str[j];
  //Count from 0 to n and set str[i] equal to strcpy[n-i]
  for (int i = 0; i < n; i++) str[i] = strcpy[n-i];
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
