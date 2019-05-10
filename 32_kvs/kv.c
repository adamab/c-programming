#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"


kvarray_t * readKVs(const char * fname) {
  /* This function gives the key or value based on the
   * argument passed to forKey (1 = key, 0 = value) in
   * the argument passed to line.
   */
  char * line = NULL;
  size_t sz = 0;
  kvarray_t * kvArray = malloc(sizeof(*kvArray));
  if(kvArray == NULL){
    perror("Not enough memory to create Key Value array");
    exit(EXIT_FAILURE);
  }
  FILE * f = fopen(fname, "r");
  int cnt = 0;
  if(f == NULL){
    perror("Could not open file");
    exit(EXIT_FAILURE);
  }
  while(getline(&line, &sz, f) >= 0){
    kvArray->kv = realloc(kvArray->kv, (cnt+1)*sizeof(*kvArray->kv));
    if(kvArray == NULL){
      perror("Not enough memory to create additional Key Value pair array");
      exit(EXIT_FAILURE);
    }
    kvArray->kv[cnt]->key = strtok(line, "="); 
    kvArray->kv[cnt]->value = strtok(NULL, "");
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
