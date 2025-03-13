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

// Functions (names descriptive)
DynArr DynArr_new(size_t size, size_t elem_size);
void DynArr_set(DynArr *arr, size_t index, void *data);
void DynArr_getTo(DynArr *arr, size_t index, void *to);

