#include <iostream>
#include <stdexcept>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }

    int divide(int a, int b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return a / b;
    }
};

int main() {
    Calculator calculator;

    try {
        // Attempt to perform division by zero
        int result_divide = calculator.divide(10, 0);
        std::cout << "Division Result: " << result_divide << std::endl; // This won't be reached

        int result_add = calculator.add(10, 5);
        std::cout << "Addition Result: " << result_add << std::endl;

        int result_subtract = calculator.subtract(10, 5);
        std::cout << "Subtraction Result: " << result_subtract << std::endl;

        int result_multiply = calculator.multiply(10, 5);
        std::cout << "Multiplication Result: " << result_multiply << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
