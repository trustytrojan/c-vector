#include <string.h>
#include <stdarg.h>

#include "vector.h"

// internal use only
void v_pushi(vector* v, v_eltype type, long data) {
  v_grow(v);
  v->data[v->size++] = (v_element){ .type = type, .value = { .i = data } };
}

// internal use only
void v_pushf(vector* v, v_eltype type, double data) {
  v_grow(v);
  v->data[v->size++] = (v_element){ .type = type, .value = { .f = data } };
}

void v_push(vector* v, const char* types, ...) {
  va_list args;
  const int len = strlen(types);
  int n_types = 0;
  for(int i = 0; i < len; ++i) {
    if(types[i] == '%')
      ++n_types;
  }
  va_start(args, types);
  for(int i = 0; i < len; ++i) {
    if(types[i] != '%') continue;
    switch(types[i+1]) {
      case 'b': v_pushi(v, _bool, va_arg(args, int)); break;
      case 'f': v_pushf(v, _float, va_arg(args, double)); break;
      case 'i':
      case 'd': v_pushi(v, _int, va_arg(args, int)); break;
      case 'c': v_pushi(v, _char, va_arg(args, int)); break;
      case 'l':
        switch(types[i+2]) {
          case 'u': v_pushi(v, _uint, va_arg(args, unsigned long)); break;
          case 'f': v_pushf(v, _double, va_arg(args, double)); break;
          case 'i': v_pushi(v, _int, va_arg(args, long));
        }
        break;
      case 'u':
        v_pushi(v, _uint, va_arg(args, unsigned));
        break;
      case 's':
        v_pushi(v, _string, va_arg(args, unsigned long));
        break;
      case 'p':
        v_pushi(v, _ptr, va_arg(args, unsigned long));
        break;
    }
  }
  va_end(args);
}
