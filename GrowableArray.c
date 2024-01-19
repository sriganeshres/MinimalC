#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t inital) {
  a->array = malloc(inital * sizeof(int));
  a->used = 0;
  a->size = inital;
}

void insertArray(Array *a, int val) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = val;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->size = a->used = 0;
}
/*
int main() {
  Array a;
  initArray(&a, 5);                           USAGE
  for (int i = 0; i < 100; i++) {
    insertArray(&a, i);
  }
  printf("%d\n", a.array[11]);
  printf("%zu", a.used);
  freeArray(&a);
}
*/
