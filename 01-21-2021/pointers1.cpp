/**
 * Exercises on pointers.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <cstdio>

class Complex {
 private:
  double _real;
  double _imaginary;

 public:
  Complex(double r, double i) : _real(r), _imaginary(i) {
  }

  void setReal(double r) {
    _real = r;
  }

  void setImaginary(double i) {
    _imaginary = i;
  }

  void dump() {
    printf("(%.3lf, %.3lf)\n", _real, _imaginary);
  }
};

void getComplex(Complex *cp) {
  printf("Complex number (real,imaginary): ");
  double r, i;
  scanf("%lf,%lf", &r, &i);
  cp->setReal(r);
  cp->setImaginary(i);
}

typedef Complex *ComplexPointer;

int main() {
  int i1 = 100;  // i1 is the name of the variable holding the value 100
  int *i1p = &i1;  // i1p is the name of the pointer variable that holds the address of i1
  printf("i1 = %d, i1p = %p\n", i1, i1p);

  printf("i1 = %d, *i1p = %d\n", i1, *i1p);
  *i1p = 200;
  printf("i1 = %d, *i1p = %d\n", i1, *i1p);

  Complex c1(0.500, 0.707);
  Complex *c1p = &c1;
  ComplexPointer c2p = c1p;  // ComplexPointer is just an alias for Complex *
  c1.dump();  // "Dot" notation
  c1p->dump();  // "Arrow" notation
  c2p->dump();

  // Read by passing pointer (note that this is not by reference)
  // Be sure to use a pointer that points to valid memory region!
  Complex *c3p;
  // getComplex(c3p) - This is invalid because c3p points to an unallocated region
  getComplex(c1p);  // This is OK because c1p points to the location of c1
  c1p->dump();
}