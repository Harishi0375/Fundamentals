/*
  CH-230-A
  a9_p5.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for time()
using namespace std;

int main()
{
    std::string name;
    int num;

    std::cout << "Enter your name: ";
    std::cin >> name;

    int min = 1;
    int max = 100;
    srand(static_cast<unsigned int>(time(0))); //init random number generator

    int randnum = min + (rand() % (max - min + 1)); //range 1 - 100
    
    int count = 1;
    while (1)
    {
        std::cout << "Pick random number between 1 and 100: ";
        std::cin >> num;
        if (num == randnum)
        {
            break;
        }
        count++;
        if (num > randnum)
        {
            std::cout << "Too high" << std::endl;
        }
        if (num < randnum)
        {
            std::cout << "Too low" << std::endl;
        }    
    }

    std::cout << "Congratulations! " << name << " you took " << count << " attempts" << std::endl;

    return 0;
}
