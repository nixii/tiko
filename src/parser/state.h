
#pragma once

#include "node.h"

typedef struct Constant {
  unsigned int id;
  char *value; // Computed at compile time
} Constant;

typedef struct Variable {
  unsigned int id;
  char *value; // Computed at compile time
} Variable;

typedef struct Label {
  unsigned int id;
  CodeBlock b;
} Label;

typedef struct ProgramState {
  Constant *constants;
  int num_constants;
  
  Variable *variables;
  int num_variables;
  
  Label *labels;
  int num_labels;
  Label *main;
} ProgramState;

ProgramState ProgramState_new();
