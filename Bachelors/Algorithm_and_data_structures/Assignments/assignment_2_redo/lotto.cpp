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


    //HOW PAIR WORKS
    std::pair<std::set<int>::iterator,bool> result;
    while (count < 49)
    {   
        int number = (std::rand() % 49) + 1;
        result = lottery.insert(number);
           
        if (result.second)
        {
            ++count;
        }
        else
        {
            std::cout << "failed to insert: " << number << std::endl;
        } 
    }
    
    std::set<int>::iterator iterator_lottery;
    for (iterator_lottery = lottery.begin(); iterator_lottery  != lottery.end(); ++iterator_lottery)
    {
        std::cout << *iterator_lottery << " ";
    }

    return 0;
   
}

