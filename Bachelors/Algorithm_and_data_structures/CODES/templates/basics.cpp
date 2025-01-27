#include <iostream>

template <typename T>
void printValue( T value) {
    std::cout << "Value: " << value << std::endl;
}

int main() {
    printValue(42);        // T is int
    printValue(3.14);      // T is double
    printValue("Hello");   // T is const char*
    
    return 0;
}




 