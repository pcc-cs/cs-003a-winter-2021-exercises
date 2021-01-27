/**
 * Node structure.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/
#ifndef NODE_H_
#define NODE_H_

#include <string>

struct Node {
  std::string value;
  Node *next;
  Node(std::string);
};

#endif  // NODE_H_