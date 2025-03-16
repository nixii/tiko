
#pragma once

// Create the type for a token type
typedef enum TokenType {
  KEYWORD,

  LABEL_IDENT,
  VAR_IDENT,
  CONST_IDENT,
  GLOBAL_IDENT,
  SECT_IDENT,

  OPERATION,

  COLON,

  NUMBER,
  BOOL,

  ERRTOK = 99999
} TokenType;

// Create the struct for a token
typedef struct Token {
  TokenType type;
  char *value;
} Token;

// Create a new token
Token Token_new(TokenType type, char *value);
void Token_repr(Token *t);
