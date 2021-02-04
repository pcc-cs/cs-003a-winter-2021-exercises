/**
 * Templated node.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/
#ifndef NODE_H_
#define NODE_H_

template <class T>
struct Node {
  T value;
  Node *next;
  Node(T);
};

template <class T>
Node<T>::Node(T v) : value(v), next(nullptr) {
}

#endif  // NODE_H_/**