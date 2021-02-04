/**
 * Templated stack.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/
#ifndef STACK_H_
#define STACK_H_

#include <limits>
#include "node.h"

template <class T>
class Stack {
 private:
  Node<T> *_top = nullptr;
  int _size = 0;

 public:
  ~Stack();
  bool empty() const;
  int size() const;
  T top() const;
  void push(T);
  T pop();
};

template <class T>
Stack<T>::~Stack() {
  for (Node<T> *np = _top; np != nullptr;) {
    Node<T> *p = np;
    np = np->next;
    delete p;
  }
}

template <class T>
bool Stack<T>::empty() const {
  return _top == nullptr;
}

template <class T>
int Stack<T>::size() const {
  return _size;
}

// Return next value without popping
// Throws const char * exception if empty
template <class T>
T Stack<T>::top() const {
  // Need to change to exception because we don't know the type of
  // value to return when stack is empty
  if (_top == nullptr) {
    throw "stack is empty";
  }
  return _top->value;
}

template <class T>
void Stack<T>::push(T v) {
  Node<T> *np = new Node<T>(v);
  _size++;
  if (_top == nullptr) {
    _top = np;
    return;
  }
  np->next = _top;
  _top = np;
}

// Pop the next value
// Throws const char * exception if empty
template <class T>
T Stack<T>::pop()  {
  if (_top == nullptr) {
    throw "stack is empty";
  }
  --_size;
  Node<T> *np = _top;
  _top = _top->next;
  T v = np->value;
  delete np;
  return v;
}

#endif  // STACK_H_