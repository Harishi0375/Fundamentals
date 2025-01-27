#include <iostream>

// Base class
class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog barks" << std::endl;
    }
};

int main() {
    // Creating a Dog object
    Dog myDog;

    // Upcasting: Pointer of type Dog to pointer of type Animal
    Animal* animalPtr = &myDog;

    // Calling the overridden function using the base class pointer
    animalPtr->speak();  // Outputs: Dog barks

    return 0;
}
