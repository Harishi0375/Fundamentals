#include <iostream>

class Calculator {
public:
    // Function to add two integers
    int add(int a, int b) {
        std::cout << "Calling int add(int, int)" << std::endl;
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c) {
        std::cout << "Calling int add(int, int, int)" << std::endl;
        return a + b + c;
    }

    // Function to add two double numbers
    double add(double a, double b) {
        std::cout << "Calling double add(double, double)" << std::endl;
        return a + b;
    }
};

int main() {
    // Create an instance of the Calculator class
    Calculator myCalculator;

    // Call the different overloaded functions using the class instance
    int result1 = myCalculator.add(3, 5);
    int result2 = myCalculator.add(2, 4, 6);
    double result3 = myCalculator.add(2.5, 3.7);

    // Display the results
    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;
    std::cout << "Result 3: " << result3 << std::endl;

    return 0;
}
