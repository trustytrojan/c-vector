#include "vector.h"

vector* vector_new() {
  vector* v = malloc(sizeof(vector));
  *v = (vector){
    .size = 0,
    .capacity = INITIAL_SIZE,
    .data = malloc(INITIAL_SIZE*sizeof(vector_element))
  };
  return v;
}

void vector_free(vector* v) {
  free(v->data);
  free(v);
}

void vector_grow(vector* v) {
  if(v->size == v->capacity)
    v->data = realloc(v->data, (v->capacity *= 1.5));
}

void vector_print(vector* v) {
  printf("[ ");
  for(size_t i = 0; i < v->size; ++i) {
    const vector_element el = v->data[i];
    switch(el.type) {
      case _int: printf("%d", el.value.i); break;
      case _lu: printf("%lu", el.value.lu); break;
      case _float: printf("%f", el.value.f); break;
      case _lf: printf("%lf", el.value.lf); break;
      case _bool: printf("%s", (el.value.b) ? "true" : "false"); break;
      case _char: printf("'%c'", el.value.c); break;
      case _string: printf("\"%s\"", el.value.s); break;
      case _ptr:
        if(el.value.p) printf("%p", el.value.p);
        else printf("NULL");
    }
    if(i < v->size-1)
      printf(", ");
  }
  printf(" ]\n");
}

void vector_print_types(vector* v) {
  printf("[ ");
  for(size_t i = 0; i < v->size; ++i) {
    const vector_element el = v->data[i];
    switch(el.type) {
      case _int: printf("(int) %d", el.value.i); break;
      case _lu: printf("(long) %lu", el.value.lu); break;
      case _float: printf("(float) %f", el.value.f); break;
      case _lf: printf("(double) %lf", el.value.lf); break;
      case _bool: printf("(bool) %s", (el.value.b) ? "true" : "false"); break;
      case _char: printf("(char) '%c'", el.value.c); break;
      case _string: printf("(char* %p) \"%s\"", el.value.s, el.value.s); break;
      case _ptr: printf("(void*) %p", el.value.p);
    }
    if(i < v->size-1)
      printf(", ");
  }
  printf(" ]\n");
}
