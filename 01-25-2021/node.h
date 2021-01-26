/**
 * Node structure.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/
#ifndef NODE_H_
#define NODE_H_

struct Node {
  double value;
  Node *next;
  Node(double);
};

#endif  // NODE_H_