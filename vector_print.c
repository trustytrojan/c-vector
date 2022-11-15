// THIS IS MY OWN CODE!!!
// https://github.com/trustytrojan/c-vector

#include <stdio.h>

#include "vector.h"

void v_debug(vector* v) {
  printf("vector @ %p {\n", v);
  printf("  size: %ld\n", v->size);
  printf("  capacity: %ld\n", v->capacity);
  printf("  data: %p\n", v->data);
  printf("}\n");
}

void v_print(vector* v) {
  printf("[ ");
  for(size_t i = 0; i < v->size; ++i) {
    const v_element el = v->data[i];
    switch(el.type) {
      case _int: printf("%ld", el.value.i); break;
      case _uint: printf("%lu", (unsigned long)el.value.i); break;
      case _float:
      case _double: printf("%lf", el.value.f); break;
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
