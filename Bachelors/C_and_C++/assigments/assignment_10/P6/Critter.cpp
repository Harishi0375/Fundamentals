/*
  CH-230-A
  a10_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include "Critter.h"
#include <iostream>

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
Critter::Critter() : name("default_critter"), hunger(0.2), boredom(0), height(5.0), age(0), gender("unknown"), thirst(0.2) {}

Critter::Critter(const std::string& newname) : name(newname), hunger(0.2), boredom(0), height(5.0), age(0), gender("unknown"), thirst(0.2) {}

Critter::Critter(const std::string& newname, int newhunger, int newboredom, double newheight)
    : name(newname), boredom(newboredom), height(newheight), age(0), gender("unknown"), thirst(convertToDouble(newhunger)) {}

Critter::Critter(const std::string& newname, int newhunger, int newboredom, double newheight, double newthirst)
    : name(newname), boredom(newboredom), height(newheight), age(0), gender("unknown"), thirst(newthirst)
{
    setHunger(newhunger);
}

// Setter methods
void Critter::setName(const std::string& newname)
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

void Critter::setGender(const std::string& newGender)
{
    gender = newGender;
}

void Critter::setThirst(double newThirst)
{
    thirst = newThirst;
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

std::string Critter::getGender() const
{
    return gender;
}

double Critter::getThirst() const
{
    return thirst;
}

// Service method
void Critter::print() const
{
    std::cout << "I am " << name << ". My hunger level is " << getHunger() << ". My thirst level is " << thirst << "." << std::endl;
}





