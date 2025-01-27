#include <iostream>
#include <vector>

int main() {
    // Declare a vector of integers
    std::vector<int> myVector;

    // Insert elements into the vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Access elements
    std::cout << "First element: " << myVector[0] << std::endl;
    std::cout << "Second element: " << myVector.at(1) << std::endl;

    // Modify elements
    myVector[1] = 25;
    std::cout << "Modified second element: " << myVector[1] << std::endl;

    // Print all elements in the vector
    std::cout << "Elements in the vector: ";
    for (int elem : myVector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Check if vector is empty
    if (myVector.empty()) {
        std::cout << "Vector is empty" << std::endl;
    } else {
        std::cout << "Vector is not empty" << std::endl;
    }

    // Get the size of the vector
    std::cout << "Size of the vector: " << myVector.size() << std::endl;

    // Clear the vector
    myVector.clear();

    // Check if vector is empty after clearing
    if (myVector.empty()) {
        std::cout << "Vector is empty after clearing" << std::endl;
    } else {
        std::cout << "Vector is not empty after clearing" << std::endl;
    }

    return 0;
}
