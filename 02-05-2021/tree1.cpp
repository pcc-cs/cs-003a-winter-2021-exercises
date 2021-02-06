/**
 * Recursive tree traversal.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>
#include "node.h"

// Hard-coded creation with predetermined values
template <class T>
Node<T> *create() {
  Node<T> *node = new Node<T>(10.0);
  node->left = new Node<T>(2);
  node->left->right = new Node<T>(7);
  node->right = new Node<T>(15);
  node->right->left = new Node<T>(13);
  node->right->right = new Node<T>(25);
  return node;
}

template <class T>
bool find(Node<T> *node, T value) {
  if (node == nullptr) {
    return false;
  }
  if (node->value == value) {
    return true;
  }
  // Recursive call
  if (value > node->value) {
    return find(node->right, value);
  }
  return find(node->left, value);
}

int main() {
  Node<double> *tree = create<double>();
  printf("tree root = %0.1lf\n", tree->value);

  // Find using recursion
  printf("15 found: %s\n", find(tree, 15.0) ? "true" : "false");
  printf("11 found: %s\n", find(tree, 11.0) ? "true" : "false");
}