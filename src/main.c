
// Includes
#include <stddef.h>
#include "lexer/lexer.h"
#include "lexer/token.h"

// Main function
int main(void) {

  // Get the lexer result of this static string
  LexerResult res = tokenize("#150 #20 $x_test");

  // If there isn't an error and there are actually tokens
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
