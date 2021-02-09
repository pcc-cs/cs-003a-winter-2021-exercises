/**
 * Class demo.
 *
 * Copyright (c) 2020, Sekhar Ravinutala.
*/

#include <string>
#include <iostream>
#include <random>

#define RAND() (100000 + rand() % 900000)

// Note the syntax
class Student {
 // "Attributes" are basically "member" variables
 // Encapsulation: these "attributes" are not visible outside this class
 private:
  unsigned long studentID;
  std::string firstName;
  std::string lastName;

 public:
  // Special method, called a "constructor"
  Student(std::string fn, std::string ln) : studentID(RAND()), firstName(fn), lastName(ln) {
  }

  // "Accessors" provide public access to private attributes
  unsigned long getStudentID() {
    return studentID;
  }

  // "Mutators" provide public write access, but often with extra logic checks
  void setStudentID(unsigned long sid) {
    // "Sad" path
    if (sid < 100000 || sid > 999999) {
      return;
    }
    // "Happy" path
    studentID = sid;
  }

  // "Methods" are "member" functions
  // Public "methods" provide the interface to the class, specifying operations on the attributes
  // This attributes and operations on them constitutes "informational cohesion"
  std::string name() {
    return lastName + ", " + firstName;
  }

  // This method is "abstracting" out the common logic into one place
  void dump(std::string tag) {
    std::cout << "[" << tag << "] " << studentID << ": " << name() << std::endl;
  }
};

// The caller has no idea how Student is implemented (the concept of "encapsulation")
int main() {
  // "Instantiation" of the class "type"
  Student s1("Johnny", "Sokko");  // As if you called Student("Jonny", "Sokko")

  // This does NOT work because these attributes are private
  // std::cout << s1.studentID << std::endl;
  // s1.studentID = rand();
  // This works because the reading is through an "accessor"
  std::cout << s1.getStudentID() << std::endl;
  s1.setStudentID(0);
  std::cout << s1.getStudentID() << std::endl;
  s1.setStudentID(445321UL);
  std::cout << s1.getStudentID() << std::endl;

  // This accesses the member function (method) of the class instance
  s1.dump("s1");
  
  // Couple of other types of instantiation
  Student s2 = {"Johnny", "Sokko"};
  Student s3 = Student("Johnny", "Sokko");
  s2.dump("s2");
  s3.dump("s3");
}