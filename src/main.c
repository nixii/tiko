
// Includes
#include <stdio.h>
#include "deque/deque.h"
#include "lexer/token.h"

// Main function
int main(void) {

  Token t = Token_new(OPERATION, NULL);
  printf("%d\n", t.type);

}
