
#include "dynarr.h"
#include <stdio.h>

int main(void) {

  DynArr arr = DynArr_new(2, sizeof(float));
  float x = 20.4;
  DynArr_set(&arr, 1, &x);
  float y;
  DynArr_get(&arr, 1, &y);
  printf("%f\n", y);

  return 0;
}
