#include <iostream>

constexpr int value = 10;

static_assert(value == 10, "Value must be equal to 10");

int main() {
    std::cout << "Value is: " << value << std::endl;
    return 0;
}
