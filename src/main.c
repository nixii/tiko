
#include "dynarr.h"
#include <stdio.h>

int main(void) {

  DynArr arr = DynArr_new(2, sizeof(float));
  float x = 20.4;
  DynArr_set(&arr, 1, &x);
  float x2 = 12.3; // Create a new floating point number to set the 0th index to
  DynArr_set(&arr, 0, &x2); // Set the dynamic array's 0th index to x3
  float y;
  DynArr_get(&arr, 1, &y);
  float y2; // Create a buffer for the 0th index of the array to be loaded into
  DynArr_get(&arr, 0, &y2); // Load the 0th index into y2
  printf("%f\n", y);
  printf("%f\n", y2); // Print y2 (the 0th index) out

  return 0;
}
