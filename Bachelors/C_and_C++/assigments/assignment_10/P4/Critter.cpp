/*
  CH-230-A
  a10_p4.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include "Critter.h"

using namespace std;

// Constructors
Critter::Critter()
{
    name = "default_critter";
    height = 5.0;
    hunger = boredom = age = 0;
    cout << "A default critter has been created." << endl;
}

Critter::Critter(const std::string &newname)
{
    name = newname;
    height = 5.0;
    hunger = boredom = age = 0;
    cout << "A critter named " << name << " has been created." << endl;
}

Critter::Critter(const std::string &newname, int newhunger, int newboredom, double newheight)
{
    name = newname;
    hunger = newhunger;
    boredom = newboredom;
    height = newheight;
    age = 0;
    cout << "A critter named " << name << " with custom parameters has been created." << endl;
}

// Setter methods
void Critter::setName(const std::string &newname)
{
    name = newname;
}

void Critter::setHunger(int newhunger)
{
    hunger = newhunger;
}

void Critter::setBoredom(int newboredom)
{
    boredom = newboredom;
}

void Critter::setAge(int newAge)
{
    age = newAge;
}

void Critter::setGender(const std::string &newGender)
{
    gender = newGender;
}

// Getter methods
int Critter::getHunger() const
{
    return hunger;
}

int Critter::getAge() const
{
    return age;
}

std::string Critter::getGender() const
{
    return gender;
}

// Service method
void Critter::print() const
{
    cout << "I am " << name << ". My hunger level is " << hunger << "." << endl;
}
