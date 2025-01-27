#include <iostream>

int main() {
    // Define and call a lambda function
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << std::endl;

    return 0;
}
