//
// Created by Nikolay Tsonev on 14/02/2024.
//

#include <iostream>
#include <fstream>
#include <list>

// helper function to merge the 2
bool comparator(int first, int second) {
    return first < second;
}

int main() {

    std::list<int> A, B;

    int input;

    do {
        std::cout << "Please Enter num: ";
        std::cin >> input;
        if (input > 0) {
            A.push_back(input);
            B.push_front(input);
        }

    } while (input > 0);

    std::list<int>::iterator itorA;
    for (itorA = A.begin(); itorA != A.end(); itorA++) {
        std::cout << *itorA << " ";
    }

    std::cout << std::endl;

    std::list<int>::iterator itorB;
    std::ofstream output;
    output.open("listB.txt");
    for (itorB = B.begin(); itorB != B.end(); itorB++) {
        output << *itorB << " ";
    }
    output.close();

   // append the first element and then pop the first element
    A.push_back(A.front());
    A.pop_front();

    B.push_back(B.front());
    B.pop_front();

    std::cout << "Printing List A: ";
    for (itorA = A.begin(); itorA != A.end(); itorA++) {
        // check if it is the last element

        if (itorA != --A.end())
            std::cout << *itorA << ",";
        else
            std::cout << *itorA << "\n";
    }

    std::cout << "Printing List B: ";
    for (itorB = B.begin(); itorB != B.end(); itorB++) {
        // check if it is the last element

        if (itorB != --B.end())
            std::cout << *itorB << ",";
        else
            std::cout << *itorB << "\n";
    }

    std::cout << std::endl;

    // Merge list B into List A
    A.merge(B, comparator);

    // sort the list
    A.sort();

    std::cout << "Printing List A: ";
    for (itorA = A.begin(); itorA != A.end(); itorA++) {
        // check if it is the last element

        if (itorA != --A.end())
            std::cout << *itorA << " ";
        else
            std::cout << *itorA << "\n";
    }


    return 0;
}

