#include <iostream>

class MathOperations {
public:
    // Function overloading for different parameter types
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    MathOperations math;

    // Compile-time polymorphism based on function overloading
    int result1 = math.add(5, 3);
    double result2 = math.add(2.5, 3.7);

    std::cout << "Result 1: " << result1 << std::endl;  // Outputs: Result 1: 8
    std::cout << "Result 2: " << result2 << std::endl;  // Outputs: Result 2: 6.2

    return 0;
}
