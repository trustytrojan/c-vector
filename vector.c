#include "vector.h"

vector* vector_new() {
  vector* v = malloc(sizeof(vector));
  *v = (vector){ .size = 0, .capacity = INITIAL_SIZE, .data = malloc(INITIAL_SIZE*sizeof(void*)) };
}

void vector_free(vector* v) {
  free(v->data);
  free(v);
}

void vector_realloc(vector* v) {
  float scale = 0;

  if(v->size == v->capacity)
    scale = 1.5;
  else if(v->size == v->capacity/2)
    scale = 0.75;
  
  if(scale != 0)
    v->data = realloc(v->data, (v->capacity *= scale));
}

void vector_print(vector* v) {
  printf("{ ");
  for(int i = 0; i < v->size; ++i) {
    const vector_element el = v->data[i];
    switch(el.type) {
      case _int: printf("(int) %d", el.value.i); break;
      case _lu: printf("(long) %lu", el.value.lu); break;
      case _float: printf("(float) %f", el.value.f); break;
      case _lf: printf("(double) %lf", el.value.lf); break;
      case _bool: printf("(bool) %s", (el.value.b) ? "true" : "false"); break;
      case _char: printf("(char) '%c'", el.value.c); break;
      case _string: printf("(char* %p) \"%s\"", el.value.s); break;
      case _ptr: printf("(void*) %p", el.value.p);
    }
    if(i < v->size-1)
      printf(", ");
  }
  printf(" }\n");
}
