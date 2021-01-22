/**
 * Linked list implementation.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include "list.h"

List::List() : _head(nullptr), _tail(nullptr) {
}

// O(1) time complexity because it takes "constant" time
// irrespective of the size of the list
void List::add(int v) {
  // Be sure to create nodes on the heap, NOT on the stack
  // as an "automatic" variable!
  Node *np = new Node(v);
  if (_head == nullptr) {
    // Be sure to update ALL the affected attributes
    _head = np;
    _tail = np;
    return;
  }
  _tail->next = np;
  _tail = _tail->next;
}

void List::dump() {
  // The loop to traverse the list
  for (Node *np = _head; np != nullptr; np = np->next) {
    if (np != _head) {
      printf(" -> ");
    }
    printf("%d", np->value);
  }
  printf("\n");
}