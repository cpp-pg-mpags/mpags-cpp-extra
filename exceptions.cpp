#include <exception>
#include <iostream>
#include <memory>

struct A {
  A() {std::cout << "[A::A()]\n";}
  ~A() {std::cout << "[A::~A()]\n";}
};

struct B {
  B() {std::cout << "[B::B()]\n";}
  ~B() {std::cout << "[B::~B()]\n";}
};

struct C {
  C() {std::cout << "[C::C()]\n";}
  ~C() {std::cout << "[C::~C()]\n";}
};


void somethingThatThrows() {
  A foo {};
  B bar {};
  auto baz = std::make_unique<C>();

  std::cout << "About to throw\n";
  throw std::logic_error {"computer says no"};

  std::cout << "I shouldn't exist\n";
}

int main(int, char**) {
  try {
    somethingThatThrows();
  } catch (std::logic_error& e) {
    std::cout << "Handling std::logic_error " << e.what() << "\n";
  }

  return 0;
}


