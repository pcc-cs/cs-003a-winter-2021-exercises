/**
 * Classes.
 *
 * Copyright (c) 2020, Sekhar Ravinutala.
*/

#include <cstdio>
#include <iostream>

typedef double Value;

// Note the overloading of the constructors
class Color {
 private:
  double _red, _green, _blue;

 public:
  // Initializing attributes outside the body is called "delegation"
  // Default constructor, MUST be define explicitly if there is another constructor
  Color() : _red(0), _green(0), _blue(0) {
    printf("Color()\n");
  }

  // Single parameter constructor, requires explicit constructor call
  // ALWAYS use explicit for single parameter constructor
  explicit Color(double value) : _red(value), _green(value), _blue(value) {
    printf("Color(%.3lf)\n", value);
  }

  Color(double red, double green, double blue) : _red(red), _green(green), _blue(blue) {
    printf("Color(%.3lf, %.3lf, %.3lf)\n", red, green, blue);
  }
};

int main() {
  // "Default" constructor, meaning the constructor takes no args
  Color c1;

  // Single parameter constructor can be invoked with direct assignment
  // If you didn't use "explicit," you could have directly assigned the value
  Color c2a(0.5453);  // This is a Color class
  Value ct1 = 0.5221;  // This is a double type
  Color c2b(0.7456);

  Color c3(0.5221, 0.1321, 0.7667);
}