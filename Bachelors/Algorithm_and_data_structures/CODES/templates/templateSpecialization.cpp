#include <iostream>

// Template specialization for a specific type
template <typename T>
void print(T value) {
    std::cout << "Generic template: " << value << std::endl;
}

// Template specialization for char type
template <>
void print<char>(char value) {
    std::cout << "Specialized template for char: '" << value << "'" << std::endl;
}

int main() {
    print(42);      // Uses generic template
    print('A');     // Uses specialized template for char

    return 0;
}
