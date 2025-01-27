#include <iostream>
#include <deque>
int main() {

    std::deque<float> A;

    float input;

    // Take in user input and push front negatives
    // push back positives
    do {

        std::cout << "Give me your float: ";
        std::cin >> input;

        if (input > 0)
            A.push_back(input);
        else if (input < 0)
            A.push_front(input);

    } while (input != 0);

    // print
    std::deque<float>::iterator itor;
    for (itor = A.begin(); itor != A.end(); itor++) {
        std::cout << *itor << " ";
    }

    std::cout << std::endl;

    // itor to first positive value and insert 0 right beforehand
    for (itor = A.begin(); itor != A.end(); itor++) {
        if ( *itor > 0) {
            A.insert(itor, 0)          ;
            break;
        }
    }
     // print list again
     for (itor = A.begin(); itor != A.end(); itor++) {           
         if (itor != --A.end())
            std::cout << *itor << ";";
         else
             std::cout << *itor << "\n";
     }

     return 0;
}