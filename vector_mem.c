// THIS IS MY OWN CODE!!!
// https://github.com/trustytrojan/c-vector

#include <stdlib.h>

#include "vector.h"

vector* v_new() {
  vector* v = malloc(sizeof(vector));
  *v = (vector){
    .size = 0,
    .capacity = INITIAL_CAPACITY,
    .data = malloc(INITIAL_CAPACITY*sizeof(v_element))
  };
  return v;
}

// does NOT copy data pointed to by pointers inside a vector
vector* v_copy(vector* v) {
  vector* new_v = malloc(sizeof(vector));
  *new_v = (vector){
    .size = v->size,
    .capacity = v->capacity,
    .data = malloc(v->capacity*sizeof(v_element))
  };
  for(size_t i = 0; i < v->size; ++i)
    new_v->data[i] = v->data[i];
  return new_v;
}

void v_free(vector* v) {
  free(v->data);
  free(v);
}

void v_grow(vector* v) {
  if(v->size == v->capacity)
    v->data = realloc(v->data, (v->capacity *= 1.5));
}