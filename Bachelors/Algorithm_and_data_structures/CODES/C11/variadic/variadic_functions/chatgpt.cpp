#include <iostream>

// Base case for the recursive variadic template function
void print() {}

// Recursive variadic template function to print multiple arguments
template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " " << std::endl;
    print(args...);
}

int main() {
    print(1, 2.5, "hello");
    print(3.4,3,5,"dad");
    return 0;
}
