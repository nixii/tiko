
#pragma once

// Types of AST nodes
typedef enum AstNodeType {
  AST_SECT,
  AST_LABEL_DEF,
  AST_COMMAND,
  AST_OPERATION
} AstNodeType;

// Define a node
typedef struct AstNode {
  AstNodeType type;
  char *value;

  struct AstNode **argv;
  int argc;

  struct AstNode *next_line;
} AstNode;

// Node functions
AstNode *AstNode_new(AstNodeType type,
                     char *value,
                     AstNode **argv,
                     int argc);
