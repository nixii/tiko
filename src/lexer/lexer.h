
// Get the deque data
#include <stdlib.h>
#include "../error/error.h"
#include "token.h"

// Type for the data a lexer returns
typedef struct LexerResult {
  Token *tokens;
  Error *error;
  size_t num_tokens;
} LexerResult;

// Define the buffer size to 1kB
#define FREAD_BUFFER_SIZE 1024

// Tokenize the input
LexerResult tokenize(const char *file_name);
