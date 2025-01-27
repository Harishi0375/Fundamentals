#include <iostream>
#include <vector>
#include <iterator> // for std::distance

int main() {
    // Example container
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Example 1: Input Iterator
    std::cout << "Using Input Iterator (read-only):" << std::endl;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Example 2: Output Iterator
    std::cout << "Using Output Iterator (write-only):" << std::endl;
    std::vector<int> outputVector;
    for (int i = 0; i < 5; ++i) {
        outputVector.push_back(i);
    }
    std::copy(outputVector.begin(), outputVector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Example 3: Forward Iterator
    std::cout << "Using Forward Iterator:" << std::endl;
    std::vector<int>::iterator fwd_it = numbers.begin();
    std::cout << *fwd_it << std::endl;

    // Example 4: Bidirectional Iterator
    std::cout << "Using Bidirectional Iterator:" << std::endl;
    std::vector<int>::iterator bidir_it = numbers.end();
    std::cout << *(--bidir_it) << std::endl;

    // Example 5: Random Access Iterator
    std::cout << "Using Random Access Iterator:" << std::endl;
    std::vector<int>::iterator random_it = numbers.begin() + 2;
    std::cout << *random_it << std::endl;

    return 0;
}


// Input Iterator: Used to read data from a container.
// Output Iterator: Used to write data to a container.
// Forward Iterator: Can be used to read and write data from a container in a forward direction.
// Bidirectional Iterator: Can be used to read and write data from a container in both forward and backward directions.
// Random Access Iterator: Provides the most functionality, allowing for reading, writing, and random access to elements within a container.


