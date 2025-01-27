//
// Created by Nikolay Tsonev on 14/02/2024.
//

#include <iostream>
#include <set>

int main( ) {

    std::set<float> lott;

    // set prevents from, duplicates to be inserted
    for (int i = 0; i < 5; i++)
        lott.insert(rand() % 49 + 1);

    // create itor and print the lotto nummies
    std::set<float>::iterator sitor;
    for (sitor = lott.begin(); sitor != lott.end(); sitor++)
        std::cout << *sitor << " ";

    std::cout << std::endl;

    return 0;
}