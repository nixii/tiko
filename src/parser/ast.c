
// Includes
#include <stdlib.h>
#include "ast.h"

// Functions
AstNode AstNode_new(AstNodeType t, char *value) {
  return (AstNode){ .type = t, .argc = 0, .argv = (AstNode **)malloc(0), .value = value };
}

void AstNode_addArg(AstNode *node, AstNode *arg) { // Very safe, I know
  node->argc += 1;
  node->argv = (AstNode **)realloc(node->argv, sizeof(AstNode*) * node->argc);
  node->argv[node->argc - 1] = arg;
}
