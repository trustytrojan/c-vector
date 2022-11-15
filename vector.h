#ifndef vector_h
#define vector_h

#include <stdlib.h>

#define INITIAL_CAPACITY 8

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


// vector_mem.c

vector* v_new();
vector* v_copy(vector* v);
void v_free(vector* v);
void v_grow(vector* v);
void v_shrink(vector* v);
v_element* v_realloc(vector* v, size_t capacity);


// vector.c

v_element* v_get(vector* v, size_t index);
v_element* v_set(vector* v, size_t index, v_element to_set);
size_t v_indexof(vector* v, v_element to_find);
v_element* v_find(vector* v, v_element to_find);
void v_foreach(vector* v, void func(v_element*));


// vector_print.c

void v_print(vector* v);
void v_printtypes(vector* v);
void v_debug(vector* v);


// vector_push.c

void v_push(vector* v, const char* types, ...);

#endif