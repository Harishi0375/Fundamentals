#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    // Example vector for sorting algorithms
    std::vector<int> numbers = {5, 2, 9, 3, 7, 1, 8, 4, 6};

    // Example 1: sort()
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 2: min()
    int smallest = *std::min_element(numbers.begin(), numbers.end());
    std::cout << "Smallest number: " << smallest << std::endl;

    // Example 3: set_union()
    std::vector<int> numbers2 = {3, 5, 7, 9, 11};
    std::vector<int> unionVec(numbers.size() + numbers2.size());
    auto it = std::set_union(numbers.begin(), numbers.end(), numbers2.begin(), numbers2.end(), unionVec.begin());
    unionVec.resize(it - unionVec.begin());
    std::cout << "Union of numbers and numbers2: ";
    for (int num : unionVec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example numerical algorithm: accumulate()
    std::vector<int> numbers3 = {1, 2, 3, 4, 5};
    int sum = std::accumulate(numbers3.begin(), numbers3.end(), 0);
    std::cout << "Sum of numbers: " << sum << std::endl;

    return 0;
}

// sing sort() to sort elements in a vector.
// Using min() to find the smallest element in a vector.
// Using set_union() to compute the union of two sorted ranges.
// Using accumulate() to compute the sum of elements in a vector.