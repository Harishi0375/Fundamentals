#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib> // For srand, rand
#include <ctime>   // For time

const int size = 49;

int main()
{
    std::set<int> lottery;

    // Initialize random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int count = 0;

    while (count < 6) {
        int number = (std::rand() % size) + 1;
        lottery.insert(number);
        ++count;
    }

    // Print the drawn numbers in ascending order
    for (auto it = lottery.begin(); it != lottery.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}