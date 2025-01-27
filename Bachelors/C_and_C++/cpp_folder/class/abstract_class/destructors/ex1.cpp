#include <iostream>

// Base class with a virtual destructor
class Base {
public:
    virtual ~Base(){}

    virtual void someFunction() {
        std::cout << "Base's Function\n";
    }
};

// Derived class
class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Derived Destructor\n";
    }

    void someFunction() override {
        std::cout << "Derived's Function\n";
    }
};

int main() {
    Base* basePtr = new Derived();  // Using a pointer to the base class to point to a derived class object

    basePtr->someFunction();  // Calls the derived class's overridden function

    delete basePtr;  // Calls the derived class's destructor because the base class destructor is virtual

    return 0;
}
