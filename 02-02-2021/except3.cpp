/**
 * Custom exception classes.
 *
 * Copyright (c) 2021, Sekhar Ravinutala
 */

#include <string>
#include <iostream>
#include <cmath>

class Error {
 private:
  const char *_msg;

 public:
  Error() {
  }
  explicit Error(const char *msg) : _msg(msg) {
  }
  virtual const char *what() {
    return _msg;
  }
};

class InputError : public Error {
 private:
  std::string _msg;

 public:
  explicit InputError(const char *msg) : _msg(std::string("input: ") + msg) {
  }
  const char *what() {
    return _msg.c_str();
  }
};

// Input a +ve double value
// Throws:
//    InputError exception if -ve
//    int exception if input > 10
void input(double *dp) {
  std::cin >> *dp;
  if (*dp < 0) {
    throw InputError("must be non-negative");
  }
  if (*dp > 10) {
    throw 100;
  }
}

// Round to 2 decimal points
// Throw Error exception if < 0.0 or > 4.0
void round(double *dp) {
  *dp = round(*dp * 100) / 100;
  if (*dp < 0 || *dp > 4) {
    throw Error("invalid range");
  }
}

int main() {
  double gpa;

  try {
    // Can throw InputError exception
    input(&gpa);
    std::cout << "gpa: " << gpa << std::endl;

    // Can throw Error exception
    round(&gpa);
    std::cout << "rounded gpa: " << gpa << std::endl;
  
  // Catch only InputError exceptions
  } catch (InputError err) {
    std::cout << "catch 1: " << err.what() << std::endl;
  
  // Catch BOTH InputError and Error exceptions
  // But since this comes after the above catch block, it only catches Error
  } catch (Error err) {
    std::cout << "catch 2: " << err.what() << std::endl;
  
  // Catch all - try your best not to do this!
  } catch (...) {
    std::cout << "unknown exception" << std::endl;
  }
}