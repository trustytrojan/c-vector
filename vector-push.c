#include "vector.h"

void vector_push_int(vector* v, int element) {
  vector_realloc(v);
  v->data[v->size++] = (vector_element){ .type = _int, .value = { .i = element } };
}

void vector_push_lu(vector* v, unsigned long element) {
  vector_realloc(v);
  v->data[v->size++] = (vector_element){ .type = _lu, .value = { .lu = element } };
}

void vector_push_float(vector* v, float element) {
  vector_realloc(v);
  v->data[v->size++] = (vector_element){ .type = _float, .value = { .f = element } };
}

void vector_push_lf(vector* v, double element) {
  vector_realloc(v);
  v->data[v->size++] = (vector_element){ .type = _lf, .value = { .lf = element } };
}

void vector_push_bool(vector* v, bool element) {
  vector_realloc(v);
  v->data[v->size++] = (vector_element){ .type = _bool, .value = { .b = element } };
}

void vector_push_char(vector* v, char element) {
  vector_realloc(v);
  v->data[v->size++] = (vector_element){ .type = _char, .value = { .c = element } };
}

void vector_push_str(vector* v, char* element) {
  vector_realloc(v);
  v->data[v->size++] = (vector_element){ .type = _string, .value = { .s = element } };
}

void vector_push_ptr(vector* v, void* element) {
  vector_realloc(v);
  v->data[v->size++] = (vector_element){ .type = _ptr, .value = { .s = element } };
}
