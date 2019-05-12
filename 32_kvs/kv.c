#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char * splitKVs(char * line, char * splitChar, uint forKey){
  /* This function gives the key or value based on the
   * argument passed to forKey (1 = key, 0 = value) in
   * the argument passed to line.
   */
  char * ans = malloc(strlen(line)*sizeof(*line));
  ans = strtok(line, splitChar);//Returns the first part of the split line
  if(forKey == 0) ans = strtok(NULL, "");//Returns all of the remaining line after the split, "" will not find another split point in the string
  ans = realloc(ans, strlen(ans)*sizeof(*ans));//Set the allocation to be the size of the string to not over allocate memory
  return ans;
}

kvarray_t * readKVs(const char * fname) {
  /* This function gives the key or value based on the
   * argument passed to forKey (1 = key, 0 = value) in
   * the argument passed to line.
   */
  char * line = NULL;
  size_t sz = 0;
  int cnt = 0;
  kvarray_t * kvArray = malloc(sizeof(*kvArray));
  if(kvArray == NULL){
    perror("Not enough memory to create Key Value array");
    exit(EXIT_FAILURE);
  }
  FILE * f = fopen(fname, "r");
  if(f == NULL){
    perror("Could not open file");
    exit(EXIT_FAILURE);
  }
  kvArray->kv = NULL;
  while(getline(&line, &sz, f) >= 0){
    kvArray->kv = realloc(kvArray->kv, (cnt+1)*sizeof(*kvArray->kv));
    if(kvArray->kv == NULL){
      perror("Not enough memory to create additional Key Value pair array");
      exit(EXIT_FAILURE);
    }
    kvArray->kv[cnt]->key = splitKVs(line, "=", 1); 
    kvArray->kv[cnt]->value = splitKVs(line, "=", 0);
    line = NULL;
    cnt++;
  }
  free(line);
  return kvArray;
}

void freeKVs(kvarray_t * pairs) {
  /* This function frees all of the allocated memory
   * associated with the key value array.
   */
  for(int i = 0; i < pairs->length; i++){
    free(pairs->kv[i]->key);
    free(pairs->kv[i]->value);
    free(pairs->kv[i]);
  }
  free(pairs->kv);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  /* This function prints all key value pairs in the
   * key value pair array in a human readable format.
   */
  for(int i = 0; i < pairs->length; i++){
    printf("key = '%s' value = '%s'", pairs->kv[i]->key, pairs->kv[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  /* This function finds the key in the pairs array
   * and returns the associated value when it finds it.
   * Otherwise, it returns a NULL when the key isn't found.
   */
  for(int i = 0; i < pairs->length; i++){
    if(pairs->kv[i]->key == key) return pairs->kv[i]->value;
  }
  return NULL;
}
