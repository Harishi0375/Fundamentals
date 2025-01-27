#include <iostream>

class MyClass {
public:
    void displayMessage() {
        std::cout << "Hello from MyClass!" << std::endl;
    }

    void setData(int value) {
        data = value;
    }

    int getData() const {
        return data;
    }

private:
    int data;
};

int main() {
    // Create an object of MyClass
    MyClass obj;

    // Accessing members using the object
    obj.displayMessage();
    obj.setData(42);
    std::cout << "Data from object: " << obj.getData() << std::endl;

    // Create a pointer to MyClass and initialize it with the address of the object
    MyClass *ptr = &obj;

    // Accessing members using the pointer
    ptr->displayMessage();
    ptr->setData(100);
    std::cout << "Data from pointer: " << ptr->getData() << std::endl;

    return 0;
}
