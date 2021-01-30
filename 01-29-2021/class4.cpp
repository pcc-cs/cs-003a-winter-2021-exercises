/**
 * Destructors with inheritance, virtual destructors.
 *
 * Copyright (c) 2021, Sekhar Ravinutala.
*/

#include <string>
#include <iostream>

#define BUF_SIZE 0x1000

class Student {
 private:
  int _n = 0;
  int _cap;
  std::string *_classes;

 public:
  Student(int nc) {
    _cap = nc;
    _classes = new std::string[nc];
  }
  // By making this virtual, the destructor of derived class also gets called
  virtual ~Student() {
    std::cout << "~Student()" << std::endl;
    delete [] _classes;
  }
  void add(std::string c) {
    if (_n < _cap) {
      _classes[_n++] = c;
    }
  }
  std::string classes() {
    std::string classes;
    for (int i = 0; i < _n; i++) {
      if (i > 0) {
        classes += ", ";
      }
      classes += _classes[i];
    }
    return classes;
  }
};

class CSStudent : public Student {
 private:
  char *_buf;

 public:
  CSStudent(int nc) : Student(nc), _buf(new char[BUF_SIZE]) {
  }
  ~CSStudent() {
    std::cout << "~CSStudent" << std::endl;
    delete [] _buf;
  }
};

class Section {
 private:
  int _n = 0;
  int _cap;
  Student **_students;

 public:
  Section(int ns) {
    _cap = ns;
    _students = new Student *[ns];
  }
  ~Section() {
    std::cout << "~Section()" << std::endl;
    delete [] _students;
  }
  void add(Student *sp) {
    if (_n < _cap) {
      _students[_n++] = sp;
    }
  }
  void dump() {
    for (int i = 0; i < _n; i++) {
      std::cout << (i+1) << ": " << _students[i]->classes() << std::endl;
    }
  }
};

int main() {
  Student *s1p = new CSStudent(6);
  Section c1(60);
  s1p->add("CS3A"), s1p->add("MUSC2B");
  c1.add(s1p);
  c1.dump();
  
  // Explicitly delete s1p
  delete s1p;
}