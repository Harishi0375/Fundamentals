#include <iostream>

// Function template to find the maximum of two values
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "Maximum of 5 and 8 is: " << max(5, 8) << std::endl;
    std::cout << "Maximum of 3.14 and 2.71 is: " << max(3.14, 2.71) << std::endl;

    return 0;
}

