
// Includes
#include "token.h"

// Create a new token
Token Token_new(TokenType type, char *value) {
  Token t = {.type = type, .value = value};
  return t;
}
