#include "vector.h"

int main() {
  vector* v = v_new();
  v_push(v, "%b %c %i", 2, 'V', 99);
  v_print(v);
  v_print_types(v);
  v_free(v);
}