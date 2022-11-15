#include <stdlib.h>
#include <stdio.h>

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

// internal use only - called when pushing or inserting elements
void v_grow(vector* v) {
  if(v->size == v->capacity)
    v->data = realloc(v->data, (v->capacity *= 1.5));
}

// internal use only - called when popping or removing elements
void v_shrink(vector* v) {
  if(v->size == 0.75*v->capacity)
    v->data = realloc(v->data, (v->capacity *= 0.75));
}

// increase or decrease your vector's capacity
// returns pointer to new memory block (start of the array)
// if capacity <= vector size, returns NULL
v_element* v_realloc(vector* v, size_t capacity) {
  if(capacity <= v->size) {
    fprintf(stderr, "v_realloc: desired capacity must be more than vector size\n  desired capacity: %lu\n  current vector size: %lu\n", capacity, v->size);
    return NULL;
  }
  return (v->data = realloc(v->data, (v->capacity = capacity)));
}