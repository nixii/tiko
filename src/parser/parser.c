
// Get the symbols
#include <stdlib.h>
#include <string.h>
#include "parser.h"

// Partial parser result
typedef struct PartialParserResult {
  AstNode *node;
  Error *e;
} PartialParserResult;

// TODO
// Parse a keyword
PartialParserResult parseKeyword(LexerResult *tokens, int *i) {
}

// Parse!
ParserResult parse(LexerResult *tokens) {

  // Create a new parser
  ParserResult p = { .nodes = NULL, .error = NULL, .num_lines = 0L };

  // Propegate the error
  if (tokens->error) {
    p.error = tokens->error;
    return p;
  }

  // Loop through all tokens
  int i;
  for (i = 0; i < tokens->num_tokens; i++) {
    Token *t = &(tokens->tokens[i]);

    // Is it a ...? 
    switch (t->type) {

      // Keywords woohooo
      case KEYWORD:
        break;

      // Unhandled yet
      default:
        break;
    }    
  }

  return p;
}
