#include <iostream>
#include <set>

int main() {
    // Declare a multiset of integers
    std::multiset<int> myMultiset;

    // Insert elements into the multiset
    myMultiset.insert(10);
    myMultiset.insert(20);
    myMultiset.insert(10); // Duplicate element
    myMultiset.insert(30);
    myMultiset.insert(20); // Duplicate element

    // Iterate over the elements in the multiset
    std::cout << "Elements in the multiset: ";
    for (int elem : myMultiset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Count the occurrences of a specific element
    int count = myMultiset.count(10);
    std::cout << "Number of occurrences of 10: " << count << std::endl;

    // Erase specific elements from the multiset
    myMultiset.erase(20);

    // Check if a value exists in the multiset
    int valueToFind = 30;
    auto it = myMultiset.find(valueToFind);
    if (it != myMultiset.end()) {
        std::cout << valueToFind << " found in the multiset" << std::endl;
    } else {
        std::cout << valueToFind << " not found in the multiset" << std::endl;
    }

    return 0;
}
