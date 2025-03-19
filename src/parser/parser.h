
#pragma once

#include "ast.h"
#include "../error/error.h"
#include "../lexer/token.h"
#include "../lexer/lexer.h"

// Parser result
typedef struct ParserResult {
  AstNode *nodes;

  unsigned long num_lines;
  Error *error;
} ParserResult;

// Parse the tokens into an AST
ParserResult parse(LexerResult *tokens);
