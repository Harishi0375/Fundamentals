/*
  CH-230-A
  a9_p4.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <string>
using namespace std;

class foverloading 
{
public:
    signed int mycount(int a, int b) //subtracting function
    {
        return (b - a);
    }

    int mycount(char a, const char* b) //number of occurence
    {
        int count = 0;
        for (int i = 0; b[i] != '\0'; ++i)
        {
            if (b[i] == a)
            {
                ++count;
            }
        }
        return count;
    }
};

int main()
{
    foverloading example; //creating class: example

    std::cout << example.mycount(7, 3) << std::endl;
    std::cout << example.mycount('i', "this is a string") << std::endl;

    return 0;
}
