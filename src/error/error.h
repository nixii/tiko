#pragma once

// Enum for different error types
typedef enum ErrorType {
  ILLEGAL_CHARACTER
} ErrorType;

// Create the type for an error
typedef struct Error {
  char *data;
  ErrorType type;
} Error;

// Create a new error
Error *Error_new(ErrorType type, char *data);
