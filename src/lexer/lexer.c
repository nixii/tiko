
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "lexer.h"
#include "token.h"

// The type for a partial lexer result
typedef struct PartialLexerResult {
  Token token;
  Error *error;
} PartialLexerResult;

// Tokenize a number
PartialLexerResult tokenize_number(char *text, int *i) {

  // Initialize the number string
  char *number_string = malloc(sizeof(char));
  size_t num_chars = 0;

  // While there are characters and they are digits
  (*i)++;
  while (strlen(text) > *i
    && isdigit(text[*i])) {

    num_chars += 1;
    number_string = realloc(number_string, sizeof(char) * num_chars);
    number_string[num_chars - 1] = text[*i];
    
    // Increment i
    (*i)++;
  }

  // Decrement i
  (*i)--;

  // Allocate the token on the heap (deque requirement)
  Token t;
  t.type = NUMBER;
  t.value = number_string;

  // If it gets here, it's a valid number
  return (PartialLexerResult){.error = NULL, .token = t};
} 

// Tokenize a string
LexerResult tokenize(char *text) {

  // How many characters are there
  int i = 0;

  // Create the deque of tokens
  Token *tokens = malloc(0);
  int token_count = 0;

  // While there is a character
  while (strlen(text) > i) {

    // All possible cases
    switch (text[i]) {

      // If it is a number
      case '#': {

        // Get the token result
        PartialLexerResult res = tokenize_number(text, &i);

        // If there is an error
        if (res.error != NULL) {
          return (LexerResult){tokens = NULL, .error = res.error};
        }

        // Add the token
        token_count += 1;
        tokens = realloc(tokens, sizeof(Token) * token_count);
        tokens[token_count - 1] = res.token;
      }

      // Default case
      default: {}
    }

    // Increase i
    i++;
  }

  // Return the list of tokens
  return (LexerResult){.tokens = tokens, .error = NULL, .num_tokens = (size_t)token_count};
}
