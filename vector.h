#ifndef VECTOR
#define VECTOR

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_SIZE 8

typedef union {
  int i;
  unsigned long lu;
  float f;
  double lf;
  bool b;
  char c;
  char* s;
  void* p;
} element_data;

typedef enum { _int, _lu, _float, _lf, _bool, _char, _string, _ptr } element_type;

typedef struct {
  element_type type;
  element_data value;
} vector_element;

typedef struct {
  size_t size;
  size_t capacity;
  vector_element* data;
} vector;

// general purpose
vector* vector_new();
void vector_free(vector* v);
void vector_realloc(vector* v);
void vector_print(vector* v);

// vector_push
void vector_push_int(vector* v, int element);
void vector_push_lu(vector* v, unsigned long element);
void vector_push_float(vector* v, float element);
void vector_push_lf(vector* v, double element);
void vector_push_bool(vector* v, bool element);
void vector_push_char(vector* v, char element);
void vector_push_str(vector* v, char* element);
void vector_push_ptr(vector* v, void* element);

#endif
