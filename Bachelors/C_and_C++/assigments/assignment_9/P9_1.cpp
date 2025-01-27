/*
  CH-230-A
  a9_p1.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string country; //variable declaration

    std::cout << "Enter your country of origin:"; //print statement
    std::cin >> country; //input statement

    std::cout << "Your country of orgin is: ";
    std::cout << country << std::endl;

    return 0;

}