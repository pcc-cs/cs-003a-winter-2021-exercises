/**
 * Classes.
 *
 Copyright (c) 2020, Sekhar Ravinutala.
*/

#include <cmath>
#include <cstdio>

typedef double Value;

// Note the overloading of the constructors
class Color {
 private:
  double _red, _green, _blue;
  
  // This is a "helper" function, note that it is private
  double _value(double v) {
    if (v < 0) {
      return 0;
    }
    if (v > 1) {
      return 1;
    }
    return v;
  }

 public:
  // Default constructor, MUST be define explicitly if there is another constructor
  Color() : _red(0), _green(0), _blue(0) {
  }

  // Single parameter constructor, requires explicit constructor call
  // ALWAYS use explicit for single parameter constructor
  explicit Color(double v) {
    // The value of an assignment is same as the value being assigned
    _red = _green = _blue = _value(v);
  }

  Color(double r, double g, double b) : _red(_value(r)), _green(_value(g)), _blue(_value(b)) {
  }

  double value() {
    return sqrt((_red * _red + _green * _green + _blue * _blue) / 3.0);
  }

  // Remember to assert all checking logic every time you change the attribute values
  void scale(double factor) {
    _red = _value(_red * factor);
    _green = _value(_green * factor);
    _blue = _value(_blue * factor);
  }
};

int main() {
  // Note how this is instantiated and the "arrow" notation to access value()
  Color *c1p = new Color(0.1, 0.6, 0.3);
  printf("c1p->value() = %lf\n", c1p->value());

  // Note how this is instantiated and the "dot" notation to access value()
  Color c2(1.3, 0.4, 0.1);
  printf("c2.value() = %lf\n", c2.value());

  c2.scale(5.0);
  printf("c2.value() = %lf\n", c2.value());

  // This doesn't work because _red is private
  // printf("c2._red = %lf\n", c2._red);

  // Don't forget this!
  delete c1p;
}