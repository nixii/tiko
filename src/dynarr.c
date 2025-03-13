
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct for a dynamic array
typedef struct DynArr {
  void *data;
  size_t size;
  size_t elem_size;
} DynArr;

// Create a new dynamic array
DynArr DynArr_new(size_t size, size_t elem_size) {

  // Create the array
  DynArr arr = {
    .size = size,
    .elem_size = elem_size
  };

  // Allocate the memory
  void *data = calloc(size, elem_size);

  // If data is null then report an error
  if (data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for dynamic array.");
    arr.size = 0;
    return arr;
  }

  // Set the data
  arr.data = data;
  
  // Return the array
  return arr;
}
