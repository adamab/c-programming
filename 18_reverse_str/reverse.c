#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  //Check if the string is null and break
  if (str == NULL) return;
  //Initialize copy pointer
  char * strptr = str;
  //Create the count integer n
  int n = 0;
  //Loop through str until reaching \0
  while (*strptr != '\0' && n < 5000){
  //Increase n by 1
    n++;
  //Increase str pointer by 1
    strptr++;
  }
  //Create strcpy with the size of n
  char stringcpy[n];
  //Dereference str and store it in strcpy
  strncpy(stringcpy, str, n);
  stringcpy[n]='\0';
  //Count from 0 to n and set str[i] equal to strcpy[n-i]
  for (int i = 0; i < n; i++) {
    str[i] = stringcpy[n-i-1];
  }
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
