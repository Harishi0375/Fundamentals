#include <iostream>

int main() {
    int mb;
    try {
        std::cout << "How many MB should be reserved? ";
        std::cin >> mb;
        if (mb <= 0)
            throw "Error getting memory!";

        // Allocating and immediately deallocating to use the memory
        char* buffer = new char[256 * 4 * 1024 * mb];
        delete[] buffer;
    } catch (const char* str) {
        std::cout << "Exception: " << str << std::endl;
        return 1;
    }
    std::cout << "Program completed without errors." << std::endl;
    std::cout << mb;
    return 0;
}
