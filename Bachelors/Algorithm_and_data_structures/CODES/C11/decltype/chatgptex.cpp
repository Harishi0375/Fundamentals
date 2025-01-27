#include <iostream>

int main() {
    int x = 5;
    decltype(x) y = 10; // y will have the same type as x, which is int
    std::cout << "y = " << y << std::endl;

    const int& ref = x;
    decltype(ref) z = y; // z will have the same type as ref, which is const int&
    std::cout << "z = " << z << std::endl;

    return 0;
}
