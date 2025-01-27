#include <iostream>

// Abstract class (Blueprint)
class Vehicle {
public:
    // Abstract method (unfinished work)
    virtual void startEngine() = 0;

    // Fully written method (shared feature)
    void honkHorn() {
        std::cout << "Honk honk!\n";
    }
};

// Derived class 1 (Car)
class Car : public Vehicle {
public:
    // Complete the abstract method for a car
    void startEngine() override {
        std::cout << "Car engine started!\n";
    }
};

// Derived class 2 (Bicycle)
class Bicycle : public Vehicle {
public:
    // Complete the abstract method for a bicycle
    void startEngine() override {
        std::cout << "Bicycle pedaling started!\n";
    }
};

int main() {
    // You can't create a Vehicle directly (abstract class)
    // Vehicle vehicle;  // Error: cannot declare variable 'vehicle' to be of abstract type 'Vehicle'

    // Create specific vehicles (Car and Bicycle)
    Car myCar;
    Bicycle myBicycle;

    // Use shared features
    myCar.honkHorn();
    myBicycle.honkHorn();

    // Use specific features
    myCar.startEngine();
    myBicycle.startEngine();

    return 0;
}
