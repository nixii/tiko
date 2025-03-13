
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
    arr.data = NULL;
    arr.size = 0;
    return arr;
  }

  // Set the data
  arr.data = data;
  
  // Return the array
  return arr;
}

// Set an element
void DynArr_set(DynArr *arr, size_t index, void *data) {

  if (index < arr->size) {
    memcpy((char *)arr->data + index * arr->elem_size, data, arr->elem_size);
  } else {
    fprintf(stderr, "Error: index out of bounds!");
  }
  
}

// Get an element out
void DynArr_getTo(DynArr *arr, size_t index, void *to) {

  if (index < arr->size) {
    memcpy(to, (const char *)arr->data + index * arr->elem_size, arr->elem_size);
  } else {
    fprintf(stderr, "Error: index out of bounds!");
  }
  
}
