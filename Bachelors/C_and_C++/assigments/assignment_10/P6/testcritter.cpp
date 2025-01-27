/*
  CH-230-A
  a10_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
    Critter c1; // Default constructor
    Critter c2("Critter2"); // Constructor with name parameter
    Critter c3("Critter3", 2, 5,6.3); // Constructor with multiple parameters
    Critter c4("Critter4", 2, 5, 15.0,4.0); // Constructor with multiple parameters, including height

    // Set hunger levels
    c1.setHunger(5);
    c2.setHunger(8);
    c3.setHunger(3);
    c4.setHunger(10);

    cout << "Critter 1:" << endl;
    c1.print();
    cout << endl;

    cout << "Critter 2:" << endl;
    c2.print();
    cout << endl;

    cout << "Critter 3:" << endl;
    c3.print();
    cout << endl;

    cout << "Critter 4:" << endl;
    c4.print();
    cout << endl;

    return 0;
}





