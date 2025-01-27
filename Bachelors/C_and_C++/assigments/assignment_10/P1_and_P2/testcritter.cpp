/*
  CH-230-A
  a10_p1.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c;

	string name;
	int hunger;
	int age;
	string gender;
 
	cout << endl << "Please enter data: " << endl;
	cout << "Name: ";
	// cin >> name; will not work if name contains
	// spaces
	getline(cin, name);
	c.setName(name);
	cout << "Hunger: ";
	cin >> hunger;
	c.setHunger(hunger);
	c.setAge(age);
	cout << "Age: ";
	cin >> age;
	cout << "enter gender: ";
	getline(cin, gender);
	c.setGender(gender);
	cin >> gender;

	cout << "You have created:" << endl;
	c.print();
        return 0;
}