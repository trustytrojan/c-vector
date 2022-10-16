#include "vector.h"

// only accepts one element to push into vector
void v_push(vector* v, v_eltype type, ...) {
  v_element el;
  va_list args;
  va_start(args, 1);
  switch(el.type = type) {
    case _int: el.value.i = va_arg(args, int); break;
    case _uint: el.value.u = va_arg(args, unsigned long); break;
    case _float:
    case _double: el.value.f = va_arg(args, double); break;
    case _bool: el.value.u = va_arg(args, int); break;
    case _char: el.value.u = va_arg(args, int); break;
    case _string: el.value.p = va_arg(args, char*); break;
    case _ptr: el.value.p = va_arg(args, void*); break;
    default:
  }
  va_end(args);
  v->data[v->size++] = el;
}
