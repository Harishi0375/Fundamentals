/*
  CH-230-A
  a10_p4.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char **argv)
{
  Critter c1; // Default constructor
  c1.print();

  Critter c2(string("Critter2")); // Constructor with name parameter
  c2.setHunger(2);
  c2.print();

  Critter c3(string("Critter3"), 2, 5); // Constructor with multiple parameters
  c3.print();

  Critter c4(string("Critter4"), 2, 5, 15.0); // Constructor with multiple parameters, including height
  c4.print();

  return 0;
}
