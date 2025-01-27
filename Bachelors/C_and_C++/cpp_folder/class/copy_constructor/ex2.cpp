#include <iostream>

class MyClass {
public:
    // Constructor
    MyClass(int val) : data(val) {
        std::cout << "Constructor called with value: " << val << std::endl;
    }

    // Copy constructor
    MyClass(const MyClass& other) : data(other.data) {
        std::cout << "Copy constructor called." << std::endl;
    }

    // Member function to display data
    void displayData() const {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // Create an object using the constructor
    MyClass originalObject(42);

    // Create a new object using the copy constructor
    MyClass copiedObject(originalObject);

    // Display the data of both objects
    std::cout << "Original object:" << std::endl;
    originalObject.displayData();

    std::cout << "\nCopied object:" << std::endl;
    copiedObject.displayData();

    return 0;
}

