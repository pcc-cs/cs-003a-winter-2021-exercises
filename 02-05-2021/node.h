/**
 * Binary tree node.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#ifndef NODE_H_
#define NODE_H_

template <class T>
struct Node {
  T value;
  Node *left;
  Node *right;
  explicit Node(T v) : value(v), left(nullptr), right(nullptr) {
  }
};

#endif  // NODE_H_
