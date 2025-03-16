
// Includes
#include <stddef.h>
#include <stdio.h>
#include "lexer/lexer.h"
#include "lexer/token.h"
#include <unistd.h>

// Main function
int main(int argc, char **argv) {

  // Make sure there are enough arguments
  if (argc != 2) {
    fprintf(stderr, "incorrect usage\n");
    return 1;
  }

  // Get the file name
  const char *file_name = argv[1];
  if (file_name == NULL) {
    fprintf(stderr, "unexpected error\n");
    return 1;
  }

  // Make sure the file exists
  if (access(file_name, F_OK) != 0) {
    fprintf(stderr, "file doesn't exist\n");
    return 1;
  }

  // Tell the lexer to do stuff
  LexerResult res = tokenize(file_name);
  printf("%zu\n", res.num_tokens);

  // // If there isn't an error and there are actually tokens
  if (res.tokens) {
  
    size_t i = 0;
    
    // While the deque still has tokens
    while (i < res.num_tokens) {

      // Get the token
      Token t = res.tokens[i];
  
      // Print the token
      Token_repr(&t);
      i++;
    }
  }

  // Return 0
  return 0;
}
