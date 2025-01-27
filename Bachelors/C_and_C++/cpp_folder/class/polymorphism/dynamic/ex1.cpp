#include <iostream>

// Base class with a virtual function
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl;
    }
};

// Derived classes
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    Shape* shapePtr;

    Circle circle;
    Square square;

    // Runtime polymorphism through virtual functions
    shapePtr = &circle;
    shapePtr->draw();  // Outputs: Drawing a circle

    shapePtr = &square;
    shapePtr->draw();  // Outputs: Drawing a square

    return 0;
}
