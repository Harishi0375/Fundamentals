/*
  CH-230-A
  a9_p2.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //variable declaration
    int n;
    double x;
    std::string s;

    std::cout << "Enter an integer: ";
    std::cin >> n;

    std::cout << "Enter a double: ";
    std::cin >> x;

    std::cout << "Enter a string: ";
    std::cin >> s;

    for (int i = 0; i < n; i++)
    {
        std::cout << s << ":" << x << std::endl; //printing s:x
    }
    
    return 0;
}
