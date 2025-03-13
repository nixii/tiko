
#include "dynarr.h"
#include <stdio.h>

int main(void) {
  DynArr arr = DynArr_new(0, sizeof(int));
  printf("Hellllo, world! %zu\n", arr.size);
  return 0;
}
