
// Includes
#include <stdio.h>
#include "deque.h"

// Main function
int main(void) {

  // Create the deque
  Deque *my_deque = Deque_new();

  // The numbers; these have to be stored here because I can't lose the value else I
  // no longer have a pointer to them. I could use malloc() but that introduces errors
  // and more code that I don't want to deal with in this test
  int nums[10];

  // For each number 0-9, add it into the array and push it into the deque
  for (int i = 0; i < 10; i++) {
    nums[i] = i;
    Deque_pushBack(my_deque, &nums[i]);
  }

  // Store the current number from popping the front of the deque
  int *num = Deque_popFront(my_deque);

  // While this isn't equal to null, print the value out and get the next number.
  while (num != NULL) {
    printf("Number is now: %d\n", *num);
    num = Deque_popFront(my_deque);
  }

  // Free the deque
  Deque_free(my_deque);

  // Return success status code
  return 0;
}
