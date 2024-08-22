#include <iostream>

// Base class 1
class Base1 {
public:
    Base1() {
        std::cout << "Base1 constructor" << std::endl;
    }

    void base1Function() {
        std::cout << "Base1 function" << std::endl;
    }
};

// Base class 2
class Base2 {
public:
    Base2() {
        std::cout << "Base2 constructor" << std::endl;
    }

    void base1Function() {
        std::cout << "Base2 function" << std::endl;
    }
};

// Derived class inheriting from Base1 and Base2
class Derived : public Base1, public Base2 {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
    }

    void derivedFunction() {
        std::cout << "Derived function" << std::endl;
    }
};

int main() {
    // Create an object of the derived class
    Derived derivedObject;

    // Access functions from the base classes
    derivedObject.base1Function();
    derivedObject.base2Function();

    // Access functions from the derived class
    derivedObject.derivedFunction();

    return 0;
}
