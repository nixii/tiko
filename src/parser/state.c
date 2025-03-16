
// Include all of the state things
#include <stdlib.h>
#include "state.h"

//  Create a new program state
ProgramState ProgramState_new() {
  ProgramState s;
  s.constants = (Constant *)malloc(0);
  s.num_constants = 0;
  s.variables = (Variable *)malloc(0);
  s.num_variables = 0;
  s.labels = (Label *)malloc(0);
  s.num_labels = 0;
  s.main = NULL;
  return s;
}
