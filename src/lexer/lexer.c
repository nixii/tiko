
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

// Read more
size_t read_more(char buffer[FREAD_BUFFER_SIZE],
                 FILE* f) {
  return fread(buffer, sizeof(char), FREAD_BUFFER_SIZE, f);
}

// Parse some text thing
char *get_value(char buffer[FREAD_BUFFER_SIZE],
                size_t *bytes_read,
                size_t *bytes_processed,
                FILE *f,
                bool(*fn)(char c)) {

  // Initialize the number string
  char *str = malloc(sizeof(char));
  size_t num_chars = 0;

  // While there are characters and they are digits
  (*bytes_processed)++;
  while (*bytes_processed < *bytes_read && bytes_read > 0 && fn(buffer[*bytes_processed])) {

    num_chars += 1;
    str = realloc(str, sizeof(char) * num_chars);
    str[num_chars - 1] = buffer[*bytes_processed];
    
    // Increment i
    (*bytes_processed)++;

    // Make sure you grab stuff
    if (*bytes_processed >= *bytes_read) {
      *bytes_read = read_more(buffer, f);
    }
  }

  // Decrement i
  (*bytes_processed)--;

  return str;
}
//          res = tokenize_number(buffer, bytes_read, &bytes_processed, f);

// Tokenize a number
PartialLexerResult tokenize_number(char buffer[FREAD_BUFFER_SIZE],
                                   size_t *bytes_read,
                                   size_t *bytes_processed,
                                   FILE *f) {

  // Get the number string
  char *number_string = get_value(buffer, bytes_read, bytes_processed, f, is_valid_number_closure);

  // Create the token
  Token t = (Token){ .type = NUMBER, .value = number_string };

  // If it gets here, it's a valid number
  return (PartialLexerResult){.error = NULL, .token = t};
}

// Tokenize a labeled identifier
PartialLexerResult tokenize_labeled_identifier(char buffer[FREAD_BUFFER_SIZE],
                                               size_t *bytes_read,
                                               size_t *bytes_processed,
                                               FILE *f,
                                               TokenType t) {

  // Get the name of it
  char *name = get_value(buffer, bytes_read, bytes_processed, f, is_valid_ident_closure);

  // Create the token
  Token tt = (Token){ .type = t, .value = name };

  // Return the partial lexer result
  return (PartialLexerResult){ .error = NULL, .token = tt };
}

// Tokenize a string
LexerResult tokenize(const char *file_name) {

  // How many characters are there
  int i = 0;

  // Create the deque of tokens
  Token *tokens = malloc(0);
  int token_count = 0;

  // Load the buffer
  char buffer[FREAD_BUFFER_SIZE];

  // Load the file
  FILE *f = fopen(file_name, "r");
  if (f == NULL) {
    fprintf(stderr, "Error opening file!");
    return (LexerResult){NULL, NULL};
  }

  // Start the read loop
  size_t bytes_read;
  size_t bytes_processed;
  while ((bytes_read = read_more(buffer, f)) > 0) {
    bytes_processed = 0;

    // While there is a character
    while (bytes_processed < bytes_read) {
  
      // Prepare the result
      PartialLexerResult res = (PartialLexerResult){Token_new(ERRTOK, NULL), NULL};
      bool hasRes = true;
    
      // All possible cases
      switch ((buffer[bytes_processed])) {
  
        // If it is a number
        case '#': {
          res = tokenize_number(buffer, &bytes_read, &bytes_processed, f);
          break;
        }

        // Variables
        case '$': {
          res = tokenize_labeled_identifier(buffer, &bytes_read, &bytes_processed, f,  VAR_IDENT);
          break;
        }

        // Labels
        case '%': {
          res = tokenize_labeled_identifier(buffer, &bytes_read, &bytes_processed, f,  LABEL_IDENT);
          break;
        }

        // Constants
        case '@': {
          res = tokenize_labeled_identifier(buffer, &bytes_read, &bytes_processed, f,  CONST_IDENT);
          break;
        }

        // Globals (preset constants)
        case '!': {
          res = tokenize_labeled_identifier(buffer, &bytes_read, &bytes_processed, f,  GLOBAL_IDENT);
          break;
        }

        // Colon for code blocks
        case ':': {
          res = (PartialLexerResult) {.token = Token_new(COLON, NULL), NULL};
          break;
        }

        // Sections
        case '.': {
          res = tokenize_labeled_identifier(buffer, &bytes_read, &bytes_processed, f,  SECT_IDENT);
          break;  
        }

        // Addition/subtraction/mul/div
        case '+':
          res = (PartialLexerResult) {.token = Token_new(OPERATION, "+"), NULL}; break;
        case '-':
          res = (PartialLexerResult) {.token = Token_new(OPERATION, "-"), NULL}; break;
        case '*':
          res = (PartialLexerResult) {.token = Token_new(OPERATION, "*"), NULL}; break;
        case '/':
          res = (PartialLexerResult) {.token = Token_new(OPERATION, "/"), NULL}; break;

      
        // Default case
        default: {
  
          // Handle identifiers for keywords
          if (isalpha(buffer[bytes_processed])) {
            bytes_processed--;
            res = tokenize_labeled_identifier(buffer, &bytes_read, &bytes_processed, f,  KEYWORD);

            
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
      bytes_processed++;
    }
  }

  // Return the list of tokens
  return (LexerResult){.tokens = tokens, .error = NULL, .num_tokens = (size_t)token_count};
}
