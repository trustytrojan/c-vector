#include "vector.h"

void v_push_i(vector* v, v_eltype type, long element) {
  v_grow(v);
  v->data[v->size++] = (v_element){ .type = type, .value = { .i = element } };
}

void v_push_f(vector* v, v_eltype type, double element) {
  v_grow(v);
  v->data[v->size++] = (v_element){ .type = type, .value = { .f = element } };
}

void v_push(vector* v, const char* types, ...) {
  va_list args;
  const int len = strlen(types);
  int n_types = 0;
  for(int i = 0; i < len; ++i) {
    if(types[i] == '%')
      ++n_types;
  }
  va_start(args, n_types);
  for(int i = 0; i < len; ++i) {
    if(types[i] == '%')
      switch(types[i+1]) {
        case 'b': v_push_i(v, _bool, va_arg(args, int)); break;
        case 'f': v_push_f(v, _float, va_arg(args, double)); break;
        case 'i':
        case 'd': v_push_i(v, _int, va_arg(args, int)); break;
        case 'l':
          switch(types[i+2]) {
            case 'u': v_push_i(v, _uint, va_arg(args, unsigned long)); break;
            case 'f': v_push_f(v, _double, va_arg(args, double)); break;
            case 'i': v_push_i(v, _int, va_arg(args, long));
          }
          break;
        case 'u':
          v_push_i(v, _uint, va_arg(args, unsigned));
          break;
        case 's':
          v_push_i(v, _string, va_arg(args, unsigned long));
          break;
        case 'p':
          v_push_i(v, _ptr, va_arg(args, unsigned long));
          break;
      }
  }
  va_end(args);
}
