
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

// The if statement for a number
bool is_valid_number_closure(char c) {
  return isdigit(c);
}

// The if statement for an identifier
bool is_valid_ident_closure(char c) {
  return (isalnum(c) && !ispunct(c)) || c == '_';
}

// Parse some text thing
char *get_value(char *text, int *i, bool(*f)(char c)) {

  // Initialize the number string
  char *str = malloc(sizeof(char));
  size_t num_chars = 0;

  // While there are characters and they are digits
  (*i)++;
  while (strlen(text) > *i
    && f(text[*i])) {

    num_chars += 1;
    str = realloc(str, sizeof(char) * num_chars);
    str[num_chars - 1] = text[*i];
    
    // Increment i
    (*i)++;
  }

  // Decrement i
  (*i)--;

  return str;
}

// Tokenize a number
PartialLexerResult tokenize_number(char *text, int *i) {

  // Get the number string
  char *number_string = get_value(text, i, is_valid_number_closure);

  // Create the token
  Token t = (Token){ .type = NUMBER, .value = number_string };

  // If it gets here, it's a valid number
  return (PartialLexerResult){.error = NULL, .token = t};
}

// Tokenize a labeled identifier
PartialLexerResult tokenize_labeled_identifier(char *text, int *i, TokenType t) {

  // Get the name of it
  char *name = get_value(text, i, is_valid_ident_closure);

  // Create the token
  Token tt = (Token){ .type = t, .value = name };

  // Return the partial lexer result
  return (PartialLexerResult){ .error = NULL, .token = tt };
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

    // Prepare the result
    PartialLexerResult res;
    bool hasRes = true;
  
    // All possible cases
    switch (text[i]) {

      // If it is a number
      case '#': {
        res = tokenize_number(text, &i);
        break;
      }
      case '$': {
        res = tokenize_labeled_identifier(text, &i, VAR_IDENT);
        break;
      }
      case '%': {
        res = tokenize_labeled_identifier(text, &i, LABEL_IDENT);
        break;
      }
      case '@': {
        res = tokenize_labeled_identifier(text, &i, CONST_IDENT);
        break;
      }
      case '!': {
        res = tokenize_labeled_identifier(text, &i, GLOBAL_IDENT);
        break;
      }
      case ':': {
        res = (PartialLexerResult) {.token = Token_new(COLON, NULL), NULL};
        break;
      }
      case '.': {
        res = tokenize_labeled_identifier(text, &i, SECT_IDENT);
        break;  
      }
    
      // Default case
      default: {

        // Handle identifiers for keywords
        if (isalpha(text[i])) {
          i--;
          res = tokenize_labeled_identifier(text, &i, KEYWORD);
          
        // No keywords here
        } else {
          hasRes = false;
        }
      }
    }
    
    // If there is an error
    if (res.error != NULL) {
      return (LexerResult){tokens = NULL, .error = res.error};
    }

    // Add the token
    if (hasRes) {
      token_count += 1;
      tokens = realloc(tokens, sizeof(Token) * token_count);
      tokens[token_count - 1] = res.token;
    }

    // Increase i
    i++;
  }

  // Return the list of tokens
  return (LexerResult){.tokens = tokens, .error = NULL, .num_tokens = (size_t)token_count};
}
