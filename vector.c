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
      case _int: printf("%d", (int)el.value.i); break;
      case _uint: printf("%lu", el.value.u); break;
      case _float:
      case _double: printf("%f", el.value.f); break;
      case _bool: printf("%s", (el.value.u) ? "true" : "false"); break;
      case _char: printf("'%c'", (char)el.value.u); break;
      case _string: printf("\"%s\"", (char*)el.value.p); break;
      case _ptr:
        if(el.value.p) printf("%p", el.value.p);
        else printf("NULL");
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
      case _int: printf("(int) %d", (int)el.value.i); break;
      case _uint: printf("(long) %lu", el.value.u); break;
      case _float:
      case _double: printf("(double) %lf", el.value.f); break;
      case _bool: printf("(bool) %s", (el.value.u) ? "true" : "false"); break;
      case _char: printf("(char) '%c'", (char)el.value.u); break;
      case _string: printf("(char* %p) \"%s\"", (char*)el.value.p, (char*)el.value.p); break;
      case _ptr: printf("(void*) %p", el.value.p);
    }
    if(i < v->size-1)
      printf(", ");
  }
  printf(" ]\n");
}
