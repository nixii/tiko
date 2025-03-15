
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

////////////////////////////////////////
// Initialize a new deque with no values
Deque *Deque_new(void) {
  
  // Create the deque as a pointer so it's heap-allocated
  Deque *d = malloc(sizeof(Deque));

  // Set all the properties
  d->first = NULL;
  d->last = NULL;
  d->size = 0;

  // Return the deque
  return d;
}


////////////////////////////
// Check if a deque is empty
bool Deque_isEmpty(Deque *deque) {
  return !deque->first || !deque->last;
}


//////////////////////////////////////////////
// Push an element onto the front of the deque
void Deque_pushFront(Deque *deque, void *content) {

  // Create a new node
  DequeNode *node = malloc(sizeof(DequeNode));

  // Set all the properties of the nde
  node->data = content;
  node->prevNode = NULL;
  node->nextNode = deque->first;
  deque->size += 1;
  
  // Set the correct node to this
  if (Deque_isEmpty(deque)) {
    deque->last = node; 
  } else {
    deque->first->prevNode = node;
  }

  // Set this to be the first node in the deque
  deque->first = node;
}


/////////////////////////////////////////////
// Push an element onto the back of the deque
void Deque_pushBack(Deque *deque, void *content) {

  // Create a node on the heap
  DequeNode *node = malloc(sizeof(DequeNode));

  // Set all the properties of the node
  node->data = content;
  node->nextNode = NULL;  
  node->prevNode = deque->last;
  deque->size += 1;

  // Set the correct node to this
  if (Deque_isEmpty(deque)) {
    deque->first = node;
  } else {
    deque->last->nextNode = node;
  }

  // Set this node to be the last node in the deque
  deque->last = node;
}



////////////////////////////////////////////
// Pop the first node in the deque's content
void *Deque_popFront(Deque *deque) {

  // Return no data if the deque is empty
  if (Deque_isEmpty(deque))
    return NULL;

  // Prepare the buffers
  void *content;
  DequeNode *node = deque->first;

  // Change the elements in the deque
  deque->first = node->nextNode;
  deque->size -= 1;

  // Update the other elements that point here
  if (!deque->first)
    deque->last = NULL;
  else
    deque->first->prevNode = NULL;

  // Get the content, free the data (!), and return the content
  content = node->data;
  free(node);
  return content;
}



///////////////////////////////////////////////
// Pop the last elemenet in the deque's content
void *Deque_popBack(Deque *deque) {

  // Return nothing if the deque is empty
  if (Deque_isEmpty(deque))
    return NULL;

  // Prepare the buffers
  void *content;
  DequeNode *node = deque->last;

  // Change the elements in the deque
  deque->last = node->prevNode;
  deque->size -= 1;

  // Update the other elements
  if (!deque->last)
    deque->first = NULL;
  else
    deque->last->nextNode = NULL;

  // Get the content, free the data (!), and return the content
  content = node->data;
  free(node);
  return content;
}



/////////////////////////////////////////////
// Peek the first node in the deque's content
void *Deque_peekFront(Deque *deque) {
  if (Deque_isEmpty(deque))
    return NULL;
  return deque->first->data;
}


//////////////////////////////////////////////
// Peek the second node in the deque's content
void *Deque_peekBack(Deque *deque) {
  if (Deque_isEmpty(deque))
    return NULL;
  return deque->last->data;
}


////////////////////////
// Free the entire deque
void Deque_free(Deque *deque) {

  // The first node in the deque
  DequeNode *first = deque->first;

  // For each deque node, free it
  while (first != NULL) {
    DequeNode *node = first;
    first = node->nextNode;
    free(node);
  }

  // Finally, free the deque
  free(deque);
}
