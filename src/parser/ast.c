
// Imports
#include <stdlib.h>
#include "ast.h"

// Create a new AST node
AstNode *AstNode_new(AstNodeType type,
                     char *value,
                     AstNode **argv,
                     int argc) {

  // Allocate the memory
  AstNode *n = (AstNode *)malloc(sizeof(AstNode));

  // Make sure the memory was allocated
  if (n == NULL) {
    return n;
  }

  // Set the values and return the node
  n->type = type;
  n->value = value;
  n->argv = argv;
  n->argc = argc;
  return n;
}

