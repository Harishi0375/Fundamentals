/*
  CH-230-A
  a13_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <stdexcept>

int main() 
{
    std::vector<int> myVector;
    for (int i = 0; i < 20; ++i) {
        myVector.push_back(8);
    }

    try {
        //using at() to access 21st element 
        int value = myVector.at(20);

        // This line won't be reached if an exception occurs
        std::cout << "Value at index 20: " << value << std::endl;
    } catch (const std::out_of_range& ex) {
        // Catch the out_of_range exception
        std::cerr << "Caught an exception: " << ex.what() << std::endl;
    }

    return 0;
}
