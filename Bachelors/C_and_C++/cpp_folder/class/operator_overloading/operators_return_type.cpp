#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass() : value(0) {}

    // Arithmetic Operators (+, -, *, /, etc.):
    MyClass operator+(const MyClass& other) const {
        MyClass result;
        result.value = this->value + other.value;
        return result;
    }

    // Comparison Operators (==, !=, <, >, etc.):
    bool operator==(const MyClass& other) const {
        return this->value == other.value;
    }

    // Assignment Operator (=):
    MyClass& operator=(const MyClass& other) {
        this->value = other.value;
        return *this;
    }

    // Unary Operators (++, --, +, -, etc.):
    MyClass& operator++() {
        ++this->value;
        return *this;
    }

    // Display function
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass result;

    // Testing operators
    result = obj1 + obj2;
    result.display();  // Should print "Value: 0"

    if (obj1 == obj2) {
        std::cout << "Objects are equal." << std::endl;
    } else {
        std::cout << "Objects are not equal." << std::endl;
    }

    ++obj1;
    obj1.display();  // Should print "Value: 1"

    return 0;
}
