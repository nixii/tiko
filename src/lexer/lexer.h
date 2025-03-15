
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

// Tokenize the input
LexerResult tokenize(char *text);
