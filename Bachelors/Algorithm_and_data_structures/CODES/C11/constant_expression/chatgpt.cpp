#include <iostream>

constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int value = 5;
    constexpr int result = square(value); // result is a constant expression

    std::cout << "Square of " << value << " is " << result << std::endl;

    return 0;
}
