/*
  CH-230-A
  a10_p5.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include "Critter.h"

using namespace std;

// Private helper methods for hunger conversion
double Critter::convertToDouble(int hungerLevel)
{
    return static_cast<double>(hungerLevel) / 10.0;
}

int Critter::convertToInt(double hungerPercentage) const
{
    return static_cast<int>(hungerPercentage * 10);
}

// Constructors
Critter::Critter() : name("default_critter"), hunger(0.2), boredom(0), height(5.0), age(0), gender("unknown") {}

Critter::Critter(const string& newname) : name(newname), hunger(0.2), boredom(0), height(5.0), age(0), gender("unknown") {}

Critter::Critter(const string& newname, int newhunger, int newboredom, double newheight)
    : name(newname), boredom(newboredom), height(newheight), age(0), gender("unknown")
{
    setHunger(newhunger);
}

// Setter methods
void Critter::setName(const string& newname)
{
    name = newname;
}

void Critter::setHunger(int newhunger)
{
    hunger = convertToDouble(newhunger);
}

void Critter::setBoredom(int newboredom)
{
    boredom = newboredom;
}

void Critter::setAge(int newAge)
{
    age = newAge;
}

void Critter::setGender(const string& newGender)
{
    gender = newGender;
}

// Getter methods
int Critter::getHunger() const
{
    return convertToInt(hunger);
}

int Critter::getAge() const
{
    return age;
}

string Critter::getGender() const
{
    return gender;
}

// Service method
void Critter::print() const
{
    cout << "I am " << name << ". My hunger level is " << getHunger() << "." << endl;
}



