/**
 * Node implementation.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <string>
#include "node.h"

Node::Node(std::string v) : value(v), next(nullptr) {
}