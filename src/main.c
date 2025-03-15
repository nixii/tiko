
// Includes
#include "lexer/lexer.h"
#include "deque/deque.h"
#include "lexer/token.h"

// Main function
int main(void) {

  LexerResult res = tokenize("#150 #20");
  if (res.tokens && !Deque_isEmpty(res.tokens)) {
    while (!Deque_isEmpty(res.tokens)) {
      Token *t = Deque_popFront(res.tokens);
      Token_repr(t);
    }
  }
  return 0;
}
