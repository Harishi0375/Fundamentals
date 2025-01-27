/*
  CH-230-A
  a9_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
// using namespace std;

float abs(const float x) //abs function 
{
    if (x < 0)
    {
        return -(x); // - * - becomes +
    }
    return x;
}


int main()
{
    float num;
    std::cout << "Enter a float:";
    std::cin >> num;

    std::cout << "Absolute value: " << abs(num) << std::endl; //print statement

    return 0;

}