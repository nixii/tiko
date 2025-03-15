
#include "error.h"

// Define the new error type
Error Error_new(ErrorType type, char* data) {
  return (Error){ .type = type, .data = data};
}
