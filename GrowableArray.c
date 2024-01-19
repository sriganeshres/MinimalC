#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum typeReq {
  INT,
  CHAR,
  BOOLEAN,
};

typedef struct {
  void *array;
  size_t used;
  size_t size;
  enum typeReq typ;
} Array;

void initArray(Array *a, size_t inital, enum typeReq typ) {
  a->typ = typ;
  switch (typ) {
  case INT: {
    a->array = (int *)malloc(inital * sizeof(int));
    break;
  }
  case CHAR: {
    a->array = (char *)malloc(inital * sizeof(char));
    break;
  }
  case BOOLEAN: {
    a->array = (bool *)malloc(inital * sizeof(bool));
    break;
  }
  default: {
    printf("Select a proper type\n");
    return;
  }
  }
  a->used = 0;
  a->size = inital;
}

void insertArray(Array *a, void *val) {
  if (a->used == a->size) {
    a->size *= 2;
    switch (a->typ) {
    case INT:
      a->array = (int *)realloc(a->array, a->size * sizeof(int));
      break;
    case CHAR:
      a->array = (char *)realloc(a->array, a->size * sizeof(char));
      break;
    case BOOLEAN:
      a->array = (bool *)realloc(a->array, a->size * sizeof(bool));
      break;
    default:
      printf("Select a proper type\n");
      return;
    }
  }
  switch (a->typ) {
  case INT:
    ((int *)a->array)[a->used++] = *((int *)val);
    break;
  case CHAR:
    ((char *)a->array)[a->used++] = *((char *)val);
    break;
  case BOOLEAN:
    ((bool *)a->array)[a->used++] = *((bool *)val);
    break;
  default:
    printf("Select a proper type\n");
    return;
  }
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->size = a->used = 0;
}

void printValue(Array *a, size_t index) {
  switch (a->typ) {
  case INT:
    printf("%d\n", ((int *)a->array)[index]);
    break;
  case CHAR:
    printf("%c\n", ((char *)a->array)[index]);
    break;
  case BOOLEAN:
    printf("%s\n", ((bool *)a->array)[index] ? "true" : "false");
    break;
  default:
    printf("Select a proper type\n");
    break;
  }
}

/*
int main() {
  Array a;
  initArray(&a, 5, CHAR);
  for (int i = 0; i < 100; i++) {                  USAGE
    insertArray(&a, &(char){i + '0'});
  }
  printValue(&a, 49);
  printf("%zu", a.used);
  freeArray(&a);
}
*/
