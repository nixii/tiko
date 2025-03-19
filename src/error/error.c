
#include <stdlib.h>
#include "error.h"

// Define the new error type
Error *Error_new(ErrorType type, char* data) {

  Error *e = (Error *)malloc(sizeof(Error));

  if (e == NULL) {
    return NULL;
  }
  
  e->type = type;
  e->data = data;
  
  return e;
}
