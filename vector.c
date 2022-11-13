#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "vector.h"

vector* v_new() {
  vector* v = malloc(sizeof(vector));
  *v = (vector){
    .size = 0,
    .capacity = INITIAL_SIZE,
    .data = malloc(INITIAL_SIZE*sizeof(v_element))
  };
  return v;
}

void v_free(vector* v) {
  free(v->data);
  free(v);
}

void v_grow(vector* v) {
  if(v->size == v->capacity)
    v->data = realloc(v->data, (v->capacity *= 1.5));
}

void v_print(vector* v) {
  printf("[ ");
  for(size_t i = 0; i < v->size; ++i) {
    const v_element el = v->data[i];
    switch(el.type) {
      case _int: printf("%ld", el.value.i); break;
      case _uint: printf("%lu", (unsigned long)el.value.i); break;
      case _float:
      case _double: printf("%f", el.value.f); break;
      case _bool: printf("%s", (el.value.i) ? "true" : "false"); break;
      case _char: printf("'%c'", (char)el.value.i); break;
      case _string: printf("\"%s\"", (char*)el.value.i); break;
      case _ptr: printf("%p", (void*)el.value.i);
    }
    if(i < v->size-1)
      printf(", ");
  }
  printf(" ]\n");
}

void v_print_types(vector* v) {
  printf("[ ");
  for(size_t i = 0; i < v->size; ++i) {
    const v_element el = v->data[i];
    switch(el.type) {
      case _int: printf("(int) %ld", el.value.i); break;
      case _uint: printf("(long) %lu", (unsigned long)el.value.i); break;
      case _float:
      case _double: printf("(double) %lf", el.value.f); break;
      case _bool: printf("(bool) %s", (el.value.i) ? "true" : "false"); break;
      case _char: printf("(char) '%c'", (char)el.value.i); break;
      case _string: printf("(char* %p) \"%s\"", (char*)el.value.i, (char*)el.value.i); break;
      case _ptr: printf("(void*) %p", (void*)el.value.i);
    }
    if(i < v->size-1)
      printf(", ");
  }
  printf(" ]\n");
}
