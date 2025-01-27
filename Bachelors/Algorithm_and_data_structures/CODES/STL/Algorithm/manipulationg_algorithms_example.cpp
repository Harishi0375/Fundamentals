#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Example vector
    std::vector<int> numbers = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

    // Example 1: copy()
    std::vector<int> copiedNumbers(numbers.size());
    std::copy(numbers.begin(), numbers.end(), copiedNumbers.begin());
    std::cout << "Copied vector: ";
    for (int num : copiedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 2: swap()
    std::vector<int> numbers2 = {10, 20, 30, 40, 50};
    std::cout << "Before swapping:\n";
    std::cout << "numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\nnumbers2: ";
    for (int num : numbers2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::swap(numbers, numbers2);

    std::cout << "After swapping:\n";
    std::cout << "numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\nnumbers2: ";
    for (int num : numbers2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 3: replace()
    std::replace(numbers.begin(), numbers.end(), 5, 55); // Replace all occurrences of 5 with 55
    std::cout << "After replacing 5 with 55: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 4: remove()
    numbers.erase(std::remove(numbers.begin(), numbers.end(), 2), numbers.end()); // Remove all occurrences of 2
    std::cout << "After removing 2: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


// Using copy() to copy elements from one vector to another.
// Using swap() to swap the contents of two vectors.
// Using replace() to replace all occurrences of a specific value with another value in a vector.
// Using remove() to remove all occurrences of a specific value from a vector.