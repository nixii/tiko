#pragma once

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
DynArr DynArr_new(size_t size, size_t elem_size);
