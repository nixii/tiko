#pragma once

// Includes
#include <stdbool.h>
#include <stdlib.h>

// This stores a single node inside of the deque
typedef struct DequeNode {
  void *data;
  struct DequeNode *nextNode;
  struct DequeNode *prevNode;
} DequeNode;

// Create the struct for the deque
typedef struct Deque {
  size_t size;
  DequeNode *first;
  DequeNode *last;
} Deque;

// Functons
Deque *Deque_new(void);
bool Deque_isEmpty(Deque *deque);
void Deque_pushFront(Deque *deque, void *content);
void Deque_pushBack(Deque *deque, void *content);
void *Deque_popFront(Deque *deque);
void *Deque_popBack(Deque *deque);
void *Deque_peekFront(Deque *deque);
void *Deque_peekBack(Deque *deque);
