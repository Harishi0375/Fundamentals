#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Example vector
    std::vector<int> numbers = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

    // Example 1: find()
    // auto = vector<int>::iteratior it;
    auto it = std::find(numbers.begin(), numbers.end(), 3);
    if (it != numbers.end()) {
        std::cout << "Element found at index: " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found!" << std::endl;
    }

    // Example 2: count()
    int count = std::count(numbers.begin(), numbers.end(), 2);
    std::cout << "Number of occurrences of 2: " << count << std::endl;

    // Example 3: for_each()
    std::cout << "Elements in the vector: ";
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num << " ";
    });
    std::cout << std::endl;

    // Example 4: equal()
    std::vector<int> otherNumbers = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}; // Same as numbers
    bool isEqual = std::equal(numbers.begin(), numbers.end(), otherNumbers.begin());
    if (isEqual) {
        std::cout << "The two vectors are equal." << std::endl;
    } else {
        std::cout << "The two vectors are not equal." << std::endl;
    }

    return 0;
}


// Using find() to search for an element in a vector.
// Using count() to count occurrences of a specific value in a vector.
// Using for_each() to perform an operation on each element in a vector.
// Using equal() to check if two vectors are equal.




