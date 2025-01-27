#include <iostream>

// Base case for the recursive variadic template function
int sum() {
    return 0; // Base case: no arguments, return 0
}

// Recursive variadic template function to calculate the sum of multiple arguments
template<typename T, typename... Args>
T sum(T first, Args... rest) {
    return first + sum(rest...); // Recursively sum the rest of the arguments
}

int main() {
    std::cout << "Sum: " << sum(1, 2, 3, 4, 5) << std::endl;
    return 0;
}
