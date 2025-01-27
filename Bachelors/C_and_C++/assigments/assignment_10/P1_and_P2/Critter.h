/*
  CH-230-A
  a10_p1.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;
	int age;
	std::string gender;

public: // business logic methods are public
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	void setAge(int newAge);
	void setGender(std::string& newGender);
	// getter method
	int getHunger();
	int getAge();
	std::string getGender();
	// service method
	void print();
};