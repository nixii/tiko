
// Includes
#include "lexer/lexer.h"
#include "deque/deque.h"
#include "lexer/token.h"

// Main function
int main(void) {

  // Get the lexer result of this static string
  LexerResult res = tokenize("#150 #20");

  // If there isn't an error and there are actually tokens
  if (res.tokens && !Deque_isEmpty(res.tokens)) {

    // While the deque still has tokens
    while (!Deque_isEmpty(res.tokens)) {

      // Get the token
      Token *t = Deque_popFront(res.tokens);

      // Print the token
      Token_repr(t);

      // FREE THE TOKEN
      free(t); // IMPORTANT: Free the token!
    }
  }

  // Return 0
  return 0;
}
