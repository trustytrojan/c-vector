// Author: Tarun Rajan
// github.com/trustytrojan/c-vector

#include <stdio.h>
#include <stdbool.h>

#include "vector.h"

bool out_of_bounds(vector* v, size_t index, const char* caller) {
  if(index >= v->size) {
    fprintf(stderr, "%s: index out of bounds: %ld\n  - vector size is %ld\n", caller, index, v->size);
    return true;
  }
  return false;
}

v_element* v_get(vector* v, size_t index) {
  if(out_of_bounds(v, index, "v_get"))
    return NULL;
  return (v->data + index);
}

void v_set(vector* v, size_t index, v_element to_set) {
  if(out_of_bounds(v, index, "v_set"))
    return;
  v->data[index] = to_set;
}

bool v_element_equals(v_element a, v_element b) {
  return (a.type == b.type) && (a.value.i == b.value.i || a.value.f == b.value.f);
}

// -1 returned if element not found
size_t v_indexof(vector* v, v_element to_find) {
  for(size_t i = 0; i < v->size; ++i)
    if(v_element_equals(v->data[i], to_find)) {
      return i;
    }
  return -1;
}

// func must accept a v_element* as its only argument!!!
void v_foreach(vector* v, void func(v_element*)) {
  for(size_t i = 0; i < v->size; ++i)
    func(v->data+i);
}
