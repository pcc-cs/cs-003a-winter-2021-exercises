/**
 * Show type of inheritance.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>

class A {
 private:
  int aPrivate = 10;

 protected:
  int aProteced = 20;

 public:
  int aPublic = 30;
};

// Can access A::aProtected, A::Public
class APublic : public A {
};

// Can access A::aProtected, A::Public
class AProtected : protected A {
};

// The "private" keyword is optional (defaults to private)
// Can access A::aProtected, A::Public
class APrivate : private A {
 public:
  void dump() {
    printf("aProtected = %d, aPublic = %d\n", aProteced, aPublic);
  }
};

// Nothing is visible because APrivate downgraded aProtected and aPublic
class APrivatePublic : public A {
};

// Can access: A::aPublic, APublic::aPublic
int main() {
  A a;
  printf("%d\n", a.aPublic);

  APublic aPublic;
  printf("%d\n", aPublic.aPublic);

  // Nothing is visible
  AProtected aProtected;

  // Nothing is visible
  APrivate aPrivate;
  aPrivate.dump();
}