// Hi PotatoFur! :D

#include "dynarr.h"
#include <stdio.h>

int main(void) {

  DynArr arr = DynArr_new(2, sizeof(int));
  int x = 1;
  DynArr_set(&arr, 1, &x);
  int y;
  DynArr_getTo(&arr, 1, &y);
  printf("%d\n", y);

  return 0;
}
