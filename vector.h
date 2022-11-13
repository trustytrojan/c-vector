#ifndef VECTOR
#define VECTOR

#include <stdlib.h>

#define INITIAL_SIZE 8

typedef union {
  long i;
  double f;
} v_eldata;

typedef enum { _int, _uint, _float, _double, _bool, _char, _string, _ptr } v_eltype;

typedef struct {
  v_eltype type;
  v_eldata value;
} v_element;

typedef struct {
  size_t size;
  size_t capacity;
  v_element* data;
} vector;

vector* v_new();
void v_free(vector* v);
void v_grow(vector* v);
void v_shrink(vector* v);
void v_print(vector* v);
void v_print_types(vector* v);

void v_push(vector* v, const char* types, ...);

#endif
