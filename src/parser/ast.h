
#pragma once

// Types of AST nodes
typedef enum AstNodeType {
  ANT_OPERATION,
  ANT_SECT,
  ANT_DEFINE_LABEL,
  ANT_CALL,
  ANT_KEYWORD
} AstNodeType;

// Create the node
typedef struct AstNode {
  AstNodeType type;

  int argc;
  AstNode **argv; // Pointer to an array of AST nodes

  char *value;
} AstNode;

// Function to make a node
AstNode AstNode_new(AstNodeType t, char *value);
void AstNode_addArg(AstNode *node, AstNode *arg);
