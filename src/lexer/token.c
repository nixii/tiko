
// Includes
#include <stdio.h>
#include "token.h"

// Create a new token
Token Token_new(TokenType type, char *value) {
  Token t = {.type = type, .value = value};
  return t;
}

// Print a token
void Token_repr(Token *t) {
  if (t->value != NULL) {
    printf("(TOKEN: {\n\ttype: %d\n\tvalue: %s\n})\n", t->type, t->value);
  } else {
    printf("(TOKEN: {\n\ttype: %d\n\tvalue: NULL\n})\n", t->type);
  }  
}
