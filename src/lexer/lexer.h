
// Get the deque data
#include "../deque/deque.h"
#include "../error/error.h"

// Type for the data a lexer returns
typedef struct LexerResult {
  Deque *tokens;
  Error *error;
} LexerResult;

// Tokenize the input
LexerResult tokenize(char *text);
