
#include "dynarr.h"
#include <stdio.h>

int main(void) {

  DynArr arr = DynArr_new(2, sizeof(float));
  float x = 1.2;
  DynArr_set(&arr, 1, &x);
  float y;
  DynArr_get(&arr,./ 1, &y);
  printf("%f\n", y);

  return 0;
}
