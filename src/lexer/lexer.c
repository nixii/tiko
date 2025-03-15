
#include <stdio.h>
#include <string.h>
#include "lexer.h"

// Tokenize a string
LexerResult tokenize(char *text) {

  // How many characters are there
  size_t i = 0;

  // Create the deque of tokens
  Deque *tokens = Deque_new();

  // While there is a character
  while (strlen(text) > i) {

    i++;
  }

  // Return the list of tokens
  return (LexerResult){.tokens = tokens, .error = NULL};
}
