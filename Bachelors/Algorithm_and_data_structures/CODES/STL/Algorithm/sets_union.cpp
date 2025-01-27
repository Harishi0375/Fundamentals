#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Example sets for set operations
    std::vector<int> set1 = {1, 2, 3, 4, 5};
    std::vector<int> set2 = {3, 4, 5, 6, 7};

    // Example 1: set_union()
    std::vector<int> unionSet(set1.size() + set2.size());
    auto unionIt = std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), unionSet.begin());
    unionSet.resize(unionIt - unionSet.begin());
    std::cout << "Union of set1 and set2: ";
    for (int num : unionSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 2: set_intersection()
    std::vector<int> intersectionSet(std::min(set1.size(), set2.size()));
    auto intersectionIt = std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), intersectionSet.begin());
    intersectionSet.resize(intersectionIt - intersectionSet.begin());
    std::cout << "Intersection of set1 and set2: ";
    for (int num : intersectionSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 3: set_difference()
    std::vector<int> differenceSet(set1.size());
    auto differenceIt = std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), differenceSet.begin());
    differenceSet.resize(differenceIt - differenceSet.begin());
    std::cout << "Difference of set1 and set2: ";
    for (int num : differenceSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 4: set_symmetric_difference()
    std::vector<int> symmetricDifferenceSet(set1.size() + set2.size());
    auto symmetricDifferenceIt = std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), symmetricDifferenceSet.begin());
    symmetricDifferenceSet.resize(symmetricDifferenceIt - symmetricDifferenceSet.begin());
    std::cout << "Symmetric difference of set1 and set2: ";
    for (int num : symmetricDifferenceSet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}



// Using set_union() to compute the union of two sets.
// Using set_intersection() to compute the intersection of two sets.
// Using set_difference() to compute the difference of two sets.
// Using set_symmetric_difference() to compute the symmetric difference of two sets.